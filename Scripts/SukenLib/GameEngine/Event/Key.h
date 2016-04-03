#pragma once
#include "DxLib.h"
namespace suken{

class CKey{
public:
/**
*	@brief 説明
*/
	CKey(){}

	static const int BACK = KEY_INPUT_BACK	;///<  @brief 説明
    static const int TAB = KEY_INPUT_TAB	;///<  @brief 説明
    static const int RETURN = KEY_INPUT_RETURN	;///<  @brief 説明

    static const int LSHIFT = KEY_INPUT_LSHIFT	;///<  @brief 説明
    static const int RSHIFT = KEY_INPUT_RSHIFT	; ///<  @brief 説明
    static const int LCONTROL = KEY_INPUT_LCONTROL	;///<  @brief 説明
    static const int RCONTROL = KEY_INPUT_RCONTROL	; ///<  @brief 説明
    static const int ESCAPE = KEY_INPUT_ESCAPE	; ///<  @brief 説明
    static const int SPACE = KEY_INPUT_SPACE	; ///<  @brief 説明
    static const int PGUP = KEY_INPUT_PGUP	; ///<  @brief 説明
    static const int PGDN = KEY_INPUT_PGDN	;///<  @brief 説明
    static const int END = KEY_INPUT_END	; ///<  @brief 説明
    static const int HOME = KEY_INPUT_HOME	;///<  @brief 説明
    static const int LEFT = KEY_INPUT_LEFT	; ///<  @brief 説明
    static const int UP = KEY_INPUT_UP	; ///<  @brief 説明
    static const int RIGHT = KEY_INPUT_RIGHT	; ///<  @brief 説明
    static const int DOWN = KEY_INPUT_DOWN	; ///<  @brief 説明
    static const int INSERT = KEY_INPUT_INSERT	; ///<  @brief 説明
    static const int _DELETE = KEY_INPUT_DELETE	;///<  @brief 説明

    static const int MINUS = KEY_INPUT_MINUS	; ///<  @brief 説明
    static const int YEN = KEY_INPUT_YEN	; ///<  @brief 説明
    static const int PREVTRACK = KEY_INPUT_PREVTRACK	; ///<  @brief 説明
    static const int PERIOD = KEY_INPUT_PERIOD	;///<  @brief 説明
    static const int SLASH = KEY_INPUT_SLASH	;///<  @brief 説明
    static const int LALT = KEY_INPUT_LALT	;///<  @brief 説明
    static const int RALT = KEY_INPUT_RALT	; ///<  @brief 説明
    static const int SCROLL = KEY_INPUT_SCROLL	; ///<  @brief 説明
    static const int SEMICOLON = KEY_INPUT_SEMICOLON	;///<  @brief 説明
    static const int COLON = KEY_INPUT_COLON	; ///<  @brief 説明
    static const int LBRACKET = KEY_INPUT_LBRACKET	;///<  @brief 説明
    static const int RBRACKET = KEY_INPUT_RBRACKET	; ///<  @brief 説明
    static const int AT = KEY_INPUT_AT	; ///<  @brief 説明
    static const int BACKSLASH = KEY_INPUT_BACKSLASH	; ///<  @brief 説明
    static const int COMMA = KEY_INPUT_COMMA	; ///<  @brief 説明
    static const int CAPSLOCK = KEY_INPUT_CAPSLOCK	;///<  @brief 説明
    static const int PAUSE = KEY_INPUT_PAUSE	; ///<  @brief 説明

    static const int NUMPAD0 = KEY_INPUT_NUMPAD0	;///<  @brief 説明
    static const int NUMPAD1 = KEY_INPUT_NUMPAD1	; ///<  @brief 説明
    static const int NUMPAD2 = KEY_INPUT_NUMPAD2	; ///<  @brief 説明
    static const int NUMPAD3 = KEY_INPUT_NUMPAD3	; ///<  @brief 説明
    static const int NUMPAD4 = KEY_INPUT_NUMPAD4	; ///<  @brief 説明
    static const int NUMPAD5 = KEY_INPUT_NUMPAD5	; ///<  @brief 説明
    static const int NUMPAD6 = KEY_INPUT_NUMPAD6	; ///<  @brief 説明
    static const int NUMPAD7 = KEY_INPUT_NUMPAD7	; ///<  @brief 説明
    static const int NUMPAD8 = KEY_INPUT_NUMPAD8	; ///<  @brief 説明
    static const int NUMPAD9 = KEY_INPUT_NUMPAD9	; ///<  @brief 説明
    static const int MULTIPLY = KEY_INPUT_MULTIPLY	; ///<  @brief 説明
    static const int ADD = KEY_INPUT_ADD	; ///<  @brief 説明
    static const int SUBTRACT = KEY_INPUT_SUBTRACT	;///<  @brief 説明
    static const int DECIMAL = KEY_INPUT_DECIMAL	; ///<  @brief 説明
    static const int DIVIDE = KEY_INPUT_DIVIDE	; ///<  @brief 説明
    static const int NUMPADENTER = KEY_INPUT_NUMPADENTER	; ///<  @brief 説明

