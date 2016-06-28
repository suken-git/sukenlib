#pragma once
#include"../../Manager.h"
#include <DxLib.h>
#include <string>

enum TYPE{
	tInt,
	tStr
};

namespace suken{

class CKeyInputString {
public:
	//数字用
	//_link  入力情報を返すint型の変数
	//size  入力できる最大文字数
	//cancelFlag  Ｅｓｃキーによるキャンセルの有無
	CKeyInputString(int* _link,int size , bool cancelFlag = true):
		data(MakeKeyInput( size > 9 ? 9 : size, cancelFlag, false, true)), intLink(_link), strLink(nullptr), width(9*(size > 9 ? 9 : size)+3), height(16), link(tInt),writing(false){
			mem = nullptr;
	}

	//文字列用
	//_link  入力情報を返すstring型の変数
	//size  入力できる最大文字数、全角は2文字分
	//cancelFlag  Ｅｓｃキーによるキャンセルの有無
	//singleOnly  半角に固定するかのフラグ
	//doubleOnly  全角に固定するかのフラグ
	CKeyInputString(std::string* _link, int size, bool cancelFlag = true , bool singleOnly = false, bool doubleOnly = false) :
		data(MakeKeyInput(size, cancelFlag, singleOnly, false, doubleOnly)), intLink(nullptr), strLink(_link),
			width(doubleOnly ? (size % 2 ? (int)(17*(size-1)/2+3) : (int)(17*size/2+3)) : 9*size+3), height(16), link(tStr), writing(false) {
				mem = new char [size];
	}

	~CKeyInputString() {
		DeleteKeyInput(data);
		if (intLink != nullptr) {
			delete intLink;
			intLink = nullptr;
		}
		if (strLink != nullptr) {
			delete strLink;
			strLink = nullptr;
		}
		if (mem != nullptr) {
			delete mem;
			mem = nullptr;
		}
	}

	void active() {
		SetActiveKeyInput(data);
		if (link == tInt) {
				SetKeyInputNumber(*intLink, data);
			}
		if (link == tStr) {
			SetKeyInputString(strLink->c_str(), data);
		}
		writing = 1;
	}

	bool CheckActive(){
		return writing;
	}

	//縦１６
	//activeOnly 書いているときのみ文字を表示
	void Draw(int x, int y, bool activeOnly = false, int x2 = 0,int y2 = 0);
	
private:
	const int data;
	int *intLink;
	std::string *strLink;
	const int width;
	const int height;
	const TYPE link;
	bool writing;
	char *mem;
};

void SetKeyInputStringColor(int NmlStr,int NmlCur,int _back,int _frame,int _font,int _fontColor);

}