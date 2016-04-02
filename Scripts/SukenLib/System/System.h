#pragma once
#include <vector>
#include "DxLib.h"
#include <Manager.h>

namespace suken{

class CSystem{
public:
/**
*	@brief 説明
*/
	CSystem();
/**
*	@brief 説明
*/
	~CSystem();
/**
*	@brief 説明
*/
	void Awake();
/**
*	@brief 説明
* @return 戻り値
*/
	int  GetLocalStandardTime();
/**
*	@brief 説明
*	@param value 引数
*/
	void SetUseThread_Awake(bool flag);
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetUseThread_Awake();
/**
*	@brief 説明
*	@param value 引数
*/
	void SetLoadingGraph(const char *path);
/**
*	@brief 説明
*	@param value 引数
*/
	void SetLoadingMinimalTime(int time);
/**
*	@brief 説明
*/
	void Wait_Loading();
/**
*	@brief 説明
*/
	void Update();
/**
*	@brief 説明
*/
	void Wait();
/**
*	@brief 説明
*/
	void End();
/**
*	@brief 説明
*/
	void TakeScreenShot();
/**
*	@brief 説明
*	@param value 引数
*/
	void GetScreenShot(int *GrHandleAdress);
/**
*	@brief 説明
*/
	void Escape();
/**
*	@brief 説明
* @return 戻り値
*/
	bool GetEscapeFlag();
/**
*	@brief 説明
* @return 戻り値
*/
	int GetFrame();
/**
*	@brief 説明
* @return 戻り値
*/
	int GetNow();
/**
*	@brief 説明
* @return 戻り値
*/
	float GetFps();
/**
*	@brief 説明
* @return 戻り値
*/
	int GetRefreshRate();
/**
*	@brief 説明
*	@param value 引数
*/
	void SetTargetFps(float _fps);
/**
*	@brief 説明
*	@param value 引数
* @return 戻り値
*/
	float GetTargetFps();
/**
*	@brief 説明 //新しいスレッドを作る
*	@param value 引数
*/
	void CreateNewThread( void(*pFunc)() );
/**
*	@brief 説明
* @return 戻り値
*/
	HDC GetDisplayDC();
#ifdef USE_LUA
/**
*	@brief 説明
* @return 戻り値
*/
	lua_State* GetLua();
#endif
private:
	HDC display ;//ディスプレイドライバ
	int frame;
	int count;
	int startTime;
	int localStandardTime;
	int N;			//Nフレームに一回fpsを算出する
	float fps;
	float targetFps;
	int now;
	int refreshRate;
	std::vector<HANDLE> handleChild;
	bool escapeFlag;
	int screenShot;
	bool screenShotFlag;
	int *screenShotGrHandleAdress;
	char loadingImgPath[256];
	int loadingImg;
	bool useThread_AwakeFlag;
	int loadingMinimalTime;
#ifdef USE_LUA
	lua_State *Lua;
#endif
};
}
//Singleton
extern suken::CSystem System;
