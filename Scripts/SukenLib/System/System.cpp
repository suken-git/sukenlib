#include"System.h"
#include <Utility/Utility.h>
//Singleton
suken::CSystem System;

suken::CSystem::CSystem(){
	startTime = 0;
	count = 0;
	fps = 60.0;		//0除算を防ぐため
	frame = 0;
	escapeFlag = false;
	targetFps = 0.0f;
	screenShotGrHandleAdress = nullptr;
	loadingImgPath = "";
}
suken::CSystem::~CSystem(){
	
}
void suken::CSystem::Awake(){
	//ゲームの超基本設定、普通何もいじらない
	SetWindowIconID( 101 ) ;//アイコンのやつ
	SetGraphMode( WINDOW_WIDTH ,  WINDOW_HEIGHT , 32 ) ;//SetWindowSize(WINDOW_WIDTH , WINDOW_HEIGHT );
	ChangeWindowMode(TRUE);
	SetAlwaysRunFlag(TRUE);//常時起動するのでTRUE
	SetOutApplicationLogValidFlag( FALSE );//ログ出力抑制するのでFALSE
	DxLib_Init(); 
	SetDrawScreen( DX_SCREEN_BACK );
	SetTransColor( 255 , 0 , 255 );	//マゼンタ透過
	if(loadingImgPath != ""){
		loadingImg = LoadGraph(loadingImgPath.c_str());
	}
	DrawExtendGraph(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,loadingImg,true);
	//リフレッシュレートの取得
	HDC hdc;
	hdc = GetDC( GetMainWindowHandle() );//デバイスコンテキストの取得
	refreshRate = GetDeviceCaps( hdc , VREFRESH );//リフレッシュレートの取得
	ReleaseDC( GetMainWindowHandle() , hdc );//デバイスコンテクストの解放

	display = CreateDC(TEXT("DISPLAY") , nullptr , nullptr , nullptr);

#ifdef USE_LUA
	Lua = luaL_newstate();
#endif
	ScreenFlip();

	N = refreshRate;//1秒に一回fpsを算出

	now = GetNowCount();
	localStandardTime = now;

}
int  suken::CSystem::GetLocalStandardTime(){
	return localStandardTime;
}
void suken::CSystem::SetUseThread_Awake(bool flag){
	useThread_AwakeFlag = flag;
}
bool suken::CSystem::GetUseThread_Awake(){
	return useThread_AwakeFlag;
}
void suken::CSystem::SetLoadingGraph(const std::string path){
	loadingImgPath = path;
}
void suken::CSystem::SetLoadingMinimalTime(int time){
	loadingMinimalTime = time;
}
void suken::CSystem::Wait_Loading(){
	int restTime = loadingMinimalTime - (GetNowCount()-localStandardTime);
	if(restTime > 0){
		WaitTimer(restTime);
	}
}
void suken::CSystem::Update(){
	//臨時
	//N = (int)(GetFps()+0.5);
	//
	now = GetNowCount();
	if( count == 0 ){ //1フレーム目なら時刻を記憶
		startTime = now;
	}
	if( count == N ){ //規定フレームに達したら平均を計算する
		
		fps = 1000/((now-startTime)/(double)N);
		count = 0;
		startTime = now;

	}

	count++;
	frame++;
}
void suken::CSystem::Wait(){
		
#ifdef DEBUG_DRAW
	DrawFormatString(0, 5, WHITE, "%.1f", fps);
#endif
	if(targetFps != 0.0f){
		int tookTime = now - startTime;	//かかった時間
		int waitTime = count*1000/targetFps - tookTime;	//待つべき時間
		if( waitTime > 0 ){
		Sleep(waitTime);	//待機
		}
	}else{
		Sleep(0);	//余ったタイムスライスを破棄
	}	
}
void suken::CSystem::End(){
	DxLib_End();	
	ShellExecute(GetMainWindowHandle() , "open" , "Launcher.exe" , nullptr , nullptr , SW_SHOW);
}
void suken::CSystem::TakeScreenShot(){
	if(screenShotFlag){
		screenShotFlag = false;
		if(screenShotGrHandleAdress != nullptr){
			*screenShotGrHandleAdress = GetDrawScreen();
		}
		screenShotGrHandleAdress = nullptr;
	}
}
void suken::CSystem::GetScreenShot(int *GrHandleAdress){
	screenShotFlag = true;
	screenShotGrHandleAdress = GrHandleAdress;
}
void suken::CSystem::Escape(){
	escapeFlag = true;
}
bool suken::CSystem::GetEscapeFlag(){	
	return escapeFlag;
}
int suken::CSystem::GetFrame(){
	return frame;
}
int suken::CSystem::GetNow(){
	return now;
}
float suken::CSystem::GetFps(){
	return fps;
}
int suken::CSystem::GetRefreshRate(){
	return refreshRate;
}
void suken::CSystem::SetTargetFps(float _fps){
	targetFps = _fps;
}
float suken::CSystem::GetTargetFps(){
	return targetFps;
}
//新しいスレッドを作る。
void suken::CSystem::CreateNewThread( void(*pFunc)() ){
	if(handleChild.empty()){				
		DxLib::SetMultiThreadFlag( true );			//そのままではDxLibはDirectXの関係でマルチスレッドにできないので設定してやる必要がある
	}
	//新しいスレッドを作成（型「HANDLE」はポインタなのでSystem::CreateNewThreadメソッドが終了しても自動的に破棄されない）
	HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)pFunc, nullptr, 0, LPDWORD());

	handleChild.push_back(handle);
}
HDC suken::CSystem::GetDisplayDC(){
	return display;
}
#ifdef USE_LUA
lua_State* CSystem::GetLua(){
	return Lua;
}
#endif
