#include "Suken.h"

void suken::Awake(){
	Game.rootScene.SetButton((float)System.GetWindowX()*(18.0f/20.0f), (float)System.GetWindowY()*(1.0f / 15.0f), (float)System.GetWindowX()*(19.0f / 20.0f), (float)System.GetWindowY()*(2.0f / 15.0f),YELLOW,"Å®",BLACK,(void(*)())nullptr);
	
}

void suken::GameLoopEnter(){
	if (Game.GetCurrentScene() == &Game.rootScene ) {
		debug.Print("rootScene");
		DxLib::DrawBox(100,100,200,200,RED,true);
	}
	else {
		debug.Print("hshdhsdhbdjks");
	}
}

void suken::GameLoopExit(){

}