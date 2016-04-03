#pragma once

namespace suken{


//入力用データクラス
class CKeyIn{
public:
/**
*	@brief 説明
*/
	CKeyIn(){
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	int keyCode;///<  @brief 説明
	void (*pFuncVoid)();///<  @brief 説明
	void (*pFuncInt)(int);///<  @brief 説明
	int *pInt;///<  @brief 説明
	int Int;///<  @brief 説明
};
class CMouseIn{
public:
/**
*	@brief 説明
*/
	CMouseIn(){
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	int x1,x2,y1,y2;///<  @brief 説明
	void (*pFuncVoid)();///<  @brief 説明
	void (*pFuncInt)(int);///<  @brief 説明
	int *pInt;///<  @brief 説明
	int Int;///<  @brief 説明
	int type;///<  @brief 説明
	
};
class CpMouseIn{
public:
/**
*	@brief 説明
*/
	CpMouseIn(){
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	int *x1,*x2,*y1,*y2;///<  @brief 説明
	void (*pFuncVoid)();///<  @brief 説明
	void (*pFuncInt)(int);///<  @brief 説明
	int *pInt;///<  @brief 説明
	int Int;///<  @brief 説明
	int type;///<  @brief 説明
	
};
class CKeyBoolIn{
public:
	int keyCode;///<  @brief 説明
	bool *pBool;///<  @brief 説明
};
class CMouseBoolIn{
public:
	int x1,x2,y1,y2;///<  @brief 説明
	bool *pBool;///<  @brief 説明
	int type;///<  @brief 説明
	

};
class CpMouseBoolIn{
public:
	int *x1,*x2,*y1,*y2;///<  @brief 説明
	bool *pBool;///<  @brief 説明
	int type;///<  @brief 説明
	
};
class CFrame{
public:
/**
*	@brief 説明
*/
	CFrame(){
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	void (*pFuncVoid)();///<  @brief 説明
	void (*pFuncInt)(int);///<  @brief 説明
	int *pInt;///<  @brief 説明
	int Int;///<  @brief 説明
};
class CBoolean{
public:
/**
*	@brief 説明
*/
	CBoolean(){
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	void (*pFuncVoid)();///<  @brief 説明
	void (*pFuncInt)(int);///<  @brief 説明
	int *pInt;///<  @brief 説明
	int Int;///<  @brief 説明
	bool* pBool;///<  @brief 説明
};


}