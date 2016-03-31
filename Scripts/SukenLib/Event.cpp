#include"Event.h"


void CKey::Loop(){
	 //全てのキーの押下状態を取得
	char buf[256];
	GetHitKeyStateAll( buf ) ;
	for(int i=0;i<256;i++){
		if( buf[i] == 0 ){
			count[i] += 1.0f;
		}else if( buf[i] == 1 ){
			if(count[i] < 1.0f){
				count[i] = 0.5f;
			}else{
				count[i] = 0.0f;
			}
		}
	}
}
bool CKey::GetPush(int keyCode){
	 //キーコードチェック
		if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] < 1.0f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetPushの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return false;
	 }
 }
 bool CKey::GetDown(int keyCode){
	 //キーコードチェック
	 if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 0.0f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	 }else{
		WarningSK("CKey::GetDownの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return false;
	 }
}
 bool CKey::GetUp(int keyCode){
	//キーコードチェック
	if( keyCode < 256 && keyCode >= 0 ){
		if( count[keyCode] == 1.5f ){
			if(Event.GetValid()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;			
		}
	}else{
		WarningSK("CKey::GetUpの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return false;
	}
}
int CKey::GetCount(int keyCode){
	//キーコードチェック
		if( keyCode < 256 && keyCode >= 0 ){
		return (int)(count[keyCode]);
	}else{
		WarningSK("CKey::GetCountの引数に不正なキーコードが入力されました\nキーコード　：　%d",keyCode);
		return -1;
	}
}

CMouseIn CMouse::Off( int _x1 , int _y1 , int _x2 , int _y2 ){

	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool CMouse::GetOff( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1>mouseX && _x2<mouseX ){
		if(_y1>mouseY && _y2<mouseY){
			return true;
		}
	}
	return false;
}
CpMouseIn CMouse::Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){

	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool CMouse::GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1>mouseX && *_x2<mouseX ){
		if(*_y1>mouseY && *_y2<mouseY){
			return true;
		}
	}
	return false;
}
CMouseIn CMouse::On( int _x1 , int _y1 , int _x2 , int _y2 ){
	
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool CMouse::GetOn( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
CpMouseIn CMouse::On( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool CMouse::GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
CMouseIn CMouse::Click( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool CMouse::GetClick( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;		
				}
			} 
		}
	}
	return false;
}
CpMouseIn CMouse::Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool CMouse::GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;	
				}
			} 
		}
	}
	return false;
}
CMouseIn CMouse::Release( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool CMouse::GetRelease( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
CpMouseIn CMouse::Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool CMouse::GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
void CMouse::Loop(){
	GetMousePoint( &mouseX, &mouseY );
	preMouseInput = mouseInput;
	if(IsLeft){
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_LEFT );
	}else{
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_RIGHT );
	}
}
void CMouse::SetLeft(){
	IsLeft = true;
}
void CMouse::SetRight(){
	IsLeft = false;
}

CEvent::CEvent(){
	EVERY_FRAME=FRAME_EVENT;
	LMouse.SetLeft();
	RMouse.SetRight();
	IsActivated = true;
}
void CEvent::Loop(){
	key.Loop();
	LMouse.Loop();
	RMouse.Loop();
}
void CEvent::Activate(){
	IsActivated = true;
}
void CEvent::Deactivate(){
	IsActivated = false;
}
bool CEvent::GetValid(){
	return IsActivated;
}


