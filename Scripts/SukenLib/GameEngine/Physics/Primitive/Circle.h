#pragma once
#include"Primitive.h"


namespace suken{

class CCircle : public suken::CPrimitive {
public:
/**
*	@brief à–¾
*/
	CCircle();
//“Æ©
	float radius;
	float mass;
	float bound;
	bool IsKinematic;
	static const int figureType = SHAPE_CIRCLE; 
/**
*	@brief à–¾
* @return –ß‚è’l
*/
	suken::Vector2D GetCenterPos();
/**
*	@brief à–¾
* @return –ß‚è’l
*/
	float GetArea();
/**
*	@brief à–¾
*/
	void Loop();
/**
*	@brief à–¾
*	@param value ˆø”
*/
	void AddCollisionFalse(CCircle *c);
/**
*	@brief à–¾
*	@param value ˆø”
*/
	void RemoveCollisionFalse(CCircle *c);
/**
*	@brief à–¾
*	@param value ˆø”
* @return –ß‚è’l
*/
	bool GetIsNoCollision(CCircle *c);
private:
	std::vector<CCircle*> noCollision;
};

}