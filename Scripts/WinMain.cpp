#include"Suken.h"
#include<windows.h>
using namespace suken;




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow){

	
	//////////////////////////////////////////////////////////////////////////////////////////
	

	//処理設定　ここから//////////////////////////////////////////////
	
	DxLib::SetWindowStyleMode(0) ;/*０：今までどおりの普通のウインドウ １：タイトルバーなし、縁あり ２：タイトルバーも縁もなし*/
	DxLib::SetMainWindowText("SukenLib");
	System.SetWindowSize(900,600);							//ウインドウサイズを設定
	System.SetTargetFps(60.0);								//目標のフレームレートを設定
	System.SetLoadingGraph("SukenLibAsset/LOGO/LOGO.png");	//ローディング画面に表示する画像のアドレスを指定
	System.SetUseThread_Awake(false);						//void Awake()の実行をバックグラウンドで行うかどうか
	System.SetLoadingMinimalTime(0);						//Loading画面の最低表示時間をミリ秒で設定
	//処理設定　ここまで//////////////////////////////////////////////
	System.Awake();
	debug.Awake(hInstance,hPreInst,nCmdShow);


	///////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	
	if(System.GetUseThread_Awake()){
		System.CreateNewThread(Awake);
	}else{
		Awake();
	}
	System.Wait_Loading();

	while(!ProcessMessage() &&!System.GetEscapeFlag()){
		ScreenFlip();
		ClearDrawScreen();
		System.Update();
		GameLoopEnter();
		Game.Loop();
		GameLoopExit();
		Game.ExecuteCommand();
		System.ExitFrame();
		debug.Loop();
		System.Wait();
	}
        
	System.End();
	return 0;
} 



