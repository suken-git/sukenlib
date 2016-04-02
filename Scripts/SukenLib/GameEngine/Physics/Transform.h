#pragma once
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
	float airResistance;
	suken::Vector2D gravity;
	void TransLate(suken::Vector2D _v);
	void Loop();
};

}