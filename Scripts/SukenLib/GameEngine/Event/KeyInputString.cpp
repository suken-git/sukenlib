#include "KeyInputString.h"
#include "Event.h"

const int RED = GetColor( 255 , 0 , 0 );///<  @brief ����
const int GREEN = GetColor( 0 , 255 , 0 );///<  @brief ����
const int BLUE = GetColor( 0 , 0 , 255 );///<  @brief ����
const int BLACK = GetColor( 0 , 0 , 0 );///<  @brief ����
const int WHITE = GetColor( 255 , 255 , 255 );///<  @brief ����
const int GRAY = GetColor( 128 , 128 , 128 );///<  @brief ����
const int LIGHTBLUE = GetColor( 128 , 128 , 255 );///<  @brief ����
const int LIGHTGREEN = GetColor( 128 , 255 , 128 );///<  @brief ����
const int M_PINK = GetColor( 255 , 128 , 128 );///<  @brief ����
const int YELLOW = GetColor( 255 , 255 , 0);///<  @brief ����

int back = GetColor(255,255,255);
int frame = GetColor(0,0,0);
int font = NULL;
int fontColor = GetColor(255,255,255);

void suken::CKeyInputString::Draw(int x, int y, bool activeOnly, int x2, int y2) {
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
				if(font == NULL){
					DrawFormatString(x+1, y, fontColor, "%d",*intLink);
				}else{
					DrawFormatStringToHandle(x+1, y, fontColor,font, "%d",*intLink);
				}
			}
			if (link == tStr) {
				if(font == NULL){
					DrawString(x+1, y, strLink->c_str(), fontColor);
				}else{
					DrawStringToHandle(x+1, y, strLink->c_str(), fontColor,font);
				}
			}
		}
		if (writing == 1){
			DrawBox(x, y, x + width, y + height, back, true);
			DrawBox(x, y, x + width, y + height, frame, false);
			DrawKeyInputString(x+1, y,data);
		}
		if(Event.LMouse.GetClick(x, y,x2 == 0 ? x + width : x2,y2 == 0 ? y + height : y2)){
				active();
		}
	}