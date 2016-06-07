#include"Suken.h"
int keyInputHandle;
void Awake(){
	
}
void GameLoopEnter(){
	if(Event.key.GetDown(Event.key.RETURN)){
		keyInputHandle = Game.rootScene.input.keyInput.japanese.MakeInput(300,300,8);
		Game.rootScene.input.keyInput.japanese.front().SetColor(GetColor(255,255,255));
	}
	DrawBox(0,0,System.GetWindowX(),System.GetWindowY(),WHITE,true);
}
void GameLoopExit(){
	
}