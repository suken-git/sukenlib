#include "Suken.h"

void suken::Awake(){

}

void suken::GameLoopEnter(){
	debug.PrintKeyPush(Event.key.RETURN,"ENTER");
	debug.PrintKeyUp(Event.key.RETURN,"ENTER");
	debug.PrintKeyDown(Event.key.RETURN,"ENTER");
}

void suken::GameLoopExit(){

}