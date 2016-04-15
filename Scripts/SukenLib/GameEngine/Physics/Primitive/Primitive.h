#pragma once
#include"Manager.h"
#include"../Transform.h"
namespace suken{	
///FIGURE TYPE
const int SHAPE_RECT	= 1;///<  @brief 説明
const int SHAPE_CIRCLE	= 2;///<  @brief 説明
class CPrimitive{
public:
/**
*	@brief 説明
*/
	CPrimitive();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	void AddEventLisnerOnCollision(void (*pFunc)());
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	void RemoveEventLisnerOnCollision(void (*pFunc)());
/**
*	@brief 説明
*/
	void OnCollisionFunc();
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetCollisionState();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	void SetCollisionState(bool flag);
/**
*	@brief 説明
*/
	virtual void Loop();
	suken::CTransform center;///<  @brief 説明
protected:
	std::vector<void(*)()> onCollisionTaskVoid;///<  @brief 説明
	bool onCollision;///<  @brief 説明
	int figureType;///<  @brief 説明
};

}