#pragma once
#include"EventData.h"

namespace suken{
const int MOUSE_OFF		=	10;///<  @brief ����
const int MOUSE_ON		=	11;///<  @brief ����
const int MOUSE_PUSH	=	12;///<  @brief ����
const int MOUSE_CLICK	=	13;///<  @brief ����
const int MOUSE_RELEASE =	14;///<  @brief ����


//�}�E�X��`�N���X
class CMouse{
public:
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CMouseIn Off( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
* @return �߂�l
*/
	bool GetOff();
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetOff( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CpMouseIn Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CMouseIn On( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
* @return �߂�l
*/
	bool GetOn();
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetOn( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CpMouseIn On( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CMouseIn Click( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
* @return �߂�l
*/
	bool GetClick();
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetClick( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CpMouseIn Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CMouseIn Release( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
* @return �߂�l
*/
	bool GetRelease();
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetRelease( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	CpMouseIn Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*/
	void SetLeft();
/**
*	@brief ����
*/
	void SetRight();
/**
*	@brief ����
* @return �߂�l
*/
	int GetX();
/**
*	@brief ����
* @return �߂�l
*/
	int GetY();
/**
*	@brief ����
* @return �߂�l
*/
	bool GetInput();
/**
*	@brief ����
* @return �߂�l
*/
	bool GetPreInput();
	
	
private:
	int mouseX;///<  @brief ���݂̃}�E�X�̂����W
	int mouseY;///<  @brief ���݂̃}�E�X�̂����W
	bool mouseInput;///<  @brief ���t���[���̃}�E�X���̗͂L��
	bool preMouseInput;///<  @brief �O�t���[���̃}�E�X���̗͂L��
	bool IsLeft;///<  @brief �S������}�E�X�{�^���������ǂ��� true:���@false:�E
};


}

