#pragma once
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

	CMouseIn Off( int _x1 , int _y1 , int _x2 , int _y2 );
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
*	@param value 引数
* @return 戻り値
*/
	void Loop();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	void SetLeft();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	void SetRight();

	int mouseX;///<  @brief 説明
	int mouseY;///<  @brief 説明
	bool mouseInput;///<  @brief 説明
	bool preMouseInput;///<  @brief 説明
	
private:
	bool IsLeft;///<  @brief 説明
};


}

