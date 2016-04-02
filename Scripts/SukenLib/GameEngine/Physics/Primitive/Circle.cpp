#include"Circle.h"
#include <Utility/Utility.h>
#define _USE_MATH_DEFINES
#include "math.h"

suken::CCircle::CCircle(){
	mass = 1.0f;
	radius = 1.0f;
	bound = 1.0f;
	IsKinematic = false;
}
suken::Vector2D suken::CCircle::GetCenterPos(){		
	return center.position;					
}
float suken::CCircle::GetArea(){ 			
	return (float)( M_PI * radius * radius );		
}
void suken::CCircle::Loop(){
	center.Loop();
#ifdef DEBUG_DRAW
	DxLib::DrawCircle((int)(center.position.x +0.5), (int)(center.position.y+0.5) , (int)(radius+0.5) ,WHITE ,false );
#endif
}



void suken::CCircle::AddCollisionFalse(CCircle *c){
	noCollision.push_back(c);
}
void suken::CCircle::RemoveCollisionFalse(CCircle *c){
	if(!noCollision.empty()){
		std::vector<CCircle*>::iterator it = noCollision.begin();
		while( ( it != noCollision.end() ) ){

			if( *it ==  c  ){

				noCollision.erase( it );
				break;
			}
			it++;
		}
	}
}
bool suken::CCircle::GetIsNoCollision(CCircle *c){
	if(!noCollision.empty()){
		std::vector<CCircle*>::iterator it = noCollision.begin();
		while( ( it != noCollision.end() ) ){

			if( *it ==  c  ){

				return true;
			}
			it++;
		}
	}
	return false;
}