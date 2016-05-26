#pragma once
#include"Primitive.h"


namespace suken{

class CCircle : public suken::CPrimitive {
public:
/**
*	@brief ê‡ñæ
*/
	CCircle();
//ì∆é©
	float radius;///<  @brief ê‡ñæ
	float mass;///<  @brief ê‡ñæ
	float bound;///<  @brief ê‡ñæ
	bool IsKinematic;///<  @brief ê‡ñæ
	static const int figureType = SHAPE_CIRCLE; ///<  @brief ê‡ñæ
/**
*	@brief ê‡ñæ
* @return ñﬂÇËíl
*/
	suken::Vector2D GetCenterPos();
/**
*	@brief ê‡ñæ
* @return ñﬂÇËíl
*/
	float GetArea();
/**
*	@brief ê‡ñæ
*/
	void Loop();
/**
*	@brief ê‡ñæ
*	@param value à¯êî
*/
	void AddCollisionFalse(CCircle *c);
/**
*	@brief ê‡ñæ
*	@param value à¯êî
*/
	void RemoveCollisionFalse(CCircle *c);
/**
*	@brief ê‡ñæ
*	@param value à¯êî
* @return ñﬂÇËíl
*/
	bool GetIsNoCollision(CCircle *c);
private:
	std::vector<CCircle*> noCollision;///<  @brief ê‡ñæ
};

}