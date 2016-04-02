#pragma once
//for CMouseIn,CpMouseIn
#include"EventData.h"

namespace suken{


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

