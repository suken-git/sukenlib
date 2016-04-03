#include"Transform.h"
#include <System/System.h>

suken::CTransform::CTransform(){
	//prePosition = position = velocity = acceralate = VGet(0,0);
	rotation = 0.0f;
	gravity = VGet(0,0);
	airResistance = 0 ;
}

void suken::CTransform::TransLate(suken::Vector2D _v){
	position += _v;
}

void suken::CTransform::Loop(){
		
	//prePosition = position;
		
	///‹ó‹C’ïR
	acceralate *= ( 1 - ( airResistance / System.GetFps() ));
		
	///‘¬“x
	velocity += (acceralate + gravity ) / System.GetFps();
	velocity *= ( 1 - ( airResistance / System.GetFps() ));
	///ˆÊ’u
	prePosition = position;
	position += velocity / System.GetFps();
	if( velocity.y > 0.0f ){
		rotation = acos(VNorm(velocity).x);
	}else{
		rotation = -acos(VNorm(velocity).x);
	}
}
