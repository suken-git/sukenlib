#include"Game.h"
//Singleton
suken::CGame Game;

suken::CGame::CGame(){
	useDrawLoopFlag =true;
	rootScene.ResetSceneNum();
}
suken::CGame::~CGame(){
/*
	if(memoryLeakChecker!=0){
		char info[256];
		sprintf(info,"error : %dŒ‚Ìƒƒ‚ƒŠƒŠ[ƒN‚ª”­¶‚µ‚Ä‚¢‚Ü‚·",memoryLeakChecker);
		MessageBox(nullptr,info,"MemoryLeakChecher",MB_OK);
	}
	*/
	rootScene.SetFocus(true);
}
void awake(){

}
void suken::CGame::AddChild(CScene* _scene){
		
	rootScene.SetFocus(false);

	_scene->SetFocus(true);
	sceneChild.push_back(_scene);

}
void suken::CGame::RemoveChild(CScene* _scene){
	_scene->SetFocus(false);
	std::vector<CScene*>::iterator it=sceneChild.begin();

	while( it != sceneChild.end() ) {
		if(*it==_scene){
			
			sceneChild.erase(it);
			break;
		}
		it++;
	}

	if(sceneChild.empty()){
		rootScene.SetFocus(true);
	}
}
void suken::CGame::RemoveChild(){
	sceneChild.front()->SetFocus(false);
	sceneChild.pop_back();
		
	if(sceneChild.empty()){
		rootScene.SetFocus(true);
	}
}
void suken::CGame::Loop(){
	
		Event.Loop();
	
	if( !sceneChild.size() == 0 ){

		sceneChild.back()->Loop();

	}else{
			
		rootScene.Loop();

	}
}

	
void suken::CGame::SetUseDrawLoop(bool flag){
	useDrawLoopFlag = flag;
}
bool suken::CGame::GetUseDrawLoop(){
	return useDrawLoopFlag;
}