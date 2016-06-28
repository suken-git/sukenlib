#pragma once
#include"../Manager.h"
#include"Scene.h"
#include <vector>
#include<queue>

namespace suken{
	enum SCENE_OPERATION_COMMAND{ADD,REMOVE};
	enum TRANSITION_ANIMATION_MODE {NONE,ZOOM_OUT,SCROLL_TO_REMOVE,REMOVING,ADDING,SCROLL_TO_ADD,SCROLL,ZOOM_UP};
//�Q�[���V�X�e�������N���X
class CGame{
public:
/**
*	@brief ����
*/
	CGame();
/**
*	@brief ����
*/
	~CGame();
/**
*	@brief ����
*/
	void Awake();
/**
*	@brief ����
*	@param value ����
*/
	void AddChild(CScene* _scene);
/**
*	@brief ����
*	@param value ����
*/
	void RemoveChild(CScene* _scene);
/**
*	@brief ����
*/
	void RemoveChild();
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*	@param value ����
*/
	void SetUseDrawLoop(bool flag);
/**
*	@brief ����
* @return �߂�l
*/
	bool GetUseDrawLoop();
/**
*	@brief ����
* @return �߂�l
*/
	CScene *GetCurrentScene();
/**
*	@brief commandQueue�ɐς܂ꂽ�V�[������R�}���h�����s
*/
	void ExecuteCommand();
/**
*	@brief commandQueue�ɐς܂ꂽ�V�[������R�}���h�����s
*/
	
	CScene rootScene;///<  @brief ����

private:
	std::vector<CScene*> sceneChild;///<  @brief ����
	bool useDrawLoopFlag;///<  @brief ����
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
extern suken::CGame Game;///<  @brief ����



