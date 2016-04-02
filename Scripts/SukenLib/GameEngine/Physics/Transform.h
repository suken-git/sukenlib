#pragma once
#include"Vector2D.h"
namespace suken{

class CTransform{
public:
/**
*	@brief 説明
*/
	CTransform();
	suken::Vector2D position;///<　@brief 説明
	suken::Vector2D velocity;///<　@brief 説明
	suken::Vector2D acceralate;///<　@brief 説明

	suken::Vector2D prePosition;///<　@brief 説明

	float rotation;///<　@brief 説明
	float airResistance;///<　@brief 説明
	suken::Vector2D gravity;///<　@brief 説明
/**
*	@brief 説明
*	@param value 引数
*/
	void TransLate(suken::Vector2D _v);
/**
*	@brief 説明
*/
	void Loop();
};

}