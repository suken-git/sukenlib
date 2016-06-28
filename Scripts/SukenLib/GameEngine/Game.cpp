#include"Game.h"
#include"../System/System.h"
//Singleton
suken::CGame Game;

const int ZOOM_OUT_TIME = 30;
const int ZOOM_UP_TIME = 30;
const int ADD_TIME = 28;
const int REMOVE_TIME = 30;
const int SCROLL_SPEED = 5;
suken::CGame::CGame()
{
	useDrawLoopFlag = true;
	rootScene.ResetSceneNum();
#ifdef SCENE_TRANSITION_ANIMATION
	IsSceneTransition = false;
#endif
}
suken::CGame::~CGame()
{
	/*
		if(memoryLeakChecker!=0){
			char info[256];
			sprintf(info,"error : %d件のメモリリークが発生しています",memoryLeakChecker);
			MessageBox(nullptr,info,"MemoryLeakChecher",MB_OK);
		}
		*/
	rootScene.SetFocus(true);
}
void awake()
{

}
void suken::CGame::AddChild(CScene* _scene)
{
	std::pair<SCENE_OPERATION_COMMAND, CScene*> command;
	command.first = SCENE_OPERATION_COMMAND::ADD;
	command.second = _scene;
	commandQueue.push(command);
#ifdef SCENE_TRANSITION_ANIMATION
	ClearDrawScreen();
	_scene->Loop();
	ScreenFlip();
	System.GetScreenShot(&_scene->screenShot);
#endif
}
void suken::CGame::RemoveChild(CScene* _scene)
{

	std::pair<SCENE_OPERATION_COMMAND, CScene*> command;
	command.first = SCENE_OPERATION_COMMAND::REMOVE;
	command.second = _scene;
	commandQueue.push(command);
#ifdef SCENE_TRANSITION_ANIMATION
	//スクリーンショット
	if (commandQueue.front().second == GetCurrentScene())
	{
		System.GetScreenShot(&GetCurrentScene()->screenShot);
	}
#endif

}
void suken::CGame::RemoveChild()
{
	std::pair<SCENE_OPERATION_COMMAND, CScene*> command;
	command.first = SCENE_OPERATION_COMMAND::REMOVE;
	command.second = nullptr;
	commandQueue.push(command);
#ifdef SCENE_TRANSITION_ANIMATION
	//スクリーンショット
	System.GetScreenShot(&this->GetCurrentScene()->screenShot);
#endif

}
void suken::CGame::Loop()
{

	
#ifdef SCENE_TRANSITION_ANIMATION
	if (transAnimCount == 30) {
		float h = (float)System.GetWindowY();
		float w = (float)System.GetWindowX();
	}
	if (!IsSceneTransition) {
#endif
		Event.Loop();

		if (!sceneChild.size() == 0) {

			sceneChild.back()->Loop();

		}
		else {

			rootScene.Loop();

		}
#ifdef SCENE_TRANSITION_ANIMATION
	}
	else {
		
		if (transAnimCount == 30) {
			float h = (float)System.GetWindowY();
			float w = (float)System.GetWindowX();
		}
		//DxLib::DrawString(300,0,"TRANSITION",GetColor(255,255,0));
		if (!Game.commandQueue.empty())
		{
			transAnimCount++;
			
			float h = (float)System.GetWindowY();
			float w = (float)System.GetWindowX();
			DxLib::DrawBox(0,0,w,h,GetColor(0,0,0),true);
			DrawFormatString(650, 0, GetColor(255, 255, 0), "COUNT : %d", transAnimCount);
			//SCROLL
			if (abs(transAnimScroll - transAnimScrollTarget) > SCROLL_SPEED) {
				if (transAnimScroll - transAnimScrollTarget > 0) {
					transAnimScroll -= SCROLL_SPEED;
				}
				else
				{
					transAnimScroll += SCROLL_SPEED;
				}
			}
			float ratio;
			int x1, x2, y1, y2;
			
			switch (mode)
			{
			case NONE:
				DxLib::DrawString(400, 0, "MODE : NONE", GetColor(255, 255, 0));
				IsSceneTransition = false;
				break;
			case ZOOM_OUT:
				DxLib::DrawString(400, 20, "MODE : ZOOM_OUT", GetColor(255, 255, 0));
				for (int i = 0; i < sceneChild.size(); i++) {
					DrawSceneTransAnim(i,i);
					DxLib::DrawExtendGraph(w - (int)(5 * w / 8) - (sceneChild.size() - i)*(int)(5 * w / 8), (int)(h / 4), w - (int)(w / 8) - (sceneChild.size() - i)*(int)(5 * w / 8), h - (int)(h / 4), sceneChild[i]->screenShot, false);
					//枠
					DxLib::DrawBox(w - (int)(5 * w / 8) - (sceneChild.size() - i)*(int)(5 * w / 8), (int)(h / 4), w - (int)(w / 8) - (sceneChild.size() - i)*(int)(5 * w / 8), h - (int)(h / 4), GetColor(255, 255, 255), false);
				}
				
				//CURRENTSCENE
				CScene *currentScene;
				if (sceneChild.size() > 0) 
				{
					currentScene = sceneChild[sceneChild.size() - 1];
				}
				else {
					currentScene = &rootScene;
				}

				if ( currentScene != &rootScene ) 
				{
					//rootScene
					DxLib::DrawExtendGraph((int)(w - (5.0f * w / 8.0f) - (float)(sceneChild.size() + 1)*(5.0f * w / 8.0f)), (int)(h / 4.0f), (int)(w - (w / 8.0f) - (float)(sceneChild.size() + 1)*(5.0f * w / 8.0f)), (int)(h - (h / 4.0f)), rootScene.screenShot, false);
					//枠
					DxLib::DrawBox(w - (int)(5 * w / 8) - (sceneChild.size() + 1)*(int)(5 * w / 8), (int)(h / 4), w - (int)(w / 8) - (sceneChild.size() + 1)*(int)(5 * w / 8), h - (int)(h / 4), GetColor(255, 255, 255), false);
				}
				ratio = (float)transAnimCount / (float)ZOOM_OUT_TIME;
				x1 = (int)(ratio * ( w - ( 5.0f * w / 8.0f)));
				x2 = (int)(w - (ratio *  w / 8.0f));
				y1 = (int)(ratio * h / 4.0f);
				y2 = (int)(h - ratio * h / 4.0f);
				DxLib::DrawExtendGraph(x1, y1, x2 , y2 , currentScene->screenShot, false);
				//枠
				DxLib::DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), false);

				if (transAnimCount > ZOOM_OUT_TIME)
				{

					if (!commandQueue.empty()) {
						switch (commandQueue.front().first)
						{
						case ADD:
							mode = SCROLL_TO_ADD;
							transAnimScrollTarget = -(int)(16.0f*w / 8.0f);
							break;
						case REMOVE:
							mode = SCROLL_TO_REMOVE;
							break;
						}
						transAnimCount = 0;
					}
					else {
						mode = ZOOM_UP;
						transAnimCount = 0;
					}
				}
				break;
			case ZOOM_UP:
				DxLib::DrawString(400, 40, "MODE : ZOOM_UP", GetColor(255, 255, 0));
				for (int i = 0; i < sceneChild.size(); i++) {
					DrawSceneTransAnim(i, (float)i);
				}
				DrawSceneTransAnim(-1, -1.0f, 0, &rootScene);
				if (!sceneChild.empty()) {
					//CURRENTSCENE
					DxLib::DrawExtendGraph((int)((1.0f - (float)transAnimCount / (float)ZOOM_UP_TIME)*(w - 5.0f * w / 8.0f)), (int)((1.0f - (float)transAnimCount / (float)ZOOM_UP_TIME)*(h / 4.0f)), (int)(w - ((1.0f - (float)transAnimCount / (float)ZOOM_UP_TIME)*(w / 8.0f))), (int)(h - ((1.0f - (float)transAnimCount / (float)ZOOM_UP_TIME)*(h / 4.0f))), sceneChild.back()->screenShot, false);
					//枠
					DxLib::DrawBox((int)((float)(1.0f - transAnimCount / ZOOM_UP_TIME)*(w - (int)(5 * w / 8))), (int)((float)(1.0f - transAnimCount / ZOOM_UP_TIME)*(int)(h / 4)), w - (int)((float)(1.0f - transAnimCount / ZOOM_UP_TIME)*(int)(w / 8)), h - (int)((float)(1.0f - transAnimCount / ZOOM_UP_TIME)*(int)(h / 4)), GetColor(255, 255, 255), true);
				}

				if (transAnimCount > ZOOM_UP_TIME)
				{
					mode = NONE;
				}
				break;
			case REMOVING:
				DxLib::DrawString(400, 60, "MODE : REMOVING", GetColor(255, 255, 0));
				//TODO　REMOVEアニメーション

				if (transAnimCount > REMOVE_TIME && !commandQueue.empty())
				{
					//実際の削除
					if (commandQueue.front().second == nullptr)
					{
						//フォーカス解除
						GetCurrentScene()->SetFocus(false);
						//スクリーンショット
						System.GetScreenShot(&GetCurrentScene()->screenShot);
						//削除
						sceneChild.pop_back();
						//フォーカス移動
						GetCurrentScene()->SetFocus(true);
					}
					else
					{
						//フォーカス解除
						commandQueue.front().second->SetFocus(false);
						//スクリーンショット
						if (commandQueue.front().second == GetCurrentScene())
						{
							System.GetScreenShot(&GetCurrentScene()->screenShot);
						}
						//削除
						std::vector<CScene*>::iterator it = sceneChild.begin();

						while (it != sceneChild.end()) {
							if (*it == commandQueue.front().second) {

								sceneChild.erase(it);
								break;
							}
							it++;
						}
						//フォーカス移動
						GetCurrentScene()->SetFocus(true);



					}
					//
					commandQueue.pop();
					if (!sceneChild.empty()) {
						switch (commandQueue.front().first)
						{
						case ADD:
							mode = SCROLL_TO_ADD;
							break;
						case REMOVE:
							mode = SCROLL_TO_REMOVE;
							break;
						}
					}
					else
					{
						mode = ZOOM_UP;
					}

					transAnimCount = 0;
				}
				break;
			case SCROLL_TO_REMOVE:
				DxLib::DrawString(400, 80, "MODE : SCROLL_TO_REMOVE", GetColor(255, 255, 0));
				break;
			case ADDING:
				if (transAnimCount == 29) {
					int a = 10;
					if (a == 10) {
						int b = 90;
					}
				}
				if (!commandQueue.empty()) {
					DxLib::DrawString(400, 0, "MODE : 10ADDING", GetColor(255, 255, 0));
					//Draw
					for (int i = 0; i < sceneChild.size(); i++) {
						DrawSceneTransAnim(i, (float)i);
					}
					//rootScene
					DrawSceneTransAnim(-1, -1.0f, 0, &rootScene);

					int yDelta = (int)((1.0f - (float)transAnimCount / (float)ADD_TIME)*(float)System.GetWindowY() / 2.0f);
					DrawSceneTransAnim(0, 0, -yDelta, commandQueue.front().second);
					if (transAnimCount > ADD_TIME)
					{
						//フォーカス移動
						GetCurrentScene()->SetFocus(false);
						commandQueue.front().second->SetFocus(true);
						//シーンを追加
						sceneChild.push_back(commandQueue.front().second);

						commandQueue.pop();

						if (!commandQueue.empty()) {
							switch (commandQueue.front().first)
							{
							case ADD:
								mode = SCROLL_TO_ADD;
								break;
							case REMOVE:
								mode = SCROLL_TO_REMOVE;
								break;
							}
						}
						else {
							mode = SCROLL;
							transAnimScrollTarget = 0;
						}
					}
					else
					{
						mode = SCROLL;
					}


					transAnimCount = 0;
				}

				break;
			case SCROLL_TO_ADD:

				DxLib::DrawString(400, 120, "MODE : SCROLL_TO_ADD", GetColor(255, 255, 0));
				if (abs(transAnimScroll - transAnimScrollTarget) <= SCROLL_SPEED) {
					//mode = TRANSITION_ANIMATION_MODE::ADDING;
					//WaitTimer(2000);
				}
				if (CheckHitKey(Event.key.RIGHT)) {
					transAnimScrollTarget -= 30;
				}
				if (CheckHitKey(Event.key.LEFT)) {
					transAnimScrollTarget += 30;
				}
				DrawFormatString(20,100,GetColor(0,255,0),"target : %d",transAnimScrollTarget);
				//Draw
				for (int i = 0; i < sceneChild.size(); i++) {
					DrawSceneTransAnim(i, (float)i);
				}
				//rootScene
				DrawSceneTransAnim(-1, 1.0f, 0, &rootScene);
				//TODO　一つずらして新規シーンの場所をあけるー＞ADD

				break;
			case SCROLL:
				DxLib::DrawString(400, 140, "MODE : SCROLL", GetColor(255, 255, 0));
				if (abs(transAnimScroll - transAnimScrollTarget) <= SCROLL_SPEED) {
					mode = ZOOM_UP;
				}
				//Draw
				for (int i = 0; i < sceneChild.size(); i++) {
					DrawSceneTransAnim(i, -(float)i);
				}
				//rootScene
				DrawSceneTransAnim(-1, -1.0f, 0, &rootScene);
				//TODO 現在のシーンへスクロールしてZOOM_UPへ
				break;
			}
		}
		else {
			IsSceneTransition = false;
		}
		DxLib::DrawBox(500, 500, 550, 550, GetColor(255, 0, 0), true);
	}
