#pragma once
#include"SukenLib\Utility\Debug.h"
template<typename T>
class Array{
public:
	Array(int _size){
		data = new T[_size];
		arraySize = _size;
	}
	T & operator [](int i) { 
		return at(i);
	}
	T &at(int i){
		if( i >= 0 && i < arraySize ){
			return data[i];
		}else{
			//��O����
			suken::WarningSK("Array�̑��݂��Ȃ��v�f�ւ̃A�N�Z�X���s������܂���");
		}
		//�Ԃ�l�ۏ؁i���ꂪ�Ȃ���exe���t���[�Y����j
		T temp;
		return temp;
	}
	unsigned int size(){
		return arraySize;
	}
	
private:
	T* data;
	int arraySize;
};

