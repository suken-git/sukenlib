#pragma once

#define DEBUG
#define DEBUG_DRAW
//#define USE_LUA  //Lua�X�N���v�g���g���Ȃ�R�����g�A�E�g����������
//�����ăv���W�F�N�g������lua5.1.dll��z�u
//����ł������Ȃ��Ȃ�uC\lua�v�ƁuC\lua\include�v���K�؂ɔz�u����Ă��邩���m�F����

//for system.h
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT= 600;

#ifdef USE_LUA
#include "lua.hpp"
#endif


//#define USE_GRAVITY

///�O���[�o���錾

/////Suken.h�p


#define GRAVITY VGet( 0.0f , 0.0f )///<  @brief ����


/**
*	@brief exe���s���A�n�߂Ɉ�x�������s�����֐�
*	
*/
void Awake();
/**
*	@brief �{�^���`��Ȃǂ̐������C�u�����̃V�X�e���`�����Ɏ��s�����֐��B
*�@�V�[���Ƃ͊֌W�Ȃ���Ɏ��s�����̂Ŏ�Ƀf�o�b�O�p�Ɏg��
*/
void GameLoopEnter();
/**
*	@brief �{�^���`��Ȃǂ̐������C�u�����̃V�X�e���`��̂��ƂɎ��s�����֐��B
*�@�V�[���Ƃ͊֌W�Ȃ���Ɏ��s�����̂Ŏ�Ƀf�o�b�O�p�Ɏg���B
*�@�����ɋL�q�����`�揈���͏�Ɉ�Ԏ�O�ɕ`�悳��邽�߁A�f�o�b�O�`��ɂ������߁B
*/
void GameLoopExit();