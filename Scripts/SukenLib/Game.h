#pragma once
#include"Manager.h"
#include"Scene.h"


//ゲームシステム総括クラス
class CGame{
public:
	CGame();
	~CGame();
	void Awake();
	void AddChild(CScene* _scene);
	void RemoveChild(CScene* _scene);
	void RemoveChild();
	void Loop();

	void SetUseDrawLoop(bool flag);
	bool GetUseDrawLoop();
	vector<CScene*> sceneChild;
	CScene rootScene;
private:
	bool useDrawLoopFlag;
	
	
};