#pragma once
#include"../Transform.h"
namespace suken{
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
	vector<void(*)()> onCollisionTaskVoid;
	bool onCollision;
	int figureType;

};

}