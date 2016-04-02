#pragma once
//for KEY_INPUT_~
#include"Manager.h"

namespace suken{

class CKey{
public:
	CKey(){

      

	}

	static const int BACK = KEY_INPUT_BACK	;
    static const int TAB = KEY_INPUT_TAB	;
    static const int RETURN = KEY_INPUT_RETURN	;

    static const int LSHIFT = KEY_INPUT_LSHIFT	;
    static const int RSHIFT = KEY_INPUT_RSHIFT	; 
    static const int LCONTROL = KEY_INPUT_LCONTROL	;
    static const int RCONTROL = KEY_INPUT_RCONTROL	; 
    static const int ESCAPE = KEY_INPUT_ESCAPE	; 
    static const int SPACE = KEY_INPUT_SPACE	; 
    static const int PGUP = KEY_INPUT_PGUP	; 
    static const int PGDN = KEY_INPUT_PGDN	;
    static const int END = KEY_INPUT_END	; 
    static const int HOME = KEY_INPUT_HOME	;
    static const int LEFT = KEY_INPUT_LEFT	; 
    static const int UP = KEY_INPUT_UP	; 
    static const int RIGHT = KEY_INPUT_RIGHT	; 
    static const int DOWN = KEY_INPUT_DOWN	; 
    static const int INSERT = KEY_INPUT_INSERT	; 
    static const int _DELETE = KEY_INPUT_DELETE	;

    static const int MINUS = KEY_INPUT_MINUS	; 
    static const int YEN = KEY_INPUT_YEN	; 
    static const int PREVTRACK = KEY_INPUT_PREVTRACK	; 
    static const int PERIOD = KEY_INPUT_PERIOD	;
    static const int SLASH = KEY_INPUT_SLASH	;
    static const int LALT = KEY_INPUT_LALT	;
    static const int RALT = KEY_INPUT_RALT	; 
    static const int SCROLL = KEY_INPUT_SCROLL	; 
    static const int SEMICOLON = KEY_INPUT_SEMICOLON	;
    static const int COLON = KEY_INPUT_COLON	; 
    static const int LBRACKET = KEY_INPUT_LBRACKET	;
    static const int RBRACKET = KEY_INPUT_RBRACKET	; 
    static const int AT = KEY_INPUT_AT	; 
    static const int BACKSLASH = KEY_INPUT_BACKSLASH	; 
    static const int COMMA = KEY_INPUT_COMMA	; 
    static const int CAPSLOCK = KEY_INPUT_CAPSLOCK	;
    static const int PAUSE = KEY_INPUT_PAUSE	; 

    static const int NUMPAD0 = KEY_INPUT_NUMPAD0	;
    static const int NUMPAD1 = KEY_INPUT_NUMPAD1	; 
    static const int NUMPAD2 = KEY_INPUT_NUMPAD2	; 
    static const int NUMPAD3 = KEY_INPUT_NUMPAD3	; 
    static const int NUMPAD4 = KEY_INPUT_NUMPAD4	; 
    static const int NUMPAD5 = KEY_INPUT_NUMPAD5	; 
    static const int NUMPAD6 = KEY_INPUT_NUMPAD6	; 
    static const int NUMPAD7 = KEY_INPUT_NUMPAD7	; 
    static const int NUMPAD8 = KEY_INPUT_NUMPAD8	; 
    static const int NUMPAD9 = KEY_INPUT_NUMPAD9	; 
    static const int MULTIPLY = KEY_INPUT_MULTIPLY	; 
    static const int ADD = KEY_INPUT_ADD	; 
    static const int SUBTRACT = KEY_INPUT_SUBTRACT	;
    static const int DECIMAL = KEY_INPUT_DECIMAL	; 
    static const int DIVIDE = KEY_INPUT_DIVIDE	; 
    static const int NUMPADENTER = KEY_INPUT_NUMPADENTER	; 

    static const int F1 = KEY_INPUT_F1	; 
    static const int F2 = KEY_INPUT_F2	;
    static const int F3 = KEY_INPUT_F3	; 
    static const int F4 = KEY_INPUT_F4	; 
    static const int F5 = KEY_INPUT_F5	; 
    static const int F6 = KEY_INPUT_F6	; 
    static const int F7 = KEY_INPUT_F7	;
    static const int F8 = KEY_INPUT_F8	; 
    static const int F9 = KEY_INPUT_F9	; 
    static const int F10 = KEY_INPUT_F10	; 
    static const int F11 = KEY_INPUT_F11	; 
    static const int F12 = KEY_INPUT_F12	; 

    static const int A = KEY_INPUT_A	;  
    static const int B = KEY_INPUT_B	;  
    static const int C = KEY_INPUT_C	;  
    static const int D = KEY_INPUT_D	;  
    static const int E = KEY_INPUT_E	;  
    static const int F = KEY_INPUT_F	;  
    static const int G = KEY_INPUT_G	;  
    static const int H = KEY_INPUT_H	;  
    static const int I = KEY_INPUT_I	;  
    static const int J = KEY_INPUT_J	;  
    static const int K = KEY_INPUT_K	;  
    static const int L = KEY_INPUT_L	;  
    static const int M = KEY_INPUT_M	; 
    static const int N = KEY_INPUT_N	;  
    static const int O = KEY_INPUT_O	;  
    static const int P = KEY_INPUT_P	; 
    static const int Q = KEY_INPUT_Q	;  
    static const int R = KEY_INPUT_R	;  
    static const int S = KEY_INPUT_S	;  
    static const int T = KEY_INPUT_T	;  
    static const int U = KEY_INPUT_U	;  
    static const int V = KEY_INPUT_V	;  
    static const int W = KEY_INPUT_W	;  
    static const int X = KEY_INPUT_X	;  
    static const int Y = KEY_INPUT_Y	;  
    static const int Z = KEY_INPUT_Z	;  
    static const int NUM0 = KEY_INPUT_0	;  
    static const int NUM1 = KEY_INPUT_1	;  
    static const int NUM2 = KEY_INPUT_2	;  
    static const int NUM3 = KEY_INPUT_3	;  
    static const int NUM4 = KEY_INPUT_4	;  
    static const int NUM5 = KEY_INPUT_5	;  
    static const int NUM6 = KEY_INPUT_6	;  
    static const int NUM7 = KEY_INPUT_7	;  
    static const int NUM8 = KEY_INPUT_8	;  
    static const int NUM9 = KEY_INPUT_9	; 


	void Loop();
	bool GetPush(int keyCode);
	bool GetDown(int keyCode);
	bool GetUp(int keyCode);
	int GetCount(int keyCode);
private:
	float count[256];
};

}