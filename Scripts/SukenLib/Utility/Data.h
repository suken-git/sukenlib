#pragma once
#include <unordered_map>
#include <string>

namespace suken{
class CData{
private:
	std::string fileName;///<  @brief ����
	std::unordered_map<std::string,int> hashIntData;///<  @brief ����
	std::unordered_map<std::string,std::string> hashStringData;///<  @brief ����
	std::vector<int> vectorIntData;///<  @brief ����
	std::vector<std::string> vectorStringData;///<  @brief ����
	std::string Normalize(std::string Str);///<  @brief ����
public:
/**
*	@brief ����
*	@param value ����
*/
	CData(std::string fileName)
{
		this->fileName = fileName;
	}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	int GetInt(int index)
{
		if (index >= vectorIntData.size())
			vectorIntData.resize(index+1);
		return vectorIntData[index];
	}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	std::string GetString(int index)
{
		if (index >= vectorStringData.size())
			vectorStringData.resize(index+1);
		return vectorStringData[index];	
	}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	int GetInt(const std::string &key)
{
		auto itr = hashIntData.find(key);
        if( itr == hashIntData.end() ) return 0;
		return hashIntData[key];
	}
/**
*	@brief ����
*	@param value ����
* @return �߂�l
*/
	std::string GetString(const std::string &key)
{
		auto itr = hashStringData.find(key);
        if( itr == hashStringData.end() ) return "";
		return hashStringData[key];	
	}
/**
*	@brief ����
*	@param value ����
*/
	void Set(int index,int value)
{
		if (index >= vectorIntData.size())
			vectorIntData.resize(index+1);
		vectorIntData[index] = value;
	}
/**
*	@brief ����
*	@param value ����
*/
	void Set(int index,std::string value)
{
		if (index >= vectorStringData.size())
			vectorStringData.resize(index+1);
		vectorStringData[index] = value;
	}
/**
*	@brief ����
*	@param value ����
*/
	void Set(std::string key,int value)
{hashIntData[key] = value;}
/**
*	@brief ����
*	@param value ����
*/
	void Set(std::string key,std::string value)
{hashStringData[key] = value;}
/**
*	@brief ����
* @return �߂�l
*/
	bool ReadAll();
/**
*	@brief ����
* @return �߂�l
*/
	bool WriteAll();
};
}