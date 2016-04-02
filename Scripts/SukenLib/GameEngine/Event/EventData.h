#pragma once


namespace suken{


//入力用データクラス
class CKeyIn{
public:
	CKeyIn(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	int keyCode;
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
};
class CMouseIn{
public:
	CMouseIn(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	int x1,x2,y1,y2;
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
	int type;
	
};
class CpMouseIn{
public:
	CpMouseIn(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	int *x1,*x2,*y1,*y2;
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
	int type;
	
};
class CKeyBoolIn{
public:
	int keyCode;
	bool *pBool;
};
class CMouseBoolIn{
public:
	int x1,x2,y1,y2;
	bool *pBool;
	int type;
	

};
class CpMouseBoolIn{
public:
	int *x1,*x2,*y1,*y2;
	bool *pBool;
	int type;
	
};
class CFrame{
public:
	CFrame(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
};
class CBoolean{
public:
	CBoolean(){
		pFuncVoid = NULL;
		pFuncInt = NULL;
		pInt = NULL;
	}
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
	bool* pBool;
};


}