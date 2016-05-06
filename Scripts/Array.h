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
			//例外処理
			suken::WarningSK("Arrayの存在しない要素へのアクセス試行がありました");
		}
		//返り値保証（これがないとexeがフリーズする）
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

