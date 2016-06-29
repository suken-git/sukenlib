#pragma once
#include"../../Manager.h"
#include"Key.h"
#include"Mouse.h"

namespace suken{
const char FRAME_EVENT	=	'E';


//���̓C�x���g��`�N���X
class CEvent{
public:
/**
*	@brief ����
*/
	CEvent();
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*/
	void Activate();
/**
*	@brief ����
*/
	void Deactivate();
/**
*	@brief ����
* @return �߂�l
*/
	bool GetValid();///<  @brief ����
	char EVERY_FRAME;///<  @brief ����
	CKey key;///<  @brief ����
	CMouse LMouse;///<  @brief ����
	CMouse RMouse;///<  @brief ����
private:
	bool IsActivated;///<  @brief ����
};

}

extern suken::CEvent Event;

