#include"System.h"
#include"../Utility/Utility.h"
#include"../GameEngine/Game.h"

suken::CSystem::CSystem()
{
	startTime = 0;
	count = 0;
	fps = 60.0;		//0���Z��h������
	frame = 0;
	escapeFlag = false;
	targetFps = 0.0f;
	screenShotGrHandleAdress = nullptr;
	loadingImgPath = "";
	window_w = WINDOW_WIDTH;
	window_h = WINDOW_HEIGHT;
}
suken::CSystem::~CSystem()
{
	
}
void suken::CSystem::Awake()
{
	//�Q�[���̒���{�ݒ�A���ʉ���������Ȃ�
	SetWindowIconID( 101 ) ;//�A�C�R���̂��
	SetGraphMode( window_w ,  window_h , 32 ) ;//SetWindowSize(WINDOW_WIDTH , WINDOW_HEIGHT );
	ChangeWindowMode(TRUE);
	SetAlwaysRunFlag(TRUE);//�펞�N������̂�TRUE
	SetOutApplicationLogValidFlag( FALSE );//���O�o�͗}������̂�FALSE
	DxLib_Init(); 
	SetDrawScreen( DX_SCREEN_BACK );
	SetTransColor( 255 , 0 , 255 );	//�}�[���^����
	if(loadingImgPath != ""){
		loadingImg = LoadGraph(loadingImgPath.c_str());
	}
	DrawExtendGraph(0,0,System.GetWindowX(),System.GetWindowY(),loadingImg,true);
	dispX = GetSystemMetrics(SM_CXSCREEN);
	dispY = GetSystemMetrics(SM_CYSCREEN);
	//���t���b�V�����[�g�̎擾
	HDC hdc;
	hdc = GetDC( GetMainWindowHandle() );//�f�o�C�X�R���e�L�X�g�̎擾
	refreshRate = GetDeviceCaps( hdc , VREFRESH );//���t���b�V�����[�g�̎擾
	ReleaseDC( GetMainWindowHandle() , hdc );//�f�o�C�X�R���e�N�X�g�̉��

	display = CreateDC(TEXT("DISPLAY") , nullptr , nullptr , nullptr);

	settings.input.AddEventListener(Event.EVERY_FRAME,SettingLoop);

#ifdef USE_LUA
	Lua = luaL_newstate();
#endif
	ScreenFlip();

	N = refreshRate;//1�b�Ɉ��fps���Z�o

	now = GetNowCount();
	localStandardTime = now;

}
int  suken::CSystem::GetLocalStandardTime()
{
	return localStandardTime;
}
void suken::CSystem::SetUseThread_Awake(bool flag)
{
	useThread_AwakeFlag = flag;
}
bool suken::CSystem::GetUseThread_Awake()
{
	return useThread_AwakeFlag;
}
void suken::CSystem::SetLoadingGraph(const std::string path)
{
	loadingImgPath = path;
}
void suken::CSystem::SetLoadingMinimalTime(int time)
{
	loadingMinimalTime = time;
}
void suken::CSystem::Wait_Loading()
{
	int restTime = loadingMinimalTime - (GetNowCount()-localStandardTime);
	if(restTime > 0){
		WaitTimer(restTime);
	}
}
void suken::CSystem::Update()
{
	if (Event.key.GetPush(Event.key.S) && Event.key.GetPush(Event.key.K) && (Event.key.GetPush(Event.key.RCONTROL)|| Event.key.GetPush(Event.key.LCONTROL))) {
		Game.AddChild(&this->settings);
	}
	//�Վ�
	//N = (int)(GetFps()+0.5);
	//
	now = GetNowCount();
	if( count == 0 ){ //1�t���[���ڂȂ玞�����L��
		startTime = now;
	}
	if( count == N ){ //�K��t���[���ɒB�����畽�ς��v�Z����
		
		fps = (float)( 1000/((now-startTime)/(double)N) );
		count = 0;
		startTime = now;

	}

	count++;
	frame++;
}
void suken::CSystem::Wait()
{
		
#ifdef DEBUG_DRAW
	DrawFormatString(0, 0, WHITE, "%.1f", fps);
#endif
	if(targetFps != 0.0f){
		int tookTime = now - startTime;	//������������
		int waitTime = (int)( count*1000/targetFps - tookTime );	//�҂ׂ�����
		if( waitTime > 0 ){
		Sleep(waitTime);	//�ҋ@
		}
	}else{
		Sleep(0);	//�]�����^�C���X���C�X��j��
	}	
}
void suken::CSystem::End()
{
	DxLib_End();	
	ShellExecute(GetMainWindowHandle() , "open" , "Launcher.exe" , nullptr , nullptr , SW_SHOW);
}
void suken::CSystem::TakeScreenShot()
{
	if(screenShotFlag){
		screenShotFlag = false;
		if(screenShotGrHandleAdress != nullptr){
			int screenShot = MakeGraph(this->GetWindowX(),this->GetWindowY());
			GetDrawScreenGraph(0,0,this->GetWindowX(), this->GetWindowY(),screenShot);
			*screenShotGrHandleAdress = screenShot;
		}
		screenShotGrHandleAdress = nullptr;
	}
}
void suken::CSystem::GetScreenShot(int *GrHandleAdress)
{
	screenShotFlag = true;
	screenShotGrHandleAdress = GrHandleAdress;
}
void suken::CSystem::Escape()
{
	escapeFlag = true;
}
bool suken::CSystem::GetEscapeFlag()
{	
	return escapeFlag;
}
int suken::CSystem::GetFrame()
{
	return frame;
}
int suken::CSystem::GetNow()
{
	return now;
}
float suken::CSystem::GetFps()
{
	return fps;
}
int suken::CSystem::GetRefreshRate()
{
	return refreshRate;
}
void suken::CSystem::SetTargetFps(float _fps)
{
	targetFps = _fps;
}
float suken::CSystem::GetTargetFps()
{
	return targetFps;
}
//�V�����X���b�h�����B
void suken::CSystem::CreateNewThread( void(*pFunc)() )
{
	if(handleChild.empty()){				
		DxLib::SetMultiThreadFlag( true );			//���̂܂܂ł�DxLib��DirectX�̊֌W�Ń}���`�X���b�h�ɂł��Ȃ��̂Őݒ肵�Ă��K�v������
	}
	//�V�����X���b�h���쐬�i�^�uHANDLE�v�̓|�C���^�Ȃ̂�System::CreateNewThread���\�b�h���I�����Ă������I�ɔj������Ȃ��j
	HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pFunc, nullptr, 0, LPDWORD());

	handleChild.push_back(handle);
}
HDC suken::CSystem::GetDisplayDC()
{
	return display;
}
#ifdef USE_LUA
lua_State* CSystem::GetLua()
{
	return Lua;
}
#endif
void suken::CSystem::SetWindowSize( int width , int height )
{
	window_w = width;
	window_h = height;
}

int suken::CSystem::GetWindowX()
{
	return window_w; 
}

int suken::CSystem::GetWindowY()
{
	return window_h; 
}

void suken::CSystem::ExitFrame()
{
	TakeScreenShot();
}

int suken::CSystem::GetDispX() 
{
	return dispX;
}

int suken::CSystem::GetDispY() 
{
	return dispY;
}
//Singleton
suken::CSystem System;


void suken::SettingLoop()
{
	if (Event.key.GetPush(Event.key.ESCAPE)) {
		Game.RemoveChild();
	}
}
