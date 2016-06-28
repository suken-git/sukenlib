#pragma once
#include"../Manager.h"
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
	CButton()
{
		IsUseGraph = false;
		IsReact = false;
	}
	std::string title;///<  @brief 説明
	int x1,x2,y1,y2;///<  @brief 説明
	int backColor,stringColor;///<  @brief 説明
	int graphHandle;///<  @brief 説明
	bool IsUseGraph;///<  @brief 説明
	int graphHandle_on;///<  @brief 説明
	int graphHandle_off;///<  @brief 説明
	bool IsReact;			///<  @brief 説明//マウスに反応するか否か
};
class CpButton{
public:
/**
*	@brief 説明
*/
	CpButton()
{
		IsUseGraph = false;
		IsReact =false;
	}
	std::string title;///<  @brief 説明
	int *x1,*x2,*y1,*y2;///<  @brief 説明
	int backColor,stringColor;///<  @brief 説明
	int graphHandle;///<  @brief 説明
	bool IsUseGraph;///<  @brief 説明
	int graphHandle_on;///<  @brief 説明
	int graphHandle_off;///<  @brief 説明
	bool IsReact;			///<  @brief 説明//マウスに反応するか否か
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
	suken::CCollisionManager collision;///<  @brief 説明
	CInput input;///<  @brief 説明
	std::vector<CButton> buttonChild;///<  @brief 説明
	std::vector<CpButton> pButtonChild;///<  @brief 説明
	CScene *sceneChild;///<  @brief 説明
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , CScene *_scene );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, CScene *_scene );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, CScene *_scene );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , CScene *_scene );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) ,int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) ,int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , CScene *_scene );

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , CScene *_scene);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , CScene *_scene);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)() );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief 説明
*	@param value 引数
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , CScene *_scene);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*	@brief 説明  //数研ライブラリ内部関数（使用禁止）
*/
	void ResetSceneNum();
/**
*	@brief 説明
* @return 戻り値
*/
	unsigned int GetSerialNum();
/**
*	@brief 説明
* @return 戻り値
*/
	CScene *GetCurrentScene();
	int screenShot;
private:
	bool focus;///<  @brief 説明
	static unsigned int sceneNum;///<  @brief 説明
	unsigned int serialNum;///<  @brief 説明
	
};


}