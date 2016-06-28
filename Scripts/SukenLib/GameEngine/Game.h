#pragma once
#include"../Manager.h"
#include"Scene.h"
#include <vector>
#include<queue>

namespace suken{
	enum SCENE_OPERATION_COMMAND{ADD,REMOVE};
	enum TRANSITION_ANIMATION_MODE {NONE,ZOOM_OUT,SCROLL_TO_REMOVE,REMOVING,ADDING,SCROLL_TO_ADD,SCROLL,ZOOM_UP};
//ゲームシステム総括クラス
class CGame{
public:
/**
*	@brief 説明
*/
	CGame();
/**
*	@brief 説明
*/
	~CGame();
/**
*	@brief 説明
*/
	void Awake();
/**
*	@brief 説明
*	@param value 引数
*/
	void AddChild(CScene* _scene);
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveChild(CScene* _scene);
/**
*	@brief 説明
*/
	void RemoveChild();
/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*	@param value 引数
*/
	void SetUseDrawLoop(bool flag);
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetUseDrawLoop();
/**
*	@brief 説明
* @return 戻り値
*/
	CScene *GetCurrentScene();
/**
*	@brief commandQueueに積まれたシーン操作コマンドを実行
*/
	void ExecuteCommand();
/**
*	@brief commandQueueに積まれたシーン操作コマンドを実行
*/
	
	CScene rootScene;///<  @brief 説明

private:
	std::vector<CScene*> sceneChild;///<  @brief 説明
	bool useDrawLoopFlag;///<  @brief 説明
	std::queue<std::pair<SCENE_OPERATION_COMMAND, CScene*>> commandQueue;
#ifdef SCENE_TRANSITION_ANIMATION
	bool IsSceneTransition;
	//std::queue<std::pair<SCENE_OPERATION_COMMAND, CScene*>> commandQueueforTransitionAnimation;
	//CScene sceneTransition;
	int transAnimCount;
	int transAnimScroll;
	int transAnimScrollTarget;
	TRANSITION_ANIMATION_MODE mode;
	void DrawSceneTransAnim(int sceneNum,float num, int yDelta = 0, suken::CScene *scene = nullptr);
#endif
	
};


}
//Singleton
extern suken::CGame Game;///<  @brief 説明



