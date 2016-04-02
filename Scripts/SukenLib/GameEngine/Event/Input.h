#pragma once
#include"EventData.h"
#include <vector>

namespace suken{

	//入力イベント管理クラス
class CInput{
public:
/**
*	@brief 説明
*/
	CInput();
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( int inputCode , void func() );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( int inputCode , void func(int) , int *pArgument );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( int inputCode , void func(int) , int Argument );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( int inputCode , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( int inputCode , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( int inputCode , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( CMouseIn input , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( CMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( CMouseIn input , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( CMouseIn input , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( CMouseIn input , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( CpMouseIn input , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( CpMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( CpMouseIn input , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( CpMouseIn input , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( CpMouseIn input , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( char input , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( char input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( char input , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( char input , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( char input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( char input , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( bool* input , void func()  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( bool* input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void AddEventListener( bool* input , void func(int) , int Argument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( bool* input , void func()  );	
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( bool* input , void func(int) , int *pArgument  );
/**
*	@brief 説明
*	@param value 引数
*/
	void RemoveEventListener( bool* input , void func(int) , int Argument  );
/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*/
	void DrawLoop();

	bool useKey,useMouse;
	int mouseX,mouseY;
private:
	CKeyIn keyTemp;
	std::vector<CKeyIn> keyTask;

	CMouseIn mouseTemp;
	std::vector<CMouseIn> mouseTask;

	CpMouseIn pMouseTemp;
	std::vector<CpMouseIn> pMouseTask;

	CFrame frameTemp;
	std::vector<CFrame> frameTask;

	CBoolean boolTemp;
	std::vector<CBoolean> boolTask;

	std::vector<CKeyIn> keyTask_Draw;
	std::vector<CMouseIn> mouseTask_Draw;
	std::vector<CpMouseIn> pMouseTask_Draw;
	std::vector<CFrame> frameTask_Draw;
	std::vector<CBoolean> boolTask_Draw;

	bool mouseInput,preMouseInput;
};



}