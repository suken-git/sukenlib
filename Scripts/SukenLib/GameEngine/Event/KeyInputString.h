#pragma once
#include <DxLib.h>
#include <string>

class CKeyInputString {
public:
	//数字用
	//_link  入力情報を返すint型の変数
	//size  入力できる最大文字数
	//cancelFlag  Ｅｓｃキーによるキャンセルの有無
	CKeyInputString(int* _link,int size , bool cancelFlag = true):
		data(MakeKeyInput( size > 9 ? 9 : size, cancelFlag, false, true)), intLink(_link), strLink(NULL), width(9*(size > 9 ? 9 : size)+3), height(16), link(0),writing(false){
			mem = NULL;
	}

	//文字列用
	//_link  入力情報を返すstring型の変数
	//size  入力できる最大文字数、全角は2文字分
	//cancelFlag  Ｅｓｃキーによるキャンセルの有無
	//singleOnly  半角に固定するかのフラグ
	//doubleOnly  全角に固定するかのフラグ
	CKeyInputString(std::string* _link, int size, bool cancelFlag = true , bool singleOnly = false, bool doubleOnly = false) :
		data(MakeKeyInput(size, cancelFlag, singleOnly, false, doubleOnly)), intLink(NULL), strLink(_link),
			width(doubleOnly ? (size % 2 ? (int)(17*(size-1)/2+3) : (int)(17*size/2+3)) : 9*size+3), height(16), link(1), writing(false) {
				mem = new char [size];
	}

	~CKeyInputString() {
		DeleteKeyInput(data);
		if (intLink != NULL) {
			delete intLink;
			intLink = NULL;
		}
		if (strLink != NULL) {
			delete strLink;
			strLink = NULL;
		}
		if (mem != NULL) {
			delete mem;
			mem = NULL;
		}
	}

	void active() {
		SetActiveKeyInput(data);
		if (link == 0) {
				SetKeyInputNumber(*intLink, data);
			}
			if (link == 1) {
				SetKeyInputString(strLink->c_str(), data);
			}
		writing = 1;
	}

	void Draw(int x, int y, int _width = 0, int _height = 0);
	
private:
	const int data;
	int *intLink;
	std::string *strLink;
	const int width;
	const int height;
	// 0 ： int
	// 1 ： string   わかりにくいのでどうにかしたい
	const bool link;
	bool writing;
	char *mem;
};