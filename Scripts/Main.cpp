#include"Suken.h"

BEZIER b;
CScene p,c;

void LoopP(){
	DxLib::DrawBox(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,WHITE,true);
}
void LoopC(){
	DxLib::DrawBox(150,100,WINDOW_WIDTH-100,WINDOW_HEIGHT-100,YELLOW,true);
}
void add(){
	p.addChild(&c);
}
void remove(){
	p.removeChild();
	//ErrorDx("Error->CMenu::Clear", __FILE__, __LINE__);
}




void Awake(){	


	

	vector<CVector> in ;
	in.push_back(VGet(0,0));
	in.push_back(VGet(0,200));
	in.push_back(VGet(400,400));
	in.push_back(VGet(200,0));
	
	
	b = GetBezier(in,100);

	p.SetButton(100,100,300,150,GREEN,"PRESS!",WHITE,add);
	c.SetButton(WINDOW_WIDTH-130,100,WINDOW_WIDTH-100,130,RED,"X",WHITE,remove);
	
	p.input.AddEventListener(Event.EVERY_FRAME,LoopP);
	c.input.AddEventListener(Event.EVERY_FRAME,LoopC);
	game.addChild(&p);
	
}

void GameLoopEnter(){
	//DrawBezier(b,WHITE);
	
	
}
void GameLoopExit(){

	if(Event.key.GetPressed(Event.key.SPACE)){
		DrawBox(10,10,200,200,BLACK,false);
	}
	
}

