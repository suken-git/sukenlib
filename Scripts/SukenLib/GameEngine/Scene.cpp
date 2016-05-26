#include"Scene.h"
#include <Utility/Debug.h>


//�ÓI�����o�ϐ�
unsigned int suken::CScene::sceneNum;


suken::CScene::CScene()
{
	serialNum = sceneNum;
	sceneNum++;
	focus = false;
	sceneChild = nullptr;
}
void suken::CScene::Loop()
{
	if(!focus){
		input.useKey = false;
		input.useMouse = false;
		Event.Deactivate();
	}
		
	input.Loop();
	ButtonLoop();
	input.DrawLoop();

	collision.Loop();
	collision.DrawLoop();

	if( sceneChild != nullptr ){
		sceneChild->Loop();
	}

	if(focus){
		input.useKey = true;
		input.useMouse = true;
	}
	Event.Activate();
}
void suken::CScene::ButtonLoop()
{
		

	std::vector<CButton>::iterator it = buttonChild.begin();
	if( buttonChild.size() != 0 ){
		while( it != buttonChild.end() ) {
			if(it->IsUseGraph){
				if(it->IsReact){
					if(Event.LMouse.GetOn((it->x1) , (it->y1) , (it->x2) , (it->y2))){
						DrawExtendGraph( (it->x1) , (it->y1) , (it->x2) , (it->y2) , (it->graphHandle_on) , true );
					}else{
						DrawExtendGraph( (it->x1) , (it->y1) , (it->x2) , (it->y2) , (it->graphHandle_off) , true );
					}
				}else{
					DrawExtendGraph( (it->x1) , (it->y1) , (it->x2) , (it->y2) , (it->graphHandle) , true );
				}
			}else{
					
				DxLib::DrawBox(it->x1,it->y1,it->x2,it->y2,it->backColor,TRUE);
				suken::DrawCenterString((it->x1+it->x2)/2,(it->y1+it->y2)/2-10,it->stringColor,it->title.c_str());
			}
			it++;
		}
	}
	std::vector<CpButton>::iterator it1 = pButtonChild.begin();
	if( pButtonChild.size() != 0 ){
		while( it1 != pButtonChild.end() ) {
			if(it1->IsUseGraph){
				if(it1->IsReact){
					if(Event.LMouse.GetOn(*(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2))){
						DrawExtendGraph( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , (it1->graphHandle_on) , true );
					}else{
						DrawExtendGraph( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , (it1->graphHandle_off) , true );
					}
				}else{
					DrawExtendGraph( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , (it1->graphHandle) , true );
				}
			}else{
				DxLib::DrawBox( *(it1->x1) , *(it1->y1) , *(it1->x2) , *(it1->y2) , it1->backColor , TRUE );
				suken::DrawCenterString( (*(it1->x1) + *(it1->x2) ) / 2 , ( *(it1->y1) + *(it1->y2) ) / 2 - 10 , it1->stringColor , it1->title.c_str() );
			}
			it1++;
		}
	}		
}
void suken::CScene::SetFocus(bool _focus)
{
	focus = _focus;
}
bool suken::CScene::GetFocus()
{
	return focus;
}
void suken::CScene::AddChild(CScene *_scene)
{
	if(focus){
		if( sceneChild != nullptr ){
			RemoveChild();
		}
		//�t�H�[�J�X�̈ڍs
		this->SetFocus(false);
		_scene->SetFocus(true);
		//�ǉ�
		sceneChild = _scene;
	}else{
		WarningSK("���ݗL���ł͂Ȃ��V�[���ɓ���q�̃V�[����ǉ����邱�Ƃ͂ł��܂���(CScene::AddChild)");
	}
}
void suken::CScene::RemoveChild()
{
	if( sceneChild != nullptr ){
		//�t�H�[�J�X�̈ڍs
		sceneChild->SetFocus(false);
		this->SetFocus(true);
		//�폜
		sceneChild = nullptr;
	}else{
		WarningSK("CScene::RemoveChild���Ăяo����܂�����CScene::sceneChild�ɃV�[��������܂���");
	}
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)() )
{
	CButton temp;
	temp.IsUseGraph = false;
	temp.title = title;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.backColor = backColor;
	temp.stringColor = stringColor;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) , int *pInt )
{
	CButton temp;
	temp.IsUseGraph = false;
	temp.title = title;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.backColor = backColor;
	temp.stringColor = stringColor;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) , int Int )
{
	CButton temp;
	temp.IsUseGraph = false;
	temp.title = title;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.backColor = backColor;
	temp.stringColor = stringColor;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)() )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = graph;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int *pInt )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = graph;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int Int )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = graph;

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)() )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = LoadGraph(graphPath.c_str());
	if( temp.graphHandle == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)(int) , int *pInt )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = LoadGraph(graphPath.c_str());
	if( temp.graphHandle == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)(int) , int Int )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = LoadGraph(graphPath.c_str());
	if( temp.graphHandle == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	buttonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)() )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.IsReact = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle_off = LoadGraph(Off_graphPath.c_str());
	temp.graphHandle_on = LoadGraph(On_graphPath.c_str());
	if( temp.graphHandle_off == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}
	if( temp.graphHandle_on == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );

	buttonChild.push_back( temp );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int *pInt )
{
	CButton temp;
	
	temp.IsUseGraph = true;
	temp.IsReact = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle_off = LoadGraph(Off_graphPath.c_str());
	temp.graphHandle_on = LoadGraph(On_graphPath.c_str());
	if( temp.graphHandle_off == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}
	if( temp.graphHandle_on == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );

	buttonChild.push_back( temp );
}
void suken::CScene::SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int Int )
{
	CButton temp;
		
	temp.IsUseGraph = true;
	temp.IsReact = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle_off = LoadGraph(Off_graphPath.c_str());
	temp.graphHandle_on = LoadGraph(On_graphPath.c_str());
	if( temp.graphHandle_off == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}
	if( temp.graphHandle_on == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );

	buttonChild.push_back( temp );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)() )
{
	CpButton temp;
	temp.IsUseGraph = false;
	temp.title = title;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.backColor = backColor;
	temp.stringColor = stringColor;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) ,int *pInt )
{
	CpButton temp;
	temp.IsUseGraph = false;
	temp.title = title;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.backColor = backColor;
	temp.stringColor = stringColor;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,pInt );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) ,int Int )
{
	CpButton temp;
	temp.IsUseGraph = false;
	temp.title = title;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.backColor = backColor;
	temp.stringColor = stringColor;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,Int );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)() )
{
	CpButton temp;
	temp.IsUseGraph = true;
		
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
		
	temp.graphHandle = graph;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int *pInt )
{
	CpButton temp;
	temp.IsUseGraph = true;
		
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
		
	temp.graphHandle = graph;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,pInt );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int Int )
{
	CpButton temp;
	temp.IsUseGraph = true;
		
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
		
	temp.graphHandle = graph;

	pButtonChild.push_back( temp );

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)() )
{
	CpButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = LoadGraph(graphPath.c_str());
	if( temp.graphHandle == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��char graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	pButtonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)(int) , int *pInt )
{
	CpButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = LoadGraph(graphPath.c_str());
	if( temp.graphHandle == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��char graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	pButtonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,pInt );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)(int) , int Int )
{
	CpButton temp;
		
	temp.IsUseGraph = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle = LoadGraph(graphPath.c_str());
	if( temp.graphHandle == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��char graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	pButtonChild.push_back( temp );
		
	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc ,Int );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)() )
{
	CpButton temp;
		
	temp.IsUseGraph = true;
	temp.IsReact = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle_off = LoadGraph(Off_graphPath.c_str());
	temp.graphHandle_on = LoadGraph(On_graphPath.c_str());
	if( temp.graphHandle_off == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}
	if( temp.graphHandle_on == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc );

	pButtonChild.push_back( temp );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int *pInt )
{
	CpButton temp;
		
	temp.IsUseGraph = true;
	temp.IsReact = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle_off = LoadGraph(Off_graphPath.c_str());
	temp.graphHandle_on = LoadGraph(On_graphPath.c_str());
	if( temp.graphHandle_off == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}
	if( temp.graphHandle_on == -1 ){	
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , pInt );

	pButtonChild.push_back( temp );
}
void suken::CScene::SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int Int )
{
	CpButton temp;
		
	temp.IsUseGraph = true;
	temp.IsReact = true;
	temp.x1 = x1;
	temp.x2 = x2;
	temp.y1 = y1;
	temp.y2 = y2;
	temp.graphHandle_off = LoadGraph(Off_graphPath.c_str());
	temp.graphHandle_on = LoadGraph(On_graphPath.c_str());
	if( temp.graphHandle_off == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string Off_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}
	if( temp.graphHandle_on == -1 ){
		MessageBox(nullptr,"error : SetButton���\�b�h��std::string On_graphPath�̃O���t�B�b�N�̃p�X�ɖ����Ȓl�����͂���܂���","�������C�u����",MB_OK);
	}

	this->input.AddEventListener( Event.LMouse.Click( x1 , y1 , x2 , y2 ) , pFunc , Int );

	pButtonChild.push_back( temp );
}
//�������C�u���������֐��i�g�p�֎~�j
void suken::CScene::ResetSceneNum()
{
	sceneNum = 1;
}
unsigned int suken::CScene::GetSerialNum()
{
	return serialNum;
}
