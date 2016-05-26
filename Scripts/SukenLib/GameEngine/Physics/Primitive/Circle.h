#pragma once
#include"Primitive.h"


namespace suken{

class CCircle : public suken::CPrimitive {
public:
/**
*	@brief ����
*/
	CCircle();
//�Ǝ�
	float radius;///<  @brief ����
	float mass;///<  @brief ����
	float bound;///<  @brief ����
	bool IsKinematic;///<  @brief ����
	static const int figureType = SHAPE_CIRCLE; ///<  @brief ����
/**
*	@brief ����
* @return �߂�l
*/
	suken::Vector2D GetCenterPos();
/**
*	@brief ����
* @return �߂�l
*/
	float GetArea();
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*	@param value ����
*/
	void AddCollisionFalse(CCircle *c);
/**
*	@brief ����
*	@param value ����
*/
	void RemoveCollisionFalse(CCircle *c);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetIsNoCollision(CCircle *c);
private:
	std::vector<CCircle*> noCollision;///<  @brief ����
};

}