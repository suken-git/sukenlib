#include"Debug.h"
#include"Manager.h"
#include"../System/System.h"

suken::CDebugWindow debug;

// メッセージ処理用関数
LRESULT CALLBACK suken::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		//System.Escape();
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}



void suken::CDebugWindow::Awake(HINSTANCE hInstance, HINSTANCE hPreInst, int nCmdShow) {
#ifdef DEBUG
	// ウインドウの作成
	if (!hPreInst)
	{
		myProg.style = CS_HREDRAW | CS_VREDRAW;
		myProg.lpfnWndProc = WndProc;
		myProg.cbClsExtra = 0;
		myProg.cbWndExtra = 0;
		myProg.hInstance = hInstance;
		myProg.hIcon = NULL;
		myProg.hCursor = LoadCursor(NULL, IDC_ARROW);
		myProg.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		myProg.lpszMenuName = NULL;
		myProg.lpszClassName = "ウインドウ・クラスネーム";
		if (RegisterClass(&myProg) == FALSE)
		{
			System.Escape();
		}


	}

	hWnd = CreateWindow(
		"ウインドウ・クラスネーム",
		"デバッグウインドウ -SukenLibrary-",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	// SetWindowPos関数
	::SetWindowPos(hWnd, NULL, System.GetDispX() - 100 - (System.GetDispX() - System.GetWindowX() - 100) / 2, (System.GetDispY() - System.GetWindowY()) / 2, 100, System.GetWindowY(), NULL);
	::SetWindowPos(DxLib::GetMainWindowHandle(), NULL, (System.GetDispX() - System.GetWindowX() - 100) / 2, (System.GetDispY() - System.GetWindowY()) / 2, System.GetWindowX(), System.GetWindowY(), NULL);

	UpdateWindow(hWnd);
	device = GetDC(hWnd);
#endif
}


void suken::CDebugWindow::Loop()
{
#ifdef DEBUG

	//メッセージ処理
	if (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	count = 0;

	if(!judge.empty())
	{
		for (int i = count; i < judge.size() + count; i++) {
			if(judge[i].flag == false){
				TextOut(device, 0, 20 * i, judge[i].str.c_str(), strlen(judge[i].str.c_str()));
			}else{
				SetTextColor(device,RGB(255,0,0));
				TextOut(device, 0, 20 * i, judge[i].str.c_str(), strlen(judge[i].str.c_str()));
				SetTextColor(device,RGB(0,0,0));
			}
		}
		count += judge.size();
		judge.clear();
	}

	if (!message.empty())
	{
		
		for (int i = 0; i < message.size(); i++)
		{
			TextOut(device, 0, 20 * (i+ count), message[i].c_str(), strlen(message[i].c_str()));
		}
		count + message.size();
		message.clear();
	}

	UpdateWindow(hWnd);
#endif // DEBUG
}


void suken::CDebugWindow::Print(const char* format, ...)
{
#ifdef DEBUG
	va_list args;
	char temp[256];
	va_start(args, format);
	vsprintf(temp,format, args);
	va_end(args);
	std::string str(temp);
	message.push_back(str);
#endif // DEBUG
}

void suken::CDebugWindow::PrintValue(const char* format,int value)
{
#ifdef DEBUG
	std::string str = format;
	str += " : %d";
	Print(str.c_str(),value);
#endif // DEBUG
}

void suken::CDebugWindow::PrintValue(const char* format,float value)
{
#ifdef DEBUG
	std::string str = format;
	str += " : %f";
	Print(str.c_str(),value);
#endif // DEBUG
}

void suken::CDebugWindow::PrintValue(const char* format,double value)
{
#ifdef DEBUG
	std::string str = format;
	str += " : %f";
	Print(str.c_str(),value);
#endif // DEBUG
}

void suken::CDebugWindow::PrintJudge(bool flag, const char* format)

{
#ifdef DEBUG
	std::string str(format);
	JudgeIn temp;
	temp.str = str;
	temp.flag = flag;
	judge.push_back(temp);
#endif // DEBUG
}

void suken::CDebugWindow::PrintKeyPush(int key, const char* format)

{
#ifdef DEBUG
	std::string str = "PUSH / ";
	str += format;
	PrintJudge(Event.key.GetPush(key),str.c_str());
#endif // DEBUG
}

void suken::CDebugWindow::PrintKeyUp(int key, const char* format)

{
#ifdef DEBUG
	std::string str = "UP / ";
	str += format;
	PrintJudge(Event.key.GetUp(key),str.c_str());
#endif // DEBUG
}

void suken::CDebugWindow::PrintKeyDown(int key, const char* format)

{
#ifdef DEBUG
	std::string str = "DOWN / ";
	str += format;
	PrintJudge(Event.key.GetDown(key),str.c_str());
#endif // DEBUG
}

suken::CDebugWindow::CDebugWindow() {

}

suken::CDebugWindow::~CDebugWindow() {
#ifdef DEBUG
	ReleaseDC(hWnd, device);
#endif // DEBUG
}