    static const int F1 = KEY_INPUT_F1	; ///<  @brief 説明
    static const int F2 = KEY_INPUT_F2	;///<  @brief 説明
    static const int F3 = KEY_INPUT_F3	; ///<  @brief 説明
    static const int F4 = KEY_INPUT_F4	; ///<  @brief 説明
    static const int F5 = KEY_INPUT_F5	; ///<  @brief 説明
    static const int F6 = KEY_INPUT_F6	; ///<  @brief 説明
    static const int F7 = KEY_INPUT_F7	;///<  @brief 説明
    static const int F8 = KEY_INPUT_F8	; ///<  @brief 説明
    static const int F9 = KEY_INPUT_F9	; ///<  @brief 説明
    static const int F10 = KEY_INPUT_F10	; ///<  @brief 説明
    static const int F11 = KEY_INPUT_F11	; ///<  @brief 説明
    static const int F12 = KEY_INPUT_F12	; ///<  @brief 説明

    static const int A = KEY_INPUT_A	;  ///<  @brief 説明
    static const int B = KEY_INPUT_B	;  ///<  @brief 説明
    static const int C = KEY_INPUT_C	;  ///<  @brief 説明
    static const int D = KEY_INPUT_D	;  ///<  @brief 説明
    static const int E = KEY_INPUT_E	;  ///<  @brief 説明
    static const int F = KEY_INPUT_F	;  ///<  @brief 説明
    static const int G = KEY_INPUT_G	;  ///<  @brief 説明
    static const int H = KEY_INPUT_H	;  ///<  @brief 説明
    static const int I = KEY_INPUT_I	;  ///<  @brief 説明
    static const int J = KEY_INPUT_J	;  ///<  @brief 説明
    static const int K = KEY_INPUT_K	;  ///<  @brief 説明
    static const int L = KEY_INPUT_L	;  ///<  @brief 説明
    static const int M = KEY_INPUT_M	; ///<  @brief 説明
    static const int N = KEY_INPUT_N	;  ///<  @brief 説明
    static const int O = KEY_INPUT_O	;  ///<  @brief 説明
    static const int P = KEY_INPUT_P	; ///<  @brief 説明
    static const int Q = KEY_INPUT_Q	;  ///<  @brief 説明
    static const int R = KEY_INPUT_R	;  ///<  @brief 説明
    static const int S = KEY_INPUT_S	;  ///<  @brief 説明
    static const int T = KEY_INPUT_T	;  ///<  @brief 説明
    static const int U = KEY_INPUT_U	;  ///<  @brief 説明
    static const int V = KEY_INPUT_V	;  ///<  @brief 説明
    static const int W = KEY_INPUT_W	;  ///<  @brief 説明
    static const int X = KEY_INPUT_X	;  ///<  @brief 説明
    static const int Y = KEY_INPUT_Y	;  ///<  @brief 説明
    static const int Z = KEY_INPUT_Z	;  ///<  @brief 説明
    static const int NUM0 = KEY_INPUT_0	;  ///<  @brief 説明
    static const int NUM1 = KEY_INPUT_1	;  ///<  @brief 説明
    static const int NUM2 = KEY_INPUT_2	;  ///<  @brief 説明
    static const int NUM3 = KEY_INPUT_3	;  ///<  @brief 説明
    static const int NUM4 = KEY_INPUT_4	;  ///<  @brief 説明
    static const int NUM5 = KEY_INPUT_5	;  ///<  @brief 説明
    static const int NUM6 = KEY_INPUT_6	;  ///<  @brief 説明
    static const int NUM7 = KEY_INPUT_7	;  ///<  @brief 説明
    static const int NUM8 = KEY_INPUT_8	;  ///<  @brief 説明
    static const int NUM9 = KEY_INPUT_9	; ///<  @brief 説明

/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetPush(int keyCode);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetDown(int keyCode);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	bool GetUp(int keyCode);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	int GetCount(int keyCode);
private:
	float count[256];///<  @brief 説明
};

}