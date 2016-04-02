#pragma once
#include <vector>
#include "Physics\CollosionManager.h"
#include "Event\Input.h"
#include "Event\Event.h"

namespace suken{

class CButton{
public:
	/**
*	@brief 説明
*/
	CButton(){
		IsUseGraph = false;
		IsReact = false;
	}
	char *title;
	int x1,x2,y1,y2;
	int backColor,stringColor;
	int graphHandle;
	bool IsUseGraph;
	int graphHandle_on;
	int graphHandle_off;
	bool IsReact;			//マウスに反応するか否か
};
class CpButton{
public:
/**
*	@brief 説明
*/
	CpButton(){
		IsUseGraph = false;
		IsReact =false;
	}
	char *title;
	int *x1,*x2,*y1,*y2;
	int backColor,stringColor;
	int graphHandle;
	bool IsUseGraph;
	int graphHandle_on;
	int graphHandle_off;
	bool IsReact;			//マウスに反応するか否か
};



//シーンクラス
class CScene{
public:
/**
*	@brief 説明
*/
	CScene();
/**
*	@brief 説明
*/
	void Loop();
/**
*	@brief 説明
*/
	void ButtonLoop();
	suken::CCollisionManager collision;
	CInput input;
	std::vector<CButton> buttonChild;
	std::vector<CpButton> pButtonChild;
	CScene *sceneChild;
/**
*	@brief 説明
*	@param value 引数
*/
	void SetFocus(bool _focus);
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetFocus();
/**
*	@brief 説明
*	@param value 引数
*/
	void AddChild(CScene *_scene);
/**
*	@brief 説明
*/
	void RemoveChild();
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* graphPath, void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , char *title , int stringColor , void (*pFunc)(int) ,int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , char* Off_graphPath , char* On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief 説明  //数研ライブラリ内部関数（使用禁止）
*/
	void ResetSceneNum();
/**
*	@brief 説明
* @return 戻り値
*/
	unsigned int GetSerialNum();
private:
	bool focus;
	static unsigned int sceneNum;
	unsigned int serialNum;
};


}