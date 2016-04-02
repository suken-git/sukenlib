#pragma once
#include "Primitive.h"

namespace suken{

class CRect :public suken::CPrimitive{
public:
/**
*	@brief 説明
*/
	CRect();
	float direction;
	static const int figureType = SHAPE_RECT; 
/**
*	@brief 説明
*	@param value 引数
*/
	void Set(int sizeX,int sizeY);
/**
*	@brief 説明
* @return 戻り値
*/
	suken::Vector2D GetCenterPos();
/**
*	@brief 説明
* @return 戻り値
*/
	suken::Vector2D GetSize();
	/**
*	@brief 説明
* @return 戻り値
*/
	float GetArea();
	/**
*	@brief 説明
* @return 戻り値
*/
	suken::Vector2D GetRightTop();
	/**
*	@brief 説明
* @return 戻り値
*/
	suken::Vector2D GetLeftTop();
	/**
*	@brief 説明
* @return 戻り値
*/
	suken::Vector2D GetLeftBottom();
/**
*	@brief 説明
* @return 戻り値
*/
	suken::Vector2D GetRightBottom();
/**
*	@brief 説明
*	@param value 引数
*/
	void Draw(int color);
	/**
*	@brief 説明
*/
	void Loop();
	/**
*	@brief 説明
* @return 戻り値
*/
	float GetRadius();
private:
	float rad;
	float radius;
	suken::Vector2D size;
};



}
