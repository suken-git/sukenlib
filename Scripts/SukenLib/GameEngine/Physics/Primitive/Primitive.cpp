#include"Primitive.h"


suken::CPrimitive::CPrimitive(){

}
void suken::CPrimitive::AddEventLisnerOnCollision(void (*pFunc)()){
	onCollisionTaskVoid.push_back(pFunc);
}
void suken::CPrimitive::RemoveEventLisnerOnCollision(void (*pFunc)()){
	if(!onCollisionTaskVoid.empty()){
		std::vector<void(*)()>::iterator it = onCollisionTaskVoid.begin();
		while( ( it != onCollisionTaskVoid.end() ) ){

			if( *it ==  pFunc  ){
				onCollisionTaskVoid.erase( it );
				break;
			}
			it++;
		}
	}
}
void suken::CPrimitive::OnCollisionFunc(){
	if(!onCollisionTaskVoid.empty()){
		std::vector<void(*)()>::iterator it=onCollisionTaskVoid.begin();

		while( it != onCollisionTaskVoid.end() ) {

			(*it)();					
			it++;
		}

	}
}
bool suken::CPrimitive::GetCollisionState(){
	return onCollision;
}
void suken::CPrimitive::SetCollisionState(bool flag){
	onCollision = flag;
}
void suken::CPrimitive::Loop(){
	center.Loop();
}