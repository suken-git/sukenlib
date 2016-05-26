#pragma once
#include <vector>
#include "Physics\CollosionManager.h"
#include "Event\Input.h"
#include "Event\Event.h"

namespace suken{

class CButton{
public:
	/**
*	@brief ����
*/
	CButton()
{
		IsUseGraph = false;
		IsReact = false;
	}
	std::string title;///<  @brief ����
	int x1,x2,y1,y2;///<  @brief ����
	int backColor,stringColor;///<  @brief ����
	int graphHandle;///<  @brief ����
	bool IsUseGraph;///<  @brief ����
	int graphHandle_on;///<  @brief ����
	int graphHandle_off;///<  @brief ����
	bool IsReact;			///<  @brief ����//�}�E�X�ɔ������邩�ۂ�
};
class CpButton{
public:
/**
*	@brief ����
*/
	CpButton()
{
		IsUseGraph = false;
		IsReact =false;
	}
	std::string title;///<  @brief ����
	int *x1,*x2,*y1,*y2;///<  @brief ����
	int backColor,stringColor;///<  @brief ����
	int graphHandle;///<  @brief ����
	bool IsUseGraph;///<  @brief ����
	int graphHandle_on;///<  @brief ����
	int graphHandle_off;///<  @brief ����
	bool IsReact;			///<  @brief ����//�}�E�X�ɔ������邩�ۂ�
};



//�V�[���N���X
class CScene{
public:
/**
*	@brief ����
*/
	CScene();
/**
*	@brief ����
*/
	void Loop();
/**
*	@brief ����
*/
	void ButtonLoop();
	suken::CCollisionManager collision;///<  @brief ����
	CInput input;///<  @brief ����
	std::vector<CButton> buttonChild;///<  @brief ����
	std::vector<CpButton> pButtonChild;///<  @brief ����
	CScene *sceneChild;///<  @brief ����
/**
*	@brief ����
*	@param value ����
*/
	void SetFocus(bool _focus);
/**
*	@brief ����
* @return �߂�l
*/
	bool GetFocus();
/**
*	@brief ����
*	@param value ����
*/
	void AddChild(CScene *_scene);
/**
*	@brief ����
*/
	void RemoveChild();
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , int graph, void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string graphPath, void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int x1 , int y1 , int x2 , int y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) ,int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int backColor , std::string title , int stringColor , void (*pFunc)(int) ,int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , int graph , void (*pFunc)(int) ,int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)() );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int *pInt );
/**
*	@brief ����
*	@param value ����
*/
	void SetButton( int *x1 , int *y1 , int *x2 , int *y2 , std::string Off_graphPath , std::string On_graphPath , void (*pFunc)(int) , int Int );
/**
*	@brief ����  //�������C�u���������֐��i�g�p�֎~�j
*/
	void ResetSceneNum();
/**
*	@brief ����
* @return �߂�l
*/
	unsigned int GetSerialNum();
private:
	bool focus;///<  @brief ����
	static unsigned int sceneNum;///<  @brief ����
	unsigned int serialNum;///<  @brief ����
};


}