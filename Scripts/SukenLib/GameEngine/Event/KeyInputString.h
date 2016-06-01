#pragma once
#include <DxLib.h>
#include <string>

enum TYPE{
	tInt,
	tStr
};

namespace suken{

class CKeyInputString {
public:
	//�����p
	//_link  ���͏���Ԃ�int�^�̕ϐ�
	//size  ���͂ł���ő啶����
	//cancelFlag  �d�����L�[�ɂ��L�����Z���̗L��
	CKeyInputString(int* _link,int size , bool cancelFlag = true):
		data(MakeKeyInput( size > 9 ? 9 : size, cancelFlag, false, true)), intLink(_link), strLink(nullptr), width(9*(size > 9 ? 9 : size)+3), height(16), link(tInt),writing(false){
			mem = nullptr;
	}

	//������p
	//_link  ���͏���Ԃ�string�^�̕ϐ�
	//size  ���͂ł���ő啶�����A�S�p��2������
	//cancelFlag  �d�����L�[�ɂ��L�����Z���̗L��
	//singleOnly  ���p�ɌŒ肷�邩�̃t���O
	//doubleOnly  �S�p�ɌŒ肷�邩�̃t���O
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

	//�c�P�U
	//activeOnly �����Ă���Ƃ��̂ݕ�����\��
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