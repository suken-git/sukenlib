#pragma once
#include <vector>
#include "DxLib.h"
#include <Manager.h>
extern suken::CSystem System;

namespace suken{

class CSystem{
public:
	CSystem();
	~CSystem();
	void Awake();
	int  GetLocalStandardTime();
	void SetUseThread_Awake(bool flag);
	bool GetUseThread_Awake();
	void SetLoadingGraph(const char *path);
	void SetLoadingMinimalTime(int time);
	void Wait_Loading();
	void Update();
	void Wait();
	void End();
	void TakeScreenShot();
	void GetScreenShot(int *GrHandleAdress);
	void Escape();
	bool GetEscapeFlag();
	int GetFrame();
	int GetNow();
	float GetFps();
	int GetRefreshRate();
	void SetTargetFps(float _fps);
	float GetTargetFps();
	//新しいスレッドを作る。
	void CreateNewThread( void(*pFunc)() );
	HDC GetDisplayDC();
#ifdef USE_LUA
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

