#pragma once
#include"../Transform.h"
namespace suken{	
///FIGURE TYPE
const int SHAPE_RECT	= 1;
const int SHAPE_CIRCLE	= 2;
class CPrimitive{
public:
	CPrimitive();
	void AddEventLisnerOnCollision(void (*pFunc)());
	void RemoveEventLisnerOnCollision(void (*pFunc)());
	void OnCollisionFunc();
	bool GetCollisionState();
	void SetCollisionState(bool flag);
	virtual void Loop();
	suken::CTransform center;
protected:
	std::vector<void(*)()> onCollisionTaskVoid;
	bool onCollision;
	int figureType;
};

}