#pragma once
#include"../Manager.h"
#include <unordered_map>
#include <string>

namespace suken{
class CData{
private:
	std::string fileName;///<  @brief 説明
	std::unordered_map<std::string,int> hashIntData;///<  @brief 説明
	std::unordered_map<std::string,std::string> hashStringData;///<  @brief 説明
	std::vector<int> vectorIntData;///<  @brief 説明
	std::vector<std::string> vectorStringData;///<  @brief 説明
	std::string Normalize(std::string Str);///<  @brief 説明
public:
/**
*	@brief 説明
*	@param value 引数
*/
	CData(std::string fileName)
{
		this->fileName = fileName;
	}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	int GetInt(int index)
{
		if (index >= vectorIntData.size())
			vectorIntData.resize(index+1);
		return vectorIntData[index];
	}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	std::string GetString(int index)
{
		if (index >= vectorStringData.size())
			vectorStringData.resize(index+1);
		return vectorStringData[index];	
	}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	int GetInt(const std::string &key)
{
		auto itr = hashIntData.find(key);
        if( itr == hashIntData.end() ) return 0;
		return hashIntData[key];
	}
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	std::string GetString(const std::string &key)
{
		auto itr = hashStringData.find(key);
        if( itr == hashStringData.end() ) return "";
		return hashStringData[key];	
	}
/**
*	@brief 説明
*	@param value 引数
*/
	void Set(int index,int value)
{
		if (index >= vectorIntData.size())
			vectorIntData.resize(index+1);
		vectorIntData[index] = value;
	}
/**
*	@brief 説明
*	@param value 引数
*/
	void Set(int index,std::string value)
{
		if (index >= vectorStringData.size())
			vectorStringData.resize(index+1);
		vectorStringData[index] = value;
	}
/**
*	@brief 説明
*	@param value 引数
*/
	void Set(std::string key,int value)
{hashIntData[key] = value;}
/**
*	@brief 説明
*	@param value 引数
*/
	void Set(std::string key,std::string value)
{hashStringData[key] = value;}
/**
*	@brief 説明
* @return 戻り値
*/
	bool ReadAll();
/**
*	@brief 説明
* @return 戻り値
*/
	bool WriteAll();
};
}