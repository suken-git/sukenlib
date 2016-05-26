#pragma once
#include "Primitive.h"

namespace suken{

class CRect :public suken::CPrimitive{
public:
/**
*	@brief ����
*/
	CRect();
	float direction;///<  @brief ����
	static const int figureType = SHAPE_RECT; ///<  @brief ����
/**
*	@brief ����
*	@param value ����
*/
	void Set(int sizeX,int sizeY);
/**
*	@brief ����
* @return �߂�l
*/
	suken::Vector2D GetCenterPos();
/**
*	@brief ����
* @return �߂�l
*/
	suken::Vector2D GetSize();
	/**
*	@brief ����
* @return �߂�l
*/
	float GetArea();
	/**
*	@brief ����
* @return �߂�l
*/
	suken::Vector2D GetRightTop();
	/**
*	@brief ����
* @return �߂�l
*/
	suken::Vector2D GetLeftTop();
	/**
*	@brief ����
* @return �߂�l
*/
	suken::Vector2D GetLeftBottom();
/**
*	@brief ����
* @return �߂�l
*/
	suken::Vector2D GetRightBottom();
/**
*	@brief ����
*	@param value ����
*/
	void Draw(int color);
	/**
*	@brief ����
*/
	void Loop();
	/**
*	@brief ����
* @return �߂�l
*/
	float GetRadius();
private:
	float rad;///<  @brief ����
	float radius;///<  @brief ����
	suken::Vector2D size;///<  @brief ����
};



}
