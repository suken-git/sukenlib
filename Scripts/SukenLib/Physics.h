#pragma once
#include"Manager.h"
#include"Vector2D.h"

namespace suken{


class CTransform{
public:
	CTransform();
	suken::Vector2D position;
	suken::Vector2D velocity;
	suken::Vector2D acceralate;

	suken::Vector2D prePosition;

	float rotation;
	/*static*/ float airResistance;
	/*static*/ suken::Vector2D gravity;
	void TransLate(suken::Vector2D _v);
	void Loop();
};

class CRect{
public:
	CRect();
	CTransform	center;
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
class CCircle{
public:
	CCircle();
	CTransform center;
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

class CCollisionManager{
public:
	CCollisionManager();
	~CCollisionManager();
	void Awake();
	void Loop();
	void DrawLoop();
	void CollisionCircleCalc(CCircle &A , CCircle &B ,float time);
	bool CollisionCircle(CCircle &A , CCircle &B );
	bool CollisionRect(CRect &A , CRect &B);
	void AddChild(CCircle *_circle , bool moveFlag);
	bool RemoveChild(CCircle *_circle);
	void AddChild(CRect *_rect , bool moveFlag);
	bool RemoveChild(CRect *_rect);
	vector<CCircle*> physicsCircle;
	vector<CCircle*> fixedCircle;
	vector<CRect*> fixedRect;
	vector<CRect*> physicsRect;
};


}