CInput::CInput(){
	useMouse = true;
	useKey = true;
}	
void CInput::AddEventListener( int inputCode , void func() ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncVoid=func;
	keyTask.push_back(keyTemp);

}
void CInput::AddEventListener( int inputCode , void func(int) , int *pArgument ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncInt=func;
	keyTemp.pInt = pArgument;
	keyTask.push_back(keyTemp);

}
void CInput::AddEventListener( int inputCode , void func(int) , int Argument ){
				
	keyTemp.keyCode=inputCode;
	keyTemp.pFuncInt=func;
	keyTemp.Int = Argument;
	keyTask.push_back(keyTemp);

}
void CInput::RemoveEventListener( int inputCode , void func()  ){

	vector< CKeyIn >::iterator it = keyTask.begin();

	while( ( it != keyTask.end() ) ){

		if( it->keyCode == inputCode && it->pFuncVoid == func  ){

			keyTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( int inputCode , void func(int) , int *pArgument  ){

	vector< CKeyIn >::iterator it = keyTask.begin();

	while( ( it != keyTask.end() ) ){

		if( it->keyCode == inputCode && it->pFuncInt == func && it->pInt == pArgument ){

			keyTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( int inputCode , void func(int) , int Argument  ){

	vector< CKeyIn >::iterator it = keyTask.begin();

	while( ( it != keyTask.end() ) ){

		if( it->keyCode == inputCode && it->pFuncInt == func  && it->Int == Argument ){

			keyTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::AddEventListener( CMouseIn input , void func()  ){

	mouseTemp=input;
	mouseTemp.pFuncVoid=func;
	mouseTask.push_back(mouseTemp);
				
}
void CInput::AddEventListener( CMouseIn input , void func(int) , int *pArgument  ){

	mouseTemp=input;
	mouseTemp.pFuncInt=func;
	mouseTemp.pInt = pArgument;
	mouseTask.push_back(mouseTemp);
				
}
void CInput::AddEventListener( CMouseIn input , void func(int) , int Argument  ){

	mouseTemp=input;
	mouseTemp.pFuncInt=func;
	mouseTemp.Int = Argument;
	mouseTask.push_back(mouseTemp);
				
}
void CInput::RemoveEventListener( CMouseIn input , void func()  ){

	vector< CMouseIn >::iterator it = mouseTask.begin();

	while( ( it != mouseTask.end() ) ){

		if( it->pFuncVoid == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){

			mouseTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  ){

	vector< CMouseIn >::iterator it = mouseTask.begin();

	while( ( it != mouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2 && it->pInt == pArgument ){

			mouseTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( CMouseIn input , void func(int) , int Argument  ){

	vector< CMouseIn >::iterator it = mouseTask.begin();

	while( ( it != mouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->Int == Argument ){

			mouseTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::AddEventListener( CpMouseIn input , void func()  ){

	pMouseTemp=input;
	pMouseTemp.pFuncVoid=func;
	pMouseTask.push_back(pMouseTemp);
				
}
void CInput::AddEventListener( CpMouseIn input , void func(int) , int *pArgument  ){

	pMouseTemp=input;
	pMouseTemp.pFuncInt=func;
	pMouseTemp.pInt = pArgument;
	pMouseTask.push_back(pMouseTemp);
				
}
void CInput::AddEventListener( CpMouseIn input , void func(int) , int Argument  ){

	pMouseTemp=input;
	pMouseTemp.pFuncInt=func;
	pMouseTemp.Int = Argument;
	pMouseTask.push_back(pMouseTemp);
				
}
void CInput::RemoveEventListener( CpMouseIn input , void func()  ){

	vector< CpMouseIn >::iterator it = pMouseTask.begin();

	while( ( it != pMouseTask.end() ) ){

		if( it->pFuncVoid == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  ){

			pMouseTask.erase( it );
			break;
		}
		it++;
	}
}
void CInput::RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  ){

	vector< CpMouseIn >::iterator it = pMouseTask.begin();

	while( ( it != pMouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->pInt == pArgument ){

			pMouseTask.erase( it );
			break;
		}
		it++;
	}
}
void CInput::RemoveEventListener( CpMouseIn input , void func(int) , int Argument  ){

	vector< CpMouseIn >::iterator it = pMouseTask.begin();

	while( ( it != pMouseTask.end() ) ){

		if( it->pFuncInt == func && it->type == input.type && it->x1 == input.x1 && it->x2 == input.x2 && it->y1 == input.y1 && it->y2 == input.y2  && it->Int == Argument ){

			pMouseTask.erase( it );
			break;
		}
		it++;
	}
}
void CInput::AddEventListener( char input , void func()  ){
	frameTemp.pFuncVoid=func;
	frameTask.push_back(frameTemp);
			
}
void CInput::AddEventListener( char input , void func(int) , int *pArgument  ){
	frameTemp.pFuncInt=func;
	frameTemp.pInt = pArgument;
	frameTask.push_back(frameTemp);
			
}
void CInput::AddEventListener( char input , void func(int) , int Argument  ){
	frameTemp.pFuncInt=func;
	frameTemp.Int = Argument;
	frameTask.push_back(frameTemp);
			
}
void CInput::RemoveEventListener( char input , void func()  ){

	vector< CFrame >::iterator it = frameTask.begin();

	while( ( it != frameTask.end() ) ){

		if( it->pFuncVoid ==  func  ){

			frameTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( char input , void func(int) , int *pArgument  ){

	vector< CFrame >::iterator it = frameTask.begin();

	while( ( it != frameTask.end() ) ){

		if( it->pFuncInt ==  func  && it->pInt == pArgument ){

			frameTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::RemoveEventListener( char input , void func(int) , int Argument  ){

	vector< CFrame >::iterator it = frameTask.begin();

	while( ( it != frameTask.end() ) ){

		if( it->pFuncInt ==  func  && it->Int == Argument ){

			frameTask.erase( it );
			break;
		}
		it++;
	}
		
}
void CInput::AddEventListener( bool* input , void func()  ){
	boolTemp.pFuncVoid=func;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void CInput::AddEventListener( bool* input , void func(int) , int *pArgument  ){
	boolTemp.pFuncInt=func;
	boolTemp.pInt = pArgument;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void CInput::AddEventListener( bool* input , void func(int) , int Argument  ){
	boolTemp.pFuncInt=func;
	boolTemp.Int = Argument;
	boolTemp.pBool=input;
	boolTask.push_back(boolTemp);
			
}
void CInput::RemoveEventListener( bool* input , void func()  ){

	vector< CBoolean >::iterator it = boolTask.begin();

	while( ( it != boolTask.end() ) ){

		if( it->pBool == input && it->pFuncVoid == func  ){

			boolTask.erase( it );
			break;
		}
		it++;
	}
	
}	
void CInput::RemoveEventListener( bool* input , void func(int) , int *pArgument  ){

	vector< CBoolean >::iterator it = boolTask.begin();

	while( ( it != boolTask.end() ) ){

		if( it->pBool == input && it->pFuncInt == func  && it->pInt == pArgument ){

			boolTask.erase( it );
			break;
		}
		it++;
	}
	
}
void CInput::RemoveEventListener( bool* input , void func(int) , int Argument  ){

	vector< CBoolean >::iterator it = boolTask.begin();

	while( ( it != boolTask.end() ) ){

		if( it->pBool == input && it->pFuncInt == func  && it->Int == Argument ){

			boolTask.erase( it );
			break;
		}
		it++;
	}
	
}
void CInput::Loop(){

		
	//KEY
	if(useKey){


		vector<CKeyIn>::iterator it=keyTask.begin();

		while( it != keyTask.end() ) {
			if(Event.key.GetPush(it->keyCode)){
					
				CKeyIn temp=*it;
				if(temp.pFuncVoid != NULL){
					temp.pFuncVoid();
				}else{
					if(temp.pInt == NULL){
						temp.pFuncInt(temp.Int);
					}else{
						temp.pFuncInt(*temp.pInt);
					}
				}
			}
			it++;
		}	
	}
		
	//MOUSE
	if(useMouse){

		GetMousePoint( &mouseX, &mouseY );
		preMouseInput = mouseInput;
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_LEFT );

		vector<CMouseIn>::iterator it1=mouseTask.begin();

		while( it1 != mouseTask.end() ) {

			CMouseIn temp = *it1;
			
			switch(temp.type){
				
			case MOUSE_OFF :
				if(temp.x1>mouseX && temp.x2<mouseX ){
					if(temp.y1>mouseY && temp.y2<mouseY){
						
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							if(temp.pInt == NULL){
								temp.pFuncInt(temp.Int);
							}else{
								temp.pFuncInt(*temp.pInt);
							}
						}
						
					}
				}
				break;
			case MOUSE_ON :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							if(temp.pInt == NULL){
								temp.pFuncInt(temp.Int);
							}else{
								temp.pFuncInt(*temp.pInt);
							}
						}
						
					}
				}
				break;

			case MOUSE_PUSH :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput){
							
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}							
						}
					}
				} 
				break;
			case MOUSE_CLICK :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput && !preMouseInput ){
							
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}			
						} 
					}
				}
				break;
			case MOUSE_RELEASE :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if( !mouseInput && preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}	
						} 
					}	
				}
				break;
			default :
				break;
			}
			it1++;
		}

		vector<CpMouseIn>::iterator it11 =pMouseTask.begin();

			while( it11 != pMouseTask.end() ) {

				CpMouseIn temp = *it11;
					
					
				switch(temp.type){
				
				case MOUSE_OFF :
					if( *(temp.x1) > mouseX && *(temp.x2) < mouseX ){
						if( *(temp.y1) > mouseY && *(temp.y2) < mouseY ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}				
						}
					}
					break;
				case MOUSE_ON :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								if(temp.pInt == NULL){
									temp.pFuncInt(temp.Int);
								}else{
									temp.pFuncInt(*temp.pInt);
								}
							}			
						} 
					} 
					break;
				case MOUSE_PUSH :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
							if( mouseInput ){
									
								if(temp.pFuncVoid != NULL){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == NULL){
										temp.pFuncInt(temp.Int);
									}else{
										temp.pFuncInt(*temp.pInt);
									}
								}	
							} 
						}
					} 
					break;
				case MOUSE_CLICK :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
							if( mouseInput && !preMouseInput ){
									
								if(temp.pFuncVoid != NULL){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == NULL){
										temp.pFuncInt(temp.Int);
									}else{
										temp.pFuncInt(*temp.pInt);
									}
								}	
							} 
						} 
					} 
					break;
				case MOUSE_RELEASE :
					if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
						if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
							if( !mouseInput && preMouseInput ){
									
								if(temp.pFuncVoid != NULL){
									temp.pFuncVoid();
								}else{
									if(temp.pInt == NULL){
										temp.pFuncInt(temp.Int);
									}else{
										temp.pFuncInt(*temp.pInt);
									}
								}									
							}	
						} 
					} 
					break;
				default :
					break;
				}
				it11++;
			}
		}


	vector<CFrame>::iterator it2 = frameTask.begin();

	while( it2 != frameTask.end() ) {
		CFrame temp=*it2;

		if(temp.pFuncVoid != NULL){
			temp.pFuncVoid();
		}else{
			if(temp.pInt == NULL){
				temp.pFuncInt(temp.Int);
			}else{
				temp.pFuncInt(*temp.pInt);
			}
		}
		it2++;
	}

	vector<CBoolean>::iterator it3=boolTask.begin();

	while( it3 != boolTask.end() ) {
			
		CBoolean temp=*it3;

		if(*(temp.pBool)){
			
			if(temp.pFuncVoid != NULL){
				temp.pFuncVoid();
			}else{
				if(temp.pInt == NULL){
					temp.pFuncInt(temp.Int);
				}else{
					temp.pFuncInt(*temp.pInt);
				}
			}

		}

		it3++;
	}

}//end of void Loop()
void CInput::DrawLoop(){
	//KEY
	if(useKey){

		vector<CKeyIn>::iterator it=keyTask_Draw.begin();

		while( it != keyTask_Draw.end() ) {
			if(CheckHitKey(it->keyCode)){

				CKeyIn temp=*it;
				if(temp.pFuncVoid != NULL){
					temp.pFuncVoid();
				}else{
					temp.pFuncInt(*temp.pInt);
				}
			}
			it++;
		}	
	}
		
	//MOUSE
	if(useMouse){

		vector<CMouseIn>::iterator it1=mouseTask_Draw.begin();

		while( it1 != mouseTask_Draw.end() ) {

			CMouseIn temp = *it1;
			
			switch(temp.type){
				
			case MOUSE_OFF :
				if(temp.x1>mouseX && temp.x2<mouseX ){
					if(temp.y1>mouseY && temp.y2<mouseY){
							
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}	
					}
				}
				break;
			case MOUSE_ON :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
							
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}						
					}
				}
					break;
			case MOUSE_PUSH :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}							
						}
					}
				} 
				break;
			case MOUSE_CLICK :
					if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if(mouseInput && !preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}						
						} 
					}
				}
				break;
			case MOUSE_RELEASE :
				if(temp.x1<mouseX && temp.x2>mouseX ){
					if(temp.y1<mouseY && temp.y2>mouseY){
						if( !mouseInput && preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}							
						} 
					}	
				}
				break;
			default :
				break;
			}
			it1++;
		}

		vector<CpMouseIn>::iterator it11 =pMouseTask_Draw.begin();

		while( it11 != pMouseTask_Draw.end() ) {

			CpMouseIn temp = *it11;
					
					
			switch(temp.type){
				
			case MOUSE_OFF :
				if( *(temp.x1) > mouseX && *(temp.x2) < mouseX ){
					if( *(temp.y1) > mouseY && *(temp.y2) < mouseY ){
								
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}					
					}
				}
				break;
			case MOUSE_ON :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY){
								
						if(temp.pFuncVoid != NULL){
							temp.pFuncVoid();
						}else{
							temp.pFuncInt(*temp.pInt);
						}							
					} 
				} 
				break;
			case MOUSE_PUSH :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
						if( mouseInput ){									
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}						
						} 
					}
				} 
				break;
			case MOUSE_CLICK :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
						if( mouseInput && !preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}		
						} 
					} 
				} 
				break;
			case MOUSE_RELEASE :
				if( *(temp.x1) < mouseX && *(temp.x2) > mouseX ){
					if( *(temp.y1) < mouseY && *(temp.y2) > mouseY ){
						if( !mouseInput && preMouseInput ){
								
							if(temp.pFuncVoid != NULL){
								temp.pFuncVoid();
							}else{
								temp.pFuncInt(*temp.pInt);
							}					
						}	
					} 
				} 
				break;
			default :
				break;
			}
			it11++;
		}
	}
	//ループ
	vector<CFrame>::iterator it2=frameTask_Draw.begin();

	while( it2 != frameTask_Draw.end() ) {
		CFrame temp=*it2;
		if(temp.pFuncVoid != NULL){
			temp.pFuncVoid();
		}else{
			temp.pFuncInt(*temp.pInt);
		}
		it2++;
	}
		
	//bool
	vector<CBoolean>::iterator it3=boolTask_Draw.begin();

	while( it3 != boolTask_Draw.end() ) {
		CBoolean temp=*it3;

		if(*(temp.pBool)){
			
			if(temp.pFuncVoid != NULL){
				temp.pFuncVoid();
			}else{
				temp.pFuncInt(*temp.pInt);
			}
		}

		it3++;
	}
}//end of DrawLoop()
