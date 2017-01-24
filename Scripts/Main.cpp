#include "Suken.h"

std::string str = "HelloWorld";
CKeyInputString key(&str, 25, 100, "Times New Roman");

void suken::Awake() {
	key.SetFont("Times New Roman", SHUIRO, 6, false, -1, 2, ORANGE);
}

void suken::GameLoopEnter(){
	key.Draw(20, 20);
}

void suken::GameLoopExit(){

}