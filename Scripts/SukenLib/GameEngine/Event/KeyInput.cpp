#include"KeyInput.h"
#include"../Game.h"
#include"../Physics/Vector2D.h"
#include"../../Utility/Debug.h"

suken::CKeyInputUnit::CKeyInputUnit()
{
	IsActive = false;
	//BeginInputでキー入力が始まったことを通知する用の関数ポインタ

}
void suken::CKeyInputUnit::Init(int x,int y,int _serialNum,int *_pCurrentInputSerial ,int maxLength , char temp,int *_intLink = nullptr)
{
	IsActive = false;
	strColor = GetColor(255,255,255);
	intData = 0;
	intLink = _intLink;
	strLink = nullptr;
	
	serialNumber = _serialNum;
	pCurrentInputSerial = _pCurrentInputSerial;
	BeginInput(x,y,maxLength);

}
void suken::CKeyInputUnit::Init(int x,int y,int _serialNum,int *_pCurrentInputSerial ,int maxLength , int temp , std::string *_strLink = nullptr )
{
	IsActive = false;
	strColor = GetColor(255,255,255);
	intData = 0;
	intLink = nullptr;
	strLink = _strLink;
	
	serialNumber = _serialNum;
	pCurrentInputSerial = _pCurrentInputSerial;
	BeginInput(x,y,maxLength);
	
}
void suken::CKeyInputUnit::BeginInput(int x,int y,int maxLength,bool cancelFlag)
{

	IsActive = true; 
	*pCurrentInputSerial = this->serialNumber;
	pos = suken::VGet(x,y);

	switch(serialNumber%10000)
	{
	case NONE:
		break;
	case NUMBER:
		keyInputHandle = MakeKeyInput( maxLength , cancelFlag ,FALSE , TRUE ) ;
		break;
	case ENGLISH:
		keyInputHandle = MakeKeyInput( maxLength , cancelFlag ,TRUE , FALSE) ;
		break;
	case JAPANESE:
		keyInputHandle = MakeKeyInput( maxLength*2 , cancelFlag ,FALSE , FALSE ) ;
		break;
	default:

		break;
	}
	//エラー
	if( keyInputHandle == -1 )
	{
		IsActive = false;
		WarningSK("CKeyInputModule::BeginInput()において新規キー入力データの作成に失敗しました");
	}else
	{
		SetActiveKeyInput( keyInputHandle ) ;	
	}


}
void suken::CKeyInputUnit::Loop()
{

	if( IsActive && *pCurrentInputSerial != serialNumber )
	{
		IsActive = false;
	}
	if( IsActive )
	{
		//DrawKeyInputString( pos.x , pos.y , keyInputHandle ) ;
		switch(serialNumber%10000)
		{
		case NONE:
			break;
		case NUMBER:
			intData = GetKeyInputNumber( keyInputHandle );
			char temp0[MAX_KEY_INPUT];
			GetKeyInputString( temp0 , keyInputHandle ) ;
			strData = temp0;
			break;
		case ENGLISH:
			char temp1[MAX_KEY_INPUT];
			GetKeyInputString( temp1 , keyInputHandle ) ;
			strData = temp1;
			break;
		case JAPANESE:
			char temp2[MAX_KEY_INPUT*2];
			GetKeyInputString( temp2 , keyInputHandle ) ;
			strData = temp2;
			break;
		default:
			break;
		}

		if( intLink != nullptr )
		{
			*intLink = intData;
		}
		if( strLink != nullptr )
		{
			*strLink = strData;
		}
		//入力が終了しているなら非アクティブ化
		if( CheckKeyInput( keyInputHandle ) != 0 )
		{
			//DeleteKeyInput( keyInputHandle ) ;
			IsActive = false;
			pCurrentInputSerial = NULL;

		}
	}
	//Draw
	if(0)
	{
		DrawFormatString(pos.x,pos.y,strColor,"%s",strData.c_str());
	}else
	{
		SetKeyInputStringColor( strColor , WHITE ,
			BLACK , WHITE ,
			YELLOW , WHITE ,
			WHITE , WHITE ,
			WHITE , WHITE ,
			WHITE , WHITE ,
			WHITE , BLACK ,
			BLACK , strColor ,
			strColor );
		DrawKeyInputString( pos.x , pos.y , keyInputHandle ) ;
	}
}
int suken::CKeyInputUnit::GetSerialNum(){
	return serialNumber;
}
void suken::CKeyInputUnit::SetColor(int color){
	strColor = color;
}


//////////////////////////////////////////////////
//////////////////////////////////////////////////

suken::CKeyInputModule::CKeyInputModule()
{

}
void suken::CKeyInputModule::Init(KEY_INPUT_TYPE _type,int *_pSerial,int *_pCurrentInputSerial)
{
	type = _type;
	pSerial = _pSerial;
	pCurrentInputSerial = _pCurrentInputSerial;
}

int suken::CKeyInputModule::MakeInput(int x,int y,int maxLength,void *_link)
{
	int serialNum = 0;
	serialNum += (int)type*10000;
	serialNum += *pSerial;
	if( type == NUMBER )
	{
		CKeyInputUnit temp;
		temp.Init(x,y,serialNum,pCurrentInputSerial,maxLength,1,(int*)_link);
		temp.SetColor(WHITE);
		push_back(temp);
		*pSerial++;
		return temp.GetSerialNum();
	}else if( type != NONE )
	{
		CKeyInputUnit temp;
		temp.Init(x,y,serialNum,pCurrentInputSerial,maxLength,'c',(std::string*)_link);
		push_back(temp);
		*pSerial++;
		return temp.GetSerialNum();
	}
	return -1;

}

bool suken::CKeyInputModule::End(int serialNum){
	for(int i=0;i<size();i++){
		if( at(i).GetSerialNum() == serialNum ){
			this->erase(this->begin()+i);
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

suken::CKeyInput::CKeyInput()
{
	currentInputSerial = NULL;
	for(int i=0;i<KEY_INPUT_TYPE_NUM;i++)
	{
		serial[i] = 0;
	}
	CKeyInputModule tempNUMBER;
	tempNUMBER.Init(NUMBER,&serial[NUMBER],&currentInputSerial);
	number = tempNUMBER;

	CKeyInputModule tempENGLISH;
	tempENGLISH.Init(ENGLISH,&serial[ENGLISH],&currentInputSerial);
	english = tempENGLISH;

	CKeyInputModule tempJAPANESE;
	tempJAPANESE.Init(JAPANESE,&serial[JAPANESE],&currentInputSerial);
	japanese = tempJAPANESE;
}


void suken::CKeyInput::Loop()
{
	for(int i=0;i<number.size();i++)
	{
		number[i].Loop();
	}
	for(int i=0;i<english.size();i++)
	{
		english[i].Loop();
	}
	for(int i=0;i<japanese.size();i++)
	{
		japanese[i].Loop();
	}
}

void suken::CKeyInput::End(){
	
		switch(currentInputSerial%10000)
		{
		case NONE:
			break;
		case NUMBER:
			number.End(currentInputSerial);
			break;
		case ENGLISH:
			english.End(currentInputSerial);
			break;
		case JAPANESE:
			japanese.End(currentInputSerial);
			break;
		default:
			break;
		}
		currentInputSerial = NULL;
	
}

void InputSceneLoop()
{
	Game.GetFrontScene()->input.keyInput.Loop();
}