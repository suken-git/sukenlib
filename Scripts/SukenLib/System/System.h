#pragma once
#include <vector>
#include "DxLib.h"
#include "Manager.h"
#include"../GameEngine/Scene.h"

namespace suken {

	class CSystem {
	private:
		int window_w;///<  @brief	ウインドウ幅
		int window_h;///<  @brief	ウインドウ高さ
		int dispX;///<  @brief	ディスプレイ幅
		int dispY;///<  @brief	ディスプレイ高さ
		HDC display;///<  @brief ディスプレイデバイスコンテクストを格納
		int frame;///<  @brief exe開始時からのフレーム数を格納
		int count;///<  @brief フレームレート算出用変数
		int startTime;///<  @brief フレームレート算出用変数
		int localStandardTime;///<  @brief exe開始時からの時間をマイクロ秒で格納
		int N;		///<  @brief フレームレート算出用変数 (Nフレームに一回fpsを算出する)
		float fps;///<  @brief フレームレートを格納
		float targetFps;///<  @brief 理想とするフレームレートを格納（初期値：６０）
		int now;///<  @brief 現フレームが始まった時間を格納
		int refreshRate;///<  @brief 使用中のディスプレイの１秒間の更新回数を格納
		std::vector<HANDLE> handleChild;///<  @brief 作成したスレッドのハンドルを格納
		bool escapeFlag;///<  @brief exeを終了するかどうかのフラグ
		int screenShot;///<  @brief スクリーンショットの画像ハンドルを格納するための入れ物
		bool screenShotFlag;///<  @brief 現フレームのスクリーンショットをとるかどうか
		int *screenShotGrHandleAdress;///<  @brief スクリーンショットの画像ハンドルを格納先の示すint型ポインタを格納
		std::string loadingImgPath;///<  @brief Loading画面に表示する画像のパスを格納
		int loadingImg;///<  @brief Loading画面に表示する画像ハンドルを格納
		bool useThread_AwakeFlag;///<  @brief void Awake()をバックグラウンドで実行するかどうかのフラグ
		int loadingMinimalTime;///<  @brief Loadingに費やす最低時間を格納（マイクロ秒）
		suken::CScene settings;///<  @brief 数研ライブラリの設定に使用するシーン
#ifdef USE_LUA
		lua_State *Lua;///<  @brief 説明
#endif
	public:
		/**
		*	@brief コンストラクタ　メンバ変数などの初期化を行う
		*/
		CSystem();
		/**
		*	@brief デストラクタ　DxLibの後片付け等
		*/
		~CSystem();
		/**
		*	@brief DxLibの初期化、初期設定などを担当
		*/
		void Awake();
		/**
		*	@brief exeが立ち上がってからの時間をマイクロ秒で返す
		* @return exeが立ち上がってからの時間[マイクロ秒]
		*/
		int  GetLocalStandardTime();
		/**
		*	@brief void Awake()をバックグラウンドで実行するかどうかを設定
		*	@param flag true:void Awake()をバックグラウンドで実行する false:通常通り（初期値）
		*/
		void SetUseThread_Awake(bool flag);
		/**
		*	@brief void Awake()をバックグラウンドで実行するかどうかを取得
		* @return true:void Awake()をバックグラウンドで実行する false:通常通り（初期値）
		*/
		bool GetUseThread_Awake();
		/**
		*	@brief ローディング時に表示する画像を指定する
		*	@param path 画像のパス
		*/
		void SetLoadingGraph(const std::string path);
		/**
		*	@brief ローディングの最低時間をマイクロ秒で設定
		*	@param time ローディングの最低時間[マイクロ秒]
		*/
		void SetLoadingMinimalTime(int time);
		/**
		*	@brief システム用関数
		*/
		void Wait_Loading();
		/**
		*	@brief システム用関数
		*/
		void Update();
		/**
		*	@システム用関数
		*/
		void Wait();
		/**
		*	@brief システム用関数
		*/
		void End();
		/**
		*	@brief スクリーンショットが取れるはずの関数（未整備）
		*/
		void TakeScreenShot();
		/**
		*	@brief スクリーンショットが取れるはずの関数（未整備）
		*	@param  GrHandleAdress　スクリーンショットの画像ハンドルを格納先を示すint型ポインタ
		*/
		void GetScreenShot(int *GrHandleAdress);
		/**
		*	@brief この関数を実行することでexeが終了する
		*/
		void Escape();
		/**
		*	@brief exeを終了するかどうかを得る（システム関数）
		* @return true:exeが次フレームで終了する　false:exe実行中
		*/
		bool GetEscapeFlag();
		/**
		*	@brief exeが立ち上がってからのフレーム数を取得
		* @return exeが立ち上がってからのフレーム数
		*/
		int GetFrame();
		/**
		*	@brief 現フレームの始まった時間をマイクロ秒で取得（フレーム内で時間を統一したいときにオススメ）
		* @return 現フレームの始まった時間[マイクロ秒]
		*/
		int GetNow();
		/**
		*	@brief 現在のフレームレートを取得（60フレームに１回更新）
		* @return フレームレート
		*/
		float GetFps();
		/**
		*	@brief 使用中のディスプレイの更新が１秒間に何回行われるかを取得
		* @return ディスプレイのリフレッシュレート
		*/
		int GetRefreshRate();
		/**
		*	@brief 理想となるフレームレートを指定する（処理が重い場合や、指定したフレームレートがディスプレイの更新頻度より高い場合は指定したフレームレートより遅くなります）
		*	@param _fps　理想のフレームレート
		*/
		void SetTargetFps(float _fps);
		/**
		*	@brief 理想となるフレームレートを取得する
		*	@param value 引数
		* @return 戻り値
		*/
		float GetTargetFps();
		/**
		*	@brief 新しいスレッドを作る（exe終了時に正常に解放されます）
		*	@param pFunc 作成したスレッドで実行される関数のポインタ
		*/
		void CreateNewThread(void(*pFunc)());
		/**
		*	@brief ディスプレイのデバイスコンテクストを取得（システム関数）
		* @return ディスプレイのデバイスコンテクスト
		*/
		HDC GetDisplayDC();
#ifdef USE_LUA
		/**
		*	@brief 未整備
		* @return
		*/
		lua_State* GetLua();
#endif
		/**
		*	@brief ウインドウの大きさを設定（WinMain.hの処理設定欄で使用する）
		*	@param width ウインドウ幅
		*	@param height ウインドウ高さ
		*/
		void SetWindowSize(int width, int height);
		/**
		*	@brief ウインドウの幅を得る
		*	@return ウインドウの幅
		*/
		int GetWindowX();
		/**
		*	@brief ウインドウの高さを得る
		*	@return ウインドウの高さ
		*/
		int GetWindowY();
		/**
		*	@brief システムによるフレーム最後の処理を担当
		*/
		void ExitFrame();
		/**
		*	@brief ディスプレイの幅を得る
		*	@return ディスプレイの幅
		*/
		int GetDispX();
		/**
		*	@brief ディスプレイの高さを得る
		*	@return ディスプレイの高さ
		*/
		int GetDispY();
	};
	void SettingLoop();
}
extern suken::CSystem System;