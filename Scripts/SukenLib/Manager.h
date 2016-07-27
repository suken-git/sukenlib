#pragma once

#define DEBUG
#define DEBUG_DRAW
//#define SCENE_TRANSITION_ANIMATION
//#define USE_LUA  //Lua�X�N���v�g���g���Ȃ�R�����g�A�E�g����������
//�����ăv���W�F�N�g������lua5.1.dll��z�u
//����ł������Ȃ��Ȃ�uC\lua�v�ƁuC\lua\include�v���K�؂ɔz�u����Ă��邩���m�F����

//
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 600;

#ifdef USE_LUA
#include "lua.hpp"
#endif


//#define USE_GRAVITY



#define GRAVITY VGet( 0.0f , 0.0f )///<  @brief ����

namespace suken {
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

	//SukenLib

		//Manager.h(this)

		//GameEngine

			//Game.h
	class CGame;
	//Scene.h
	class CButton;
	class CpButton;
	class CScene;

	//Event

		//Event.h
	class CEvent;
	//EventData.h
	class CKeyIn;
	class CMouseIn;
	class CpMouseIn;
	class CKeyBoolIn;
	class CMouseBoolIn;
	class CpMouseBoolIn;
	class CFrame;
	class CBoolean;
	//Input.h
	class CInput;
	//Key.h
	class CKey;
	//KeyInputString.h
	class CKeyInputString;
	//Mouse.h
	class CMouse;

	//Physics

		//CollisionManager.h
			class CCollisionManager;
		//Transform.h
				class CTransform;
			//Vector2D.h
				class Vector2D;

	//Primitive

		//Circle.h
			class CCircle;
		//Primitive.h
			class CPrimitive;
		//Rect.h
			class CRect;

	//System

		//System.h
			class CSystem;

	//Utillity

		//Array.h
			template<typename T>
			class CArray;
		//Data.h
			class CData;
		//Debug.h
			class CDebugWndow;
		//Utillity.h

		//MCE.h
			class CMCE;

	//Windows

		//Midi.h



}