#endif

}


void suken::CGame::SetUseDrawLoop(bool flag)
{
	useDrawLoopFlag = flag;
}
bool suken::CGame::GetUseDrawLoop()
{
	return useDrawLoopFlag;
}

suken::CScene *suken::CGame::GetCurrentScene()
{
	if (this->sceneChild.empty())
	{
		return this->rootScene.GetCurrentScene();
	}
	else
	{
		return this->sceneChild.back()->GetCurrentScene();
	}
}

void suken::CGame::ExecuteCommand()
{
#ifndef SCENE_TRANSITION_ANIMATION
	while (!this->commandQueue.empty()) {
		switch (commandQueue.front().first)
		{
		case ADD:
			//フォーカス移動
			GetCurrentScene()->SetFocus(false);
			commandQueue.front().second->SetFocus(true);
			//スクリーンショット
			System.GetScreenShot(&this->GetCurrentScene()->screenShot);
			//シーンを追加
			sceneChild.push_back(commandQueue.front().second);
			//コマンド削除
			commandQueue.pop();
			break;
		case REMOVE:
			if (commandQueue.front().second == nullptr)
			{
				//フォーカス解除
				GetCurrentScene()->SetFocus(false);
				//スクリーンショット
				System.GetScreenShot(&GetCurrentScene()->screenShot);
				//削除
				sceneChild.pop_back();
				//フォーカス移動
				GetCurrentScene()->SetFocus(true);
				//コマンド削除
				commandQueue.pop();
			}
			else
			{
				//フォーカス解除
				commandQueue.front().second->SetFocus(false);
				//スクリーンショット
				if (commandQueue.front().second == GetCurrentScene())
				{
					System.GetScreenShot(&GetCurrentScene()->screenShot);
				}
				//削除
				std::vector<CScene*>::iterator it = sceneChild.begin();

				while (it != sceneChild.end()) {
					if (*it == commandQueue.front().second) {

						sceneChild.erase(it);
						break;
					}
					it++;
				}
				//フォーカス移動
				GetCurrentScene()->SetFocus(true);



			}
			break;
		default:
			break;
		}
	}
#endif
#ifdef SCENE_TRANSITION_ANIMATION
	if (!commandQueue.empty() && !IsSceneTransition)
	{
		mode = ZOOM_OUT;

		System.GetScreenShot(&GetCurrentScene()->screenShot);
		IsSceneTransition = true;
		transAnimCount = 0;
		transAnimScroll = -System.GetWindowX() * 10 / 8;
		transAnimScrollTarget = -System.GetWindowX() * 10 / 8;
	}
#endif
}
#ifdef SCENE_TRANSITION_ANIMATION
void suken::CGame::DrawSceneTransAnim(int sceneNum, float num, int yDelta, suken::CScene *scene)
{
	float h = (float)System.GetWindowY();
	float w = (float)System.GetWindowX();

	int x1 = (int)(w - (num*5.0f * w / 8.0f) + (float)transAnimScroll);
	int x2 = x1 + (int)(w / 2.0f);
	int y1 = yDelta + (int)(h / 4.0f);
	int y2 = y1 + (int)(h / 2.0f);
	if (scene == nullptr) {

		DxLib::DrawExtendGraph(x1, y1, x2, y2, sceneChild[num]->screenShot, false);
		//枠
		DxLib::DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), false);

	}
	else {
		DxLib::DrawExtendGraph(x1, y1, x2, y2, scene->screenShot, false);
		//枠
		DxLib::DrawBox(x1, y1, x2, y2, GetColor(255, 255, 255), false);

	}

}

#endif