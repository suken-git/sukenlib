#pragma once
#include"Vector2D.h"
namespace suken{

class CTransform{
public:
/**
*	@brief ����
*/
	CTransform();
	suken::Vector2D position;///<  @brief ����
	suken::Vector2D velocity;///<  @brief ����
	suken::Vector2D acceralate;///<  @brief ����

	suken::Vector2D prePosition;///<  @brief ����

	float rotation;///<  @brief ����
	float airResistance;///<  @brief ����
	suken::Vector2D gravity;///<  @brief ����
/**
*	@brief ����
*	@param value ����
*/
	void TransLate(suken::Vector2D _v);
/**
*	@brief ����
*/
	void Loop();
};

}