#pragma once
#include"Primitive.h"
#include"../Transform.h"


namespace suken{

class CCircle : public CPrimitive {
public:
	CCircle();
	suken::CTransform center;
	float radius;
	float mass;
	float bound;
	bool IsKinematic;
	bool onCollision;
	static const int figureType = SHAPE_CIRCLE; 
	suken::Vector2D GetCenterPos();
	float GetArea();
	void Loop();
	void AddEventLisnerOnCollision(void (*pFunc)());
	void RemoveEventLisnerOnCollision(void (*pFunc)());
	void OnCollisionFunc();
	void AddCollisionFalse(CCircle *c);
	void RemoveCollisionFalse(CCircle *c);
	bool GetIsNoCollision(CCircle *c);
private:
	vector<void(*)()> onCollisionTaskVoid;
	vector<CCircle*> noCollision;
};

}