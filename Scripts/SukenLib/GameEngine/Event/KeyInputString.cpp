#include "KeyInputString.h"
#include "Event.h"

void CKeyInputString::Draw(int x, int y, bool activeOnly, int x2, int y2) {
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
		if (writing == 0 && activeOnly == false) {
			if (link == tInt) {
				DrawFormatString(x+1, y, GetColor(255,255,255), "%d",*intLink);
			}
			if (link == tStr) {
				DrawString(x+1, y, strLink->c_str(), GetColor(255,255,255));
			}
		}
		if (writing == 1){
			DrawBox(x, y, x + width, y + height, GetColor(0,0,0), true);
			DrawBox(x, y, x + width, y + height, GetColor(120,120,120), false);
			DrawKeyInputString(x+1, y,data);
		}
		if(Event.LMouse.GetClick(x, y,x2 == 0 ? x + width : x2,y2 == 0 ? y + height : y2)){
				active();
		}
	}