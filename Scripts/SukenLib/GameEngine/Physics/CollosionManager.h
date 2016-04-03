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
const int INF		= 10000000;///<  @brief 説明
class CCollisionManager{
public:
/**
*	@brief 説明
*/
	CCollisionManager();
/**
*	@brief 説明
*/
	~CCollisionManager();
/**
*	@brief 説明
*/
	void Awake();
/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*/
	void DrawLoop();
/**
*	@brief 説明
*	@param value 引数
*/
	void CollisionCircleCalc(CCircle &A , CCircle &B ,float time);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool CollisionCircle(CCircle &A , CCircle &B );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool CollisionRect(suken::CRect &A , suken::CRect &B);
/**
*	@brief 説明
*	@param value 引数
*/
	void AddChild(CCircle *_circle , bool moveFlag);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool RemoveChild(CCircle *_circle);
/**
*	@brief 説明
*	@param value 引数
*/
	void AddChild(suken::CRect *_rect , bool moveFlag);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool RemoveChild(suken::CRect *_rect);

	std::vector<CCircle*> physicsCircle;///<  @brief 説明
	std::vector<CCircle*> fixedCircle;///<  @brief 説明
	std::vector<CRect*> fixedRect;///<  @brief 説明
	std::vector<CRect*> physicsRect;///<  @brief 説明
};


}