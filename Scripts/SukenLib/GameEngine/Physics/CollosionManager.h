#pragma once
#include"Primitive\Circle.h"
#include"Primitive\Rect.h"

///////////////////////////////////////////////////////////////////////
////////////独自のプリミティブ追加用インクルード ここから//////////////
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
////////////独自のプリミティブ追加用インクルード ここまで//////////////
///////////////////////////////////////////////////////////////////////

namespace suken{
const int INF		= 10000000;
class CCollisionManager{
public:
	CCollisionManager();
	~CCollisionManager();
	void Awake();
	void Loop();
	void DrawLoop();
	void CollisionCircleCalc(CCircle &A , CCircle &B ,float time);
	bool CollisionCircle(CCircle &A , CCircle &B );
	bool CollisionRect(suken::CRect &A , suken::CRect &B);
	void AddChild(CCircle *_circle , bool moveFlag);
	bool RemoveChild(CCircle *_circle);
	void AddChild(suken::CRect *_rect , bool moveFlag);
	bool RemoveChild(suken::CRect *_rect);
	std::vector<CCircle*> physicsCircle;
	std::vector<CCircle*> fixedCircle;
	std::vector<CRect*> fixedRect;
	std::vector<CRect*> physicsRect;
};


}