#pragma once
#include <unordered_map>
#include <string>

namespace suken{
class CData{
private:
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
	void Set(int index,int value){
		if (index >= vectorIntData.size())
			vectorIntData.resize(index+1);
		vectorIntData[index] = value;
	}
	void Set(int index,std::string value){
		if (index >= vectorStringData.size())
			vectorStringData.resize(index+1);
		vectorStringData[index] = value;
	}
	void Set(std::string key,int value){hashIntData[key] = value;}
	void Set(std::string key,std::string value){hashStringData[key] = value;}
	
	bool ReadAll();
	bool WriteAll();
};
}