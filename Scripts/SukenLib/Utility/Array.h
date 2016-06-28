#pragma once
#include"../Manager.h"
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
			//例外処理
			suken::WarningSK("Arrayの存在しない要素へのアクセス試行がありました");
		}
		//返り値保証（これがないとexeがフリーズする）
		T temp;
		return temp;
	}
	unsigned int size() {
		return arraySize;
	}

	//多次元変換用関数。一次の時は使わない。
	int Dimention(unsigned int x, unsigned int y = 0, unsigned int z = 0) {
		if (x < xSize || y < ySize || z < zSize) {
			return x + y*xSize + z*xSize*ySize;
		}
		else {
			suken::WarningSK("Arrayの存在しない要素へのアクセス試行がありました");
		}
		int temp;
		return temp;
	}

	//埋める。
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

