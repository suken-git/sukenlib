#pragma once
#include <unordered_map>
#include <string>

namespace suken{
template<typename T> class Cdata{
protected:
	std::string fileName;
	std::unordered_map<std::string,T> hashData;
	std::vector<T> vectorData;
	std::string Normalize(std::string str);
public :
	Cdata(const std::string &fileName){this->fileName = fileName;}
	T Get(int index){
		if (index >= vectorData.size())
			vectorData.resize(index + 1);
		return vectorData[index];
	}
	T Get(const std::string &key){
		auto itr = hashData.find(key);
		if( itr == hashData.end() ) return T();
		return hashData[key];		
	}
	T Set(int index,T value){
		if (index < 0)return;
		if (index >= vectorData.size())
			vectorData.resize(index + 1);
		vectorData[index] = value;
	}
	T Set(const std::string &key,T value){hashData[key] = value;}
	T Erase(int index){
		if (index >= vectorData.size() || index <0) return;
		vectorData.erase(vectorData.begin() + index);
	}
	T Erase(const std::string &key){ hashData.erase(key);}
	bool ReadAll();
	bool WriteAll();
};
//Depricated
class CIntStringData{
protected:
	std::string fileName;
	Cdata<int> intData;
	Cdata<std::string> stringData;
public:
	CIntStringData(const std::string &fileName){
		this->fileName = fileName;
		this->intData = Cdata<int>(fileName);
		this->stringData = Cdata<std::string>(fileName);
	}
	int GetInt(int index){return intData.Get(index);}
	std::string GetString(int index){}
	int GetInt(const std::string & key){}
	std::string GetString(const std::string &key){}
	void SetInt(int index,int value){}
	void SetString(int index,const std::string& key){}
	void SetInt(const std::string &key,int value){}
	void SetString(const std::string &key,const std::string &value){}
	void Set(int index,int value){}
	void Set(int index,const std::string &value){}
	void Set(const std::string &key,int value){}
	void Set(const std::string &key,const std::string &value){}
	void EraseInt(int index){}
	void EraseInt(const std::string & key){}
	void EraseString(int index){}
	void EraseString(const std::string &key){}
	bool ReadAll();
	bool WriteAll();
};
//ÇﬂÇ¡ÇøÇ·îÒêÑèß
class CData{
protected:
	std::string fileName;
	std::unordered_map<std::string,int> hashIntData;
	std::unordered_map<std::string,std::string> hashStringData;
	std::vector<int> vectorIntData;
	std::vector<std::string> vectorStringData;
	std::string Normalize(std::string Str);
public:
	CData(std::string fileName){
		this->fileName = fileName;
	}
	int GetInt(int index){
		if (index >= vectorIntData.size())
			vectorIntData.resize(index+1);
		return vectorIntData[index];
	}
	std::string GetString(int index){
		if (index >= vectorStringData.size())
			vectorStringData.resize(index+1);
		return vectorStringData[index];	
	}
	int GetInt(const std::string &key){
		auto itr = hashIntData.find(key);
        if( itr == hashIntData.end() ) return 0;
		return hashIntData[key];
	}
	std::string GetString(const std::string &key){
		auto itr = hashStringData.find(key);
        if( itr == hashStringData.end() ) return "";
		return hashStringData[key];	
	}
	void SetInt(int index,int value){
		if (index >= vectorIntData.size())
			vectorIntData.resize(index+1);
		vectorIntData[index] = value;
	}
	void SetString(int index,std::string value){
		if (index >= vectorStringData.size())
			vectorStringData.resize(index+1);
		vectorStringData[index] = value;
	}
	void SetInt(const std::string &key,int value){hashIntData[key] = value;}
	void SetString(const std::string &key,std::string value){hashStringData[key] = value;}
	void Set(int index,int value){SetInt(index,value);}
	void Set(int index,std::string value){SetString(index,value);}
	void Set(const std::string &key,int value){SetInt(key,value);}
	void Set(const std::string &key,std::string value){SetString(key,value);}
	void EraseInt(int index){
		if (index >= vectorIntData.size() || index <0) return;
		vectorIntData.erase(vectorIntData.begin() + index);
	}
	void EraseInt(const std::string &key){ hashIntData.erase(key);}
	void EraseString(int index){
		if (index >= vectorIntData.size() || index <0) return;
		vectorIntData.erase(vectorIntData.begin() + index);
	}
	void EraseString(const std::string &key){hashStringData.erase(key);}
	
	bool ReadAll();
	bool WriteAll();
};
}