#pragma once
#include <DxLib.h>
#include <string>

class CKeyInputString {
public:
	//�����p
	//_link  ���͏���Ԃ�int�^�̕ϐ�
	//size  ���͂ł���ő啶����
	//cancelFlag  �d�����L�[�ɂ��L�����Z���̗L��
	CKeyInputString(int* _link,int size , bool cancelFlag = true):
		data(MakeKeyInput( size > 9 ? 9 : size, cancelFlag, false, true)), intLink(_link), strLink(NULL), width(9*(size > 9 ? 9 : size)+3), height(16), link(0),writing(false){
			mem = NULL;
	}

	//������p
	//_link  ���͏���Ԃ�string�^�̕ϐ�
	//size  ���͂ł���ő啶�����A�S�p��2������
	//cancelFlag  �d�����L�[�ɂ��L�����Z���̗L��
	//singleOnly  ���p�ɌŒ肷�邩�̃t���O
	//doubleOnly  �S�p�ɌŒ肷�邩�̃t���O
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
	// 0 �F int
	// 1 �F string   �킩��ɂ����̂łǂ��ɂ�������
	const bool link;
	bool writing;
	char *mem;
};