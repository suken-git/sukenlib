#pragma once
#include"../../Manager.h"
#include"Key.h"
#include"Mouse.h"

namespace suken{
const char FRAME_EVENT	=	'E';


//入力イベント定義クラス
class CEvent{
public:
/**
*	@brief 説明
*/
	CEvent();
/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*/
	void Activate();
/**
*	@brief 説明
*/
	void Deactivate();
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetValid();///<  @brief 説明
	char EVERY_FRAME;///<  @brief 説明
	CKey key;///<  @brief 説明
	CMouse LMouse;///<  @brief 説明
	CMouse RMouse;///<  @brief 説明
private:
	bool IsActivated;///<  @brief 説明
};

}

extern suken::CEvent Event;

