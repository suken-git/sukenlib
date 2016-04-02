#pragma once

namespace suken{


//入力用データクラス
class CKeyIn{
public:
	CKeyIn(){
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
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
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
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
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
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
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
};
class CBoolean{
public:
	CBoolean(){
		pFuncVoid = nullptr;
		pFuncInt = nullptr;
		pInt = nullptr;
	}
	void (*pFuncVoid)();
	void (*pFuncInt)(int);
	int *pInt;
	int Int;
	bool* pBool;
};


}