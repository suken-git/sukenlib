#pragma once

#define DEBUG
#define DEBUG_DRAW
//#define SCENE_TRANSITION_ANIMATION
//#define USE_LUA  //Luaスクリプトを使うならコメントアウトを解除する
//そしてプロジェクト直下にlua5.1.dllを配置
//それでも動かないなら「C\lua」と「C\lua\include」が適切に配置されているかを確認する

//
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 600;

#ifdef USE_LUA
#include "lua.hpp"
#endif


//#define USE_GRAVITY



#define GRAVITY VGet( 0.0f , 0.0f )///<  @brief 説明

namespace suken {
	/**
	*	@brief exe実行時、始めに一度だけ実行される関数
	*
	*/
	void Awake();
	/**
	*	@brief ボタン描画などの数研ライブラリのシステム描画より先に実行される関数。
	*　シーンとは関係なく常に実行されるので主にデバッグ用に使う
	*/
	void GameLoopEnter();
	/**
	*	@brief ボタン描画などの数研ライブラリのシステム描画のあとに実行される関数。
	*　シーンとは関係なく常に実行されるので主にデバッグ用に使う。
	*　ここに記述した描画処理は常に一番手前に描画されるため、デバッグ描画におすすめ。
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

	//Windows

		//Midi.h



}

