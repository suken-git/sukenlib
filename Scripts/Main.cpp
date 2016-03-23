#include"Suken.h"


void Awake(){	
	
}

void GameLoopEnter(){
	
}
void GameLoopExit(){
	if(Event.key.GetDown(Event.key.RETURN)){
		DrawBox(0,0,100,100,RED,true);
	}
	if(Event.key.GetUp(Event.key.RETURN)){
		DrawBox(100,0,200,100,BLUE,true);
	}
	if(Event.key.GetPush(Event.key.RETURN)){
		DrawBox(200,0,300,100,GREEN,true);
	}
	int count = Event.key.GetCount(Event.key.RETURN);
	DrawFormatString(120,120,YELLOW,"前回入力から　%d フレーム",count);
}

