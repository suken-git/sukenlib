#pragma once
//for CTransform
#include"../Transform.h"
//for Vector2D
#include"../Vector2D.h"
//for std::vector 
#include"Manager.h"

namespace suken{

class CRect{
public:
	CRect();
	suken::CTransform center;
	float direction;
	static const int figureType = SHAPE_RECT; 
	void Set(int sizeX,int sizeY);
	suken::Vector2D GetCenterPos();
	suken::Vector2D GetSize();
	float GetArea();
	suken::Vector2D GetRightTop();
	suken::Vector2D GetLeftTop();
	suken::Vector2D GetLeftBottom();
	suken::Vector2D GetRightBottom();
	void Draw(int color);
	void Loop();
	float GetRadius();
	void AddEventLisnerOnCollision(void (*pFunc)());
	void RemoveEventLisnerOnCollision(void (*pFunc)());
	void OnCollision();
private:
	vector<void(*)()> onCollisionTaskVoid;
	float rad;
	float radius;
	suken::Vector2D size;
};



}
