#pragma once
#include"Debug.h"

namespace suken{
template<typename T>
class CArray {
public:
	CArray(unsigned int _xSize, unsigned int _ySize = 1, unsigned int _zSize = 1) {
		data = new T[_xSize * _ySize * _zSize];
		arraySize = _xSize * _ySize * _zSize;
		xSize = _xSize;
		ySize = _ySize;
		zSize = _zSize;
	}

	~CArray() {
		delete[] data;
	}
	
	T & operator [](unsigned int i) {
		return at(i);
	}

	T &at(unsigned int i) {
		if (i < arraySize) {
			return data[i];
		}
		else {
			//��O����
			suken::WarningSK("Array�̑��݂��Ȃ��v�f�ւ̃A�N�Z�X���s������܂���");
		}
		//�Ԃ�l�ۏ؁i���ꂪ�Ȃ���exe���t���[�Y����j
		T temp;
		return temp;
	}
	unsigned int size() {
		return arraySize;
	}

	//�������ϊ��p�֐��B�ꎟ�̎��͎g��Ȃ��B
	int Dimention(unsigned int x, unsigned int y = 0, unsigned int z = 0) {
		if (x < xSize || y < ySize || z < zSize) {
			return x + y*xSize + z*xSize*ySize;
		}
		else {
			suken::WarningSK("Array�̑��݂��Ȃ��v�f�ւ̃A�N�Z�X���s������܂���");
		}
		int temp;
		return temp;
	}

	//���߂�B
	void Fill(T o) {
		for (int i = 0; i < arraySize; i++) {
			data[i] = o;
		}
	}
	
private:
	T* data;
	int arraySize;
	unsigned int xSize;
	unsigned int ySize;
	unsigned int zSize;
};

}

