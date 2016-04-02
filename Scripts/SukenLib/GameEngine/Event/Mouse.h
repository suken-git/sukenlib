#pragma once
#include"EventData.h"

namespace suken{
const int MOUSE_OFF		=	10;
const int MOUSE_ON		=	11;
const int MOUSE_PUSH	=	12;
const int MOUSE_CLICK	=	13;
const int MOUSE_RELEASE =	14;


//マウス定義クラス
class CMouse{
public:
	CMouseIn Off( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetOff( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	CMouseIn On( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetOn( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn On( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	CMouseIn Click( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetClick( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	CMouseIn Release( int _x1 , int _y1 , int _x2 , int _y2 );
	bool GetRelease( int _x1 , int _y1 , int _x2 , int _y2 );
	CpMouseIn Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	bool GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 );
	void Loop();
	void SetLeft();
	void SetRight();
	int mouseX,mouseY;
	bool mouseInput,preMouseInput;
	
private:
	bool IsLeft;
};


}

