#pragma once
#include"Manager.h"
#include"../Transform.h"
namespace suken{	
///FIGURE TYPE
const int SHAPE_RECT	= 1;///<  @brief ����
const int SHAPE_CIRCLE	= 2;///<  @brief ����
class CPrimitive{
public:
/**
*	@brief ����
*/
	CPrimitive();
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	void AddEventLisnerOnCollision(void (*pFunc)());
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	void RemoveEventLisnerOnCollision(void (*pFunc)());
/**
*	@brief ����
*/
	void OnCollisionFunc();
/**
*	@brief ����
* @return �߂�l
*/
	bool GetCollisionState();
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	void SetCollisionState(bool flag);
/**
*	@brief ����
*/
	virtual void Loop();
	suken::CTransform center;///<  @brief ����
protected:
	std::vector<void(*)()> onCollisionTaskVoid;///<  @brief ����
	bool onCollision;///<  @brief ����
	int figureType;///<  @brief ����
};

}