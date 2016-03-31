#include"Game.h"



CGame::CGame(){
	useDrawLoopFlag =true;
	rootScene.ResetSceneNum();
}
CGame::~CGame(){
/*
	if(memoryLeakChecker!=0){
		char info[256];
		sprintf(info,"error : %dŒ‚Ìƒƒ‚ƒŠƒŠ[ƒN‚ª”­¶‚µ‚Ä‚¢‚Ü‚·",memoryLeakChecker);
		MessageBox(NULL,info,"MemoryLeakChecher",MB_OK);
	}
	*/
	rootScene.SetFocus(true);
}
void awake(){

}
void CGame::AddChild(CScene* _scene){
		
	rootScene.SetFocus(false);

	_scene->SetFocus(true);
	sceneChild.push_back(_scene);

}
void CGame::RemoveChild(CScene* _scene){
	_scene->SetFocus(false);
	vector<CScene*>::iterator it=sceneChild.begin();

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
void CGame::RemoveChild(){
	sceneChild.front()->SetFocus(false);
	sceneChild.pop_back();
		
	if(sceneChild.empty()){
		rootScene.SetFocus(true);
	}
}
void CGame::Loop(){
	
		Event.Loop();
	
	if( !sceneChild.size() == 0 ){

		sceneChild.back()->Loop();

	}else{
			
		rootScene.Loop();

	}
}

	
void CGame::SetUseDrawLoop(bool flag){
	useDrawLoopFlag = flag;
}
bool CGame::GetUseDrawLoop(){
	return useDrawLoopFlag;
}