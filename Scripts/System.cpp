#include"Suken.h"



int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	//処理設定　ここから//////////////////////////////////////////////
	System.SetTargetFps(60.0);				//目標のフレームレートを設定
	System.SetLoadingGraph("loading.png");	//ローディング画面に表示する画像のアドレスを指定
	System.SetUseThread_Awake(false);		//void Awake()の実行をバックグラウンドで行うかどうか
	game.SetUseDrawLoop(false);				//処理と描画を完全分離するかどうか
	System.SetSyncDrawLoop(false);			//game.SetUseDrawLoop()をtrueにしたとき処理と描画を同期するかどうか
	System.SetLoadingMinimalTime(1000);		//Loading画面の最低表示時間をミリ秒で設定
	//処理設定　ここまで//////////////////////////////////////////////


	System.Awake();
	
	if(System.GetUseThread_Awake()){
		System.CreateNewThread(Awake);
	}else{
		Awake();
	}
	System.Wait_Loading();

	if(game.GetUseDrawLoop()){
		System.CreateNewThread(GameDrawLoop);
	}

	while(!ProcessMessage()&&!System.GetEscapeFlag()){
		if(!game.GetUseDrawLoop()){
			ScreenFlip();
			ClearDrawScreen();
		}else if(game.GetUseDrawLoop()&&System.GetSyncDrawLoop()){
			ScreenFlip();
			ClearDrawScreen();
		}
		System.Update();
		GameLoopEnter();
		game.Loop();
		if(game.GetUseDrawLoop()&&System.GetSyncDrawLoop()){
			game.DrawLoop();
		}
		GameLoopExit();
		System.Wait();
		
	}
        
	System.End();
	return 0;
} 


void GameDrawLoop(){
	
	while(!ProcessMessage()&&!System.GetEscapeFlag()){
		if(!System.GetSyncDrawLoop()){
			ScreenFlip();
			ClearDrawScreen();
		}
		game.DrawLoop();
	}
	
}
