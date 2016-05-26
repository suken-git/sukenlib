#pragma once
#include"Scene.h"
#include <vector>

namespace suken{

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
	std::vector<CScene*> sceneChild;///<  @brief ����
	CScene rootScene;///<  @brief ����
private:
	bool useDrawLoopFlag;///<  @brief ����
	
	
};


}
//Singleton
extern suken::CGame Game;///<  @brief ����



