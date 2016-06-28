#pragma once
#include"../../Manager.h"
namespace suken{


//���͗p�f�[�^�N���X
class CKeyIn{
public:
/**
*	@brief ����
*/
	CKeyIn()
{
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	
	int keyCode;///<  @brief ����
	void (*pFuncVoid)();///<  @brief ����
	void (*pFuncInt)(int);///<  @brief ����
	int *pInt;///<  @brief ����
	int Int;///<  @brief ����
	CScene *pScene;///<  @brief ����
	
};
class CMouseIn{
public:
/**
*	@brief ����
*/
	CMouseIn()
{
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	int x1,x2,y1,y2;///<  @brief ����
	void (*pFuncVoid)();///<  @brief ����
	void (*pFuncInt)(int);///<  @brief ����
	int *pInt;///<  @brief ����
	int Int;///<  @brief ����
	CScene *pScene;///<  @brief ����
	int type;///<  @brief ����
	
};
class CpMouseIn{
public:
/**
*	@brief ����
*/
	CpMouseIn()
{
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	int *x1,*x2,*y1,*y2;///<  @brief ����
	void (*pFuncVoid)();///<  @brief ����
	void (*pFuncInt)(int);///<  @brief ����
	int *pInt;///<  @brief ����
	int Int;///<  @brief ����
	CScene *pScene;///<  @brief ����
	int type;///<  @brief ����
	
};
class CKeyBoolIn{
public:
	int keyCode;///<  @brief ����
	bool *pBool;///<  @brief ����
};
class CMouseBoolIn{
public:
	int x1,x2,y1,y2;///<  @brief ����
	bool *pBool;///<  @brief ����
	int type;///<  @brief ����
	

};
class CpMouseBoolIn{
public:
	int *x1,*x2,*y1,*y2;///<  @brief ����
	bool *pBool;///<  @brief ����
	int type;///<  @brief ����
	
};
class CFrame{
public:
/**
*	@brief ����
*/
	CFrame()
{
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	void (*pFuncVoid)();///<  @brief ����
	void (*pFuncInt)(int);///<  @brief ����
	int *pInt;///<  @brief ����
	int Int;///<  @brief ����
	CScene *pScene;///<  @brief ����
};
class CBoolean{
public:
/**
*	@brief ����
*/
	CBoolean()
{
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	void (*pFuncVoid)();///<  @brief ����
	void (*pFuncInt)(int);///<  @brief ����
	int *pInt;///<  @brief ����
	int Int;///<  @brief ����
	CScene *pScene;///<  @brief ����
	bool* pBool;///<  @brief ����
};


}