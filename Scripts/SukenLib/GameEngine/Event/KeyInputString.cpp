#include "KeyInputString.h"
#include "Event.h"

void CKeyInputString::Draw(int x, int y, int _width, int _height) {
	if(_width <= 0)_width = width;
	if(_height <= 0)_height = height;
		if (CheckKeyInput(data) == 1) {
			writing = 0;
			if (link == 0) {
				*intLink = GetKeyInputNumber(data);
			}
			if (link == 1) {
				GetKeyInputString(mem,data);
				*strLink = mem;
			}
		}
		if(CheckKeyInput(data) == 2){
			writing = 0;
		}
		switch (writing) {
		case false:
			if (link == 0) {
				DrawFormatString(x+1, y, GetColor(255,255,255), "%d",*intLink);
			}
			if (link == 1) {
				DrawString(x+1, y, strLink->c_str(), GetColor(255,255,255));
			}
			if(Event.LMouse.GetClick(x, y, x + _width, y + _height)){
				active();
			}
		break;
		case true:
			DrawBox(x, y, x + width, y + height, GetColor(0,0,0), true);
			DrawBox(x, y, x + width, y + height, GetColor(255,255,255), false);
			DrawKeyInputString(x+1, y,data);
			
			
		break;
		}
	}