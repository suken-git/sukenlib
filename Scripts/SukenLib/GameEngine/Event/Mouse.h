#pragma once
#include"../../Manager.h"
#include"EventData.h"

namespace suken{
const int MOUSE_OFF		=	10;///<  @brief 説明
const int MOUSE_ON		=	11;///<  @brief 説明
const int MOUSE_PUSH	=	12;///<  @brief 説明
const int MOUSE_CLICK	=	13;///<  @brief 説明
const int MOUSE_RELEASE =	14;///<  @brief 説明


//マウス定義クラス
class CMouse{
public:
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CMouseIn Off( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetOff();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetOff( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CpMouseIn Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CMouseIn On( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetOn();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetOn( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CpMouseIn On( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CMouseIn Click( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetClick();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetClick( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CpMouseIn Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CMouseIn Release( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetRelease();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetRelease( int _x1 , int _y1 , int _x2 , int _y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	CpMouseIn Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*/
	void SetLeft();
/**
*	@brief 説明
*/
	void SetRight();
/**
*	@brief 説明
* @return 戻り値
*/
	int GetX();
/**
*	@brief 説明
* @return 戻り値
*/
	int GetY();
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetInput();
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetPreInput();
	
	
private:
	int mouseX;///<  @brief 現在のマウスのｘ座標
	int mouseY;///<  @brief 現在のマウスのｙ座標
	bool mouseInput;///<  @brief 現フレームのマウス入力の有無
	bool preMouseInput;///<  @brief 前フレームのマウス入力の有無
	bool IsLeft;///<  @brief 担当するマウスボタンが左かどうか true:左　false:右
};


}

