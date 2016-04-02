#pragma once
#include"../Transform.h"
class CPrimitive{
public:
CPrimitive(){

}
void AddEventLisnerOnCollision(void (*pFunc)());
void RemoveEventLisnerOnCollision(void (*pFunc)());
void OnCollisionFunc();
bool GetOnCollision();

suken::CTransform center;
private:
	bool onCollision;
	int figureType;

};