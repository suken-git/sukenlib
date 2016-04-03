#pragma once
#include"Scene.h"
#include <vector>

namespace suken{

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
	std::vector<CScene*> sceneChild;///<  @brief 説明
	CScene rootScene;///<  @brief 説明
private:
	bool useDrawLoopFlag;///<  @brief 説明
	
	
};


}
//Singleton
extern suken::CGame Game;///<  @brief 説明



