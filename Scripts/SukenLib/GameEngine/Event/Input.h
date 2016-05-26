#pragma once
#include"EventData.h"
#include <vector>

namespace suken{

	//���̓C�x���g�Ǘ��N���X
class CInput{
public:
/**
*	@brief ����
*/
	CInput();
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( int inputCode , void func() );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( int inputCode , void func(int) , int *pArgument );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( int inputCode , void func(int) , int Argument );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( int inputCode , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( int inputCode , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( int inputCode , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CpMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CpMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( CpMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CpMouseIn input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CpMouseIn input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( CpMouseIn input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( char input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( char input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( char input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( char input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( char input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( char input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( bool* input , void func()  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( bool* input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void AddEventListener( bool* input , void func(int) , int Argument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( bool* input , void func()  );	
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( bool* input , void func(int) , int *pArgument  );
/**
*	@brief ����
*	@param value ����
*/
	void RemoveEventListener( bool* input , void func(int) , int Argument  );
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*/
	void DrawLoop();

	bool useKey;///<  @brief ����
	bool useMouse;///<  @brief ����
	int mouseX;///<  @brief ����
	int mouseY;///<  @brief ����
private:
	CKeyIn keyTemp;///<  @brief ����
	std::vector<CKeyIn> keyTask;///<  @brief ����

	CMouseIn mouseTemp;///<  @brief ����
	std::vector<CMouseIn> mouseTask;///<  @brief ����

	CpMouseIn pMouseTemp;///<  @brief ����
	std::vector<CpMouseIn> pMouseTask;///<  @brief ����

	CFrame frameTemp;///<  @brief ����
	std::vector<CFrame> frameTask;///<  @brief ����

	CBoolean boolTemp;///<  @brief ����
	std::vector<CBoolean> boolTask;///<  @brief ����

	std::vector<CKeyIn> keyTask_Draw;///<  @brief ����
	std::vector<CMouseIn> mouseTask_Draw;///<  @brief ����
	std::vector<CpMouseIn> pMouseTask_Draw;///<  @brief ����
	std::vector<CFrame> frameTask_Draw;///<  @brief ����
	std::vector<CBoolean> boolTask_Draw;///<  @brief ����

	bool mouseInput;///<  @brief ����
	bool preMouseInput;///<  @brief ����
};



}