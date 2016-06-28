#pragma once
#include"../../Manager.h"
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void AddEventListener( int inputCode , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void RemoveEventListener( int inputCode , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void AddEventListener( CMouseIn input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void RemoveEventListener( CMouseIn input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void AddEventListener( CpMouseIn input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void RemoveEventListener( CpMouseIn input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void AddEventListener( char input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void RemoveEventListener( char input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	void AddEventListener( bool* input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
*	@param value 引数
*/
	void RemoveEventListener( bool* input , CScene *_scene);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*/
	void DrawLoop();

	bool useKey;///<  @brief 説明
	bool useMouse;///<  @brief 説明
	int mouseX;///<  @brief 説明
	int mouseY;///<  @brief 説明
private:
	CKeyIn keyTemp;///<  @brief 説明
	std::vector<CKeyIn> keyTask;///<  @brief 説明

	CMouseIn mouseTemp;///<  @brief 説明
	std::vector<CMouseIn> mouseTask;///<  @brief 説明

	CpMouseIn pMouseTemp;///<  @brief 説明
	std::vector<CpMouseIn> pMouseTask;///<  @brief 説明

	CFrame frameTemp;///<  @brief 説明
	std::vector<CFrame> frameTask;///<  @brief 説明

	CBoolean boolTemp;///<  @brief 説明
	std::vector<CBoolean> boolTask;///<  @brief 説明

	std::vector<CKeyIn> keyTask_Draw;///<  @brief 説明
	std::vector<CMouseIn> mouseTask_Draw;///<  @brief 説明
	std::vector<CpMouseIn> pMouseTask_Draw;///<  @brief 説明
	std::vector<CFrame> frameTask_Draw;///<  @brief 説明
	std::vector<CBoolean> boolTask_Draw;///<  @brief 説明

	bool mouseInput;///<  @brief 説明
	bool preMouseInput;///<  @brief 説明
};



}