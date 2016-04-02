#pragma once
//for CKey
#include"Key.h"
//for CMouse
#include"Mouse.h"

namespace suken{


//入力イベント定義クラス
class CEvent{
public:
	CEvent();
	void Loop();
	void Activate();
	void Deactivate();
	bool GetValid();
	char EVERY_FRAME;
	CKey key;
	CMouse LMouse;
	CMouse RMouse;
private:
	bool IsActivated;
};

}

extern suken::CEvent Event;
