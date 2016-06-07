#pragma once
#include <DxLib.h>
#include <string>
#include"../Scene.h"


enum KEY_INPUT_TYPE{
	NONE,NUMBER,ENGLISH,JAPANESE,KEY_INPUT_TYPE_NUM
};
const int MAX_KEY_INPUT = 256;
namespace suken
{
	class CKeyInputModule;
	class CKeyInputUnit;
	class CKeyInputUnit
	{
	public:
		CKeyInputUnit();
		void Init(int x,int y,int _serialNum,int *_pCurrentInputSerial ,int maxLength , char temp,int *_intLink );
		void Init(int x,int y,int _serialNum,int *_pCurrentInputSerial ,int maxLength , int temp , std::string *_strLink );
		void BeginInput(int x,int y,int maxLength,bool cancelFlag = true);
		void Loop();
		int GetSerialNum();
		void SetColor(int color);
		Vector2D pos;
	private:
		bool IsActive;
		int keyInputHandle;
		int *pCurrentInputSerial;
		int serialNumber;
		int intData;
		int *intLink;
		std::string strData;
		std::string *strLink;
		CKeyInputModule *parent;
		//color
		int strColor;
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	class CKeyInputModule :public std::vector<CKeyInputUnit> 
	{
	public:
		CKeyInputModule();
		void Init(KEY_INPUT_TYPE _type,int *_pSerial,int *_pCurrentInputSerial);
		int MakeInput(int x,int y,int maxLength,void *_link = nullptr);
		bool End(int serialNum);
	private:
		KEY_INPUT_TYPE type;
		int *pSerial;
		int *pCurrentInputSerial;
	};
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	class CKeyInput{
	public:
		CKeyInput();
		void Loop();
		void End();

		CKeyInputModule number;
		CKeyInputModule english;
		CKeyInputModule japanese;
		CScene inputScene;
	private:

		int currentInputSerial;
		int serial[4];
	};
}

void inputSceneLoop();