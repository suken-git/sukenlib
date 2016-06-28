#pragma once
#include"../../Manager.h"
#include"Vector2D.h"
namespace suken{

class CTransform{
public:
/**
*	@brief ê‡ñæ
*/
	CTransform();
	suken::Vector2D position;///<  @brief ê‡ñæ
	suken::Vector2D velocity;///<  @brief ê‡ñæ
	suken::Vector2D acceralate;///<  @brief ê‡ñæ

	suken::Vector2D prePosition;///<  @brief ê‡ñæ

	float rotation;///<  @brief ê‡ñæ
	float airResistance;///<  @brief ê‡ñæ
	suken::Vector2D gravity;///<  @brief ê‡ñæ
/**
*	@brief ê‡ñæ
*	@param value à¯êî
*/
	void TransLate(suken::Vector2D _v);
/**
*	@brief ê‡ñæ
*/
	void Loop();
};

}