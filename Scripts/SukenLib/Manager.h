#pragma once

//#define DEBUG
#define DEBUG_DRAW
//#define USE_LUA  //Luaスクリプトを使うならコメントアウトを解除する
//そしてプロジェクト直下にlua5.1.dllを配置
//それでも動かないなら「C\lua」と「C\lua\include」が適切に配置されているかを確認する

//for system.h
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT= 600;

#ifdef USE_LUA
#include "lua.hpp"
#endif


//#define USE_GRAVITY

///グローバル宣言

/////Suken.h用


#define GRAVITY VGet( 0.0f , 0.0f )///<　@brief 説明


/**
*	@brief 説明
*/
void Awake();
/**
*	@brief 説明
*/
void GameLoopEnter();
/**
*	@brief 説明
*/
void GameLoopExit();