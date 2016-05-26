#pragma once
#include"Primitive\Circle.h"
#include"Primitive\Rect.h"

///////////////////////////////////////////////////////////////////////
////////////�Ǝ��̃v���~�e�B�u�ǉ��p�C���N���[�h ��������//////////////
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
////////////�Ǝ��̃v���~�e�B�u�ǉ��p�C���N���[�h �����܂�//////////////
///////////////////////////////////////////////////////////////////////

namespace suken{
const int INF		= 10000000;///<  @brief ����
class CCollisionManager{
public:
/**
*	@brief ����
*/
	CCollisionManager();
/**
*	@brief ����
*/
	~CCollisionManager();
/**
*	@brief ����
*/
	void Awake();
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*/
	void DrawLoop();
/**
*	@brief ����
*	@param value ����
*/
	void CollisionCircleCalc(CCircle &A , CCircle &B ,float time);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool CollisionCircle(CCircle &A , CCircle &B );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool CollisionRect(suken::CRect &A , suken::CRect &B);
/**
*	@brief ����
*	@param value ����
*/
	void AddChild(CCircle *_circle , bool moveFlag);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool RemoveChild(CCircle *_circle);
/**
*	@brief ����
*	@param value ����
*/
	void AddChild(suken::CRect *_rect , bool moveFlag);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool RemoveChild(suken::CRect *_rect);

	std::vector<CCircle*> physicsCircle;///<  @brief ����
	std::vector<CCircle*> fixedCircle;///<  @brief ����
	std::vector<CRect*> fixedRect;///<  @brief ����
	std::vector<CRect*> physicsRect;///<  @brief ����
};


}