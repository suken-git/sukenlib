#pragma once
#include "DxLib.h"
namespace suken{

class CKey{
public:
/**
*	@brief ����
*/
	CKey(){}

	static const int BACK = KEY_INPUT_BACK	;///<  @brief ����
    static const int TAB = KEY_INPUT_TAB	;///<  @brief ����
    static const int RETURN = KEY_INPUT_RETURN	;///<  @brief ����

    static const int LSHIFT = KEY_INPUT_LSHIFT	;///<  @brief ����
    static const int RSHIFT = KEY_INPUT_RSHIFT	; ///<  @brief ����
    static const int LCONTROL = KEY_INPUT_LCONTROL	;///<  @brief ����
    static const int RCONTROL = KEY_INPUT_RCONTROL	; ///<  @brief ����
    static const int ESCAPE = KEY_INPUT_ESCAPE	; ///<  @brief ����
    static const int SPACE = KEY_INPUT_SPACE	; ///<  @brief ����
    static const int PGUP = KEY_INPUT_PGUP	; ///<  @brief ����
    static const int PGDN = KEY_INPUT_PGDN	;///<  @brief ����
    static const int END = KEY_INPUT_END	; ///<  @brief ����
    static const int HOME = KEY_INPUT_HOME	;///<  @brief ����
    static const int LEFT = KEY_INPUT_LEFT	; ///<  @brief ����
    static const int UP = KEY_INPUT_UP	; ///<  @brief ����
    static const int RIGHT = KEY_INPUT_RIGHT	; ///<  @brief ����
    static const int DOWN = KEY_INPUT_DOWN	; ///<  @brief ����
    static const int INSERT = KEY_INPUT_INSERT	; ///<  @brief ����
    static const int _DELETE = KEY_INPUT_DELETE	;///<  @brief ����

    static const int MINUS = KEY_INPUT_MINUS	; ///<  @brief ����
    static const int YEN = KEY_INPUT_YEN	; ///<  @brief ����
    static const int PREVTRACK = KEY_INPUT_PREVTRACK	; ///<  @brief ����
    static const int PERIOD = KEY_INPUT_PERIOD	;///<  @brief ����
    static const int SLASH = KEY_INPUT_SLASH	;///<  @brief ����
    static const int LALT = KEY_INPUT_LALT	;///<  @brief ����
    static const int RALT = KEY_INPUT_RALT	; ///<  @brief ����
    static const int SCROLL = KEY_INPUT_SCROLL	; ///<  @brief ����
    static const int SEMICOLON = KEY_INPUT_SEMICOLON	;///<  @brief ����
    static const int COLON = KEY_INPUT_COLON	; ///<  @brief ����
    static const int LBRACKET = KEY_INPUT_LBRACKET	;///<  @brief ����
    static const int RBRACKET = KEY_INPUT_RBRACKET	; ///<  @brief ����
    static const int AT = KEY_INPUT_AT	; ///<  @brief ����
    static const int BACKSLASH = KEY_INPUT_BACKSLASH	; ///<  @brief ����
    static const int COMMA = KEY_INPUT_COMMA	; ///<  @brief ����
    static const int CAPSLOCK = KEY_INPUT_CAPSLOCK	;///<  @brief ����
    static const int PAUSE = KEY_INPUT_PAUSE	; ///<  @brief ����

    static const int NUMPAD0 = KEY_INPUT_NUMPAD0	;///<  @brief ����
    static const int NUMPAD1 = KEY_INPUT_NUMPAD1	; ///<  @brief ����
    static const int NUMPAD2 = KEY_INPUT_NUMPAD2	; ///<  @brief ����
    static const int NUMPAD3 = KEY_INPUT_NUMPAD3	; ///<  @brief ����
    static const int NUMPAD4 = KEY_INPUT_NUMPAD4	; ///<  @brief ����
    static const int NUMPAD5 = KEY_INPUT_NUMPAD5	; ///<  @brief ����
    static const int NUMPAD6 = KEY_INPUT_NUMPAD6	; ///<  @brief ����
    static const int NUMPAD7 = KEY_INPUT_NUMPAD7	; ///<  @brief ����
    static const int NUMPAD8 = KEY_INPUT_NUMPAD8	; ///<  @brief ����
    static const int NUMPAD9 = KEY_INPUT_NUMPAD9	; ///<  @brief ����
    static const int MULTIPLY = KEY_INPUT_MULTIPLY	; ///<  @brief ����
    static const int ADD = KEY_INPUT_ADD	; ///<  @brief ����
    static const int SUBTRACT = KEY_INPUT_SUBTRACT	;///<  @brief ����
    static const int DECIMAL = KEY_INPUT_DECIMAL	; ///<  @brief ����
    static const int DIVIDE = KEY_INPUT_DIVIDE	; ///<  @brief ����
    static const int NUMPADENTER = KEY_INPUT_NUMPADENTER	; ///<  @brief ����

    static const int F1 = KEY_INPUT_F1	; ///<  @brief ����
    static const int F2 = KEY_INPUT_F2	;///<  @brief ����
    static const int F3 = KEY_INPUT_F3	; ///<  @brief ����
    static const int F4 = KEY_INPUT_F4	; ///<  @brief ����
    static const int F5 = KEY_INPUT_F5	; ///<  @brief ����
    static const int F6 = KEY_INPUT_F6	; ///<  @brief ����
    static const int F7 = KEY_INPUT_F7	;///<  @brief ����
    static const int F8 = KEY_INPUT_F8	; ///<  @brief ����
    static const int F9 = KEY_INPUT_F9	; ///<  @brief ����
    static const int F10 = KEY_INPUT_F10	; ///<  @brief ����
    static const int F11 = KEY_INPUT_F11	; ///<  @brief ����
    static const int F12 = KEY_INPUT_F12	; ///<  @brief ����

    static const int A = KEY_INPUT_A	;  ///<  @brief ����
    static const int B = KEY_INPUT_B	;  ///<  @brief ����
    static const int C = KEY_INPUT_C	;  ///<  @brief ����
    static const int D = KEY_INPUT_D	;  ///<  @brief ����
    static const int E = KEY_INPUT_E	;  ///<  @brief ����
    static const int F = KEY_INPUT_F	;  ///<  @brief ����
    static const int G = KEY_INPUT_G	;  ///<  @brief ����
    static const int H = KEY_INPUT_H	;  ///<  @brief ����
    static const int I = KEY_INPUT_I	;  ///<  @brief ����
    static const int J = KEY_INPUT_J	;  ///<  @brief ����
    static const int K = KEY_INPUT_K	;  ///<  @brief ����
    static const int L = KEY_INPUT_L	;  ///<  @brief ����
    static const int M = KEY_INPUT_M	; ///<  @brief ����
    static const int N = KEY_INPUT_N	;  ///<  @brief ����
    static const int O = KEY_INPUT_O	;  ///<  @brief ����
    static const int P = KEY_INPUT_P	; ///<  @brief ����
    static const int Q = KEY_INPUT_Q	;  ///<  @brief ����
    static const int R = KEY_INPUT_R	;  ///<  @brief ����
    static const int S = KEY_INPUT_S	;  ///<  @brief ����
    static const int T = KEY_INPUT_T	;  ///<  @brief ����
    static const int U = KEY_INPUT_U	;  ///<  @brief ����
    static const int V = KEY_INPUT_V	;  ///<  @brief ����
    static const int W = KEY_INPUT_W	;  ///<  @brief ����
    static const int X = KEY_INPUT_X	;  ///<  @brief ����
    static const int Y = KEY_INPUT_Y	;  ///<  @brief ����
    static const int Z = KEY_INPUT_Z	;  ///<  @brief ����
    static const int NUM0 = KEY_INPUT_0	;  ///<  @brief ����
    static const int NUM1 = KEY_INPUT_1	;  ///<  @brief ����
    static const int NUM2 = KEY_INPUT_2	;  ///<  @brief ����
    static const int NUM3 = KEY_INPUT_3	;  ///<  @brief ����
    static const int NUM4 = KEY_INPUT_4	;  ///<  @brief ����
    static const int NUM5 = KEY_INPUT_5	;  ///<  @brief ����
    static const int NUM6 = KEY_INPUT_6	;  ///<  @brief ����
    static const int NUM7 = KEY_INPUT_7	;  ///<  @brief ����
    static const int NUM8 = KEY_INPUT_8	;  ///<  @brief ����
    static const int NUM9 = KEY_INPUT_9	; ///<  @brief ����

/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetPush(int keyCode);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetDown(int keyCode);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	bool GetUp(int keyCode);
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	int GetCount(int keyCode);
private:
	float count[256];///<  @brief ����
};

}