#include "KeyInputString.h"
#include "Event.h"

void CKeyInputString::Draw(int x, int y, bool activeOnly) {
		if (CheckKeyInput(data) == 1) {
			writing = 0;
			if (link == tInt) {
				*intLink = GetKeyInputNumber(data);
			}
			if (link == tStr) {
				GetKeyInputString(mem,data);
				*strLink = mem;
			}
		}
		if(CheckKeyInput(data) == 2){
			writing = 0;
		}
		if (writing == 0 && activeOnly == true) {
			if (link == tInt) {
				DrawFormatString(x+1, y, GetColor(255,255,255), "%d",*intLink);
			}
			if (link == tStr) {
				DrawString(x+1, y, strLink->c_str(), GetColor(255,255,255));
			}
			if(Event.LMouse.GetClick(x, y, x + width, y + height)){
				active();
			}
		}
		if (writing == 1){
			DrawBox(x, y, x + width, y + height, GetColor(0,0,0), true);
			DrawBox(x, y, x + width, y + height, GetColor(120,120,120), false);
			DrawKeyInputString(x+1, y,data);
		}
	}