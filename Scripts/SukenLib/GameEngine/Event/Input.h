#pragma once
#include"EventData.h"
#include <vector>

namespace suken{

	//入力イベント管理クラス
class CInput{
public:
	CInput();
	void AddEventListener( int inputCode , void func() );
	void AddEventListener( int inputCode , void func(int) , int *pArgument );
	void AddEventListener( int inputCode , void func(int) , int Argument );
	void RemoveEventListener( int inputCode , void func()  );
	void RemoveEventListener( int inputCode , void func(int) , int *pArgument  );
	void RemoveEventListener( int inputCode , void func(int) , int Argument  );
	void AddEventListener( CMouseIn input , void func()  );
	void AddEventListener( CMouseIn input , void func(int) , int *pArgument  );
	void AddEventListener( CMouseIn input , void func(int) , int Argument  );
	void RemoveEventListener( CMouseIn input , void func()  );
	void RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  );
	void RemoveEventListener( CMouseIn input , void func(int) , int Argument  );
	void AddEventListener( CpMouseIn input , void func()  );
	void AddEventListener( CpMouseIn input , void func(int) , int *pArgument  );
	void AddEventListener( CpMouseIn input , void func(int) , int Argument  );
	void RemoveEventListener( CpMouseIn input , void func()  );
	void RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  );
	void RemoveEventListener( CpMouseIn input , void func(int) , int Argument  );
	void AddEventListener( char input , void func()  );
	void AddEventListener( char input , void func(int) , int *pArgument  );
	void AddEventListener( char input , void func(int) , int Argument  );
	void RemoveEventListener( char input , void func()  );
	void RemoveEventListener( char input , void func(int) , int *pArgument  );
	void RemoveEventListener( char input , void func(int) , int Argument  );
	void AddEventListener( bool* input , void func()  );
	void AddEventListener( bool* input , void func(int) , int *pArgument  );
	void AddEventListener( bool* input , void func(int) , int Argument  );
	void RemoveEventListener( bool* input , void func()  );	
	void RemoveEventListener( bool* input , void func(int) , int *pArgument  );
	void RemoveEventListener( bool* input , void func(int) , int Argument  );

	void Loop();
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