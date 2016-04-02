#include "DxLib.h"
#include"Mouse.h"
#include"Event.h"

suken::CMouseIn suken::CMouse::Off( int _x1 , int _y1 , int _x2 , int _y2 ){

	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool suken::CMouse::GetOff( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1>mouseX && _x2<mouseX ){
		if(_y1>mouseY && _y2<mouseY){
			return true;
		}
	}
	return false;
}
suken::CpMouseIn suken::CMouse::Off( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){

	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_OFF;

	return temp;
}
bool suken::CMouse::GetOff( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1>mouseX && *_x2<mouseX ){
		if(*_y1>mouseY && *_y2<mouseY){
			return true;
		}
	}
	return false;
}
suken::CMouseIn suken::CMouse::On( int _x1 , int _y1 , int _x2 , int _y2 ){
	
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool suken::CMouse::GetOn( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
suken::CpMouseIn suken::CMouse::On( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_ON;

	return temp;

}
bool suken::CMouse::GetOn( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(Event.GetValid()){
				return true;
			}
		}
	}
	return false;
}
suken::CMouseIn suken::CMouse::Click( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool suken::CMouse::GetClick( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;		
				}
			} 
		}
	}
	return false;
}
suken::CpMouseIn suken::CMouse::Click( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_CLICK;

	return temp;

}
bool suken::CMouse::GetClick( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if(mouseInput && !preMouseInput ){
				if(Event.GetValid()){
					return true;	
				}
			} 
		}
	}
	return false;
}
suken::CMouseIn suken::CMouse::Release( int _x1 , int _y1 , int _x2 , int _y2 ){
		
	CMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool suken::CMouse::GetRelease( int _x1 , int _y1 , int _x2 , int _y2 ){
	if(_x1<mouseX && _x2>mouseX ){
		if(_y1<mouseY && _y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
suken::CpMouseIn suken::CMouse::Release( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
		
	CpMouseIn temp;

	temp.x1 = _x1;
	temp.x2 = _x2;
	temp.y1 = _y1;
	temp.y2 = _y2;

	temp.type = MOUSE_RELEASE;

	return temp;
}
bool suken::CMouse::GetRelease( int *_x1 , int *_y1 , int *_x2 , int *_y2 ){
	if(*_x1<mouseX && *_x2>mouseX ){
		if(*_y1<mouseY && *_y2>mouseY){
			if( !mouseInput && preMouseInput ){
				if(Event.GetValid()){
					return true;
				}
			} 
		}	
	}
	return false;
}
void suken::CMouse::Loop(){
	GetMousePoint( &mouseX, &mouseY );
	preMouseInput = mouseInput;
	if(IsLeft){
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_LEFT );
	}else{
		mouseInput = (bool)( GetMouseInput() & MOUSE_INPUT_RIGHT );
	}
}
void suken::CMouse::SetLeft(){
	IsLeft = true;
}
void suken::CMouse::SetRight(){
	IsLeft = false;
}