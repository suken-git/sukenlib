#include"Picture.h"

suken::CPicture::CPicture() {
	number = 0;
}

suken::CPicture::CPicture(const char* File) {
	int buf;
	buf = LoadGraph(File);
	handle.push_back(buf);
	number = 0;
	GetGraphSize(handle[0], &sizeX, &sizeY);
}

suken::CPicture::CPicture(const char* File, int num, int Xnum, int Ynum, int Xsize, int Ysize) {
	number = num < 1 ? 1 : num;
	int* buf = new int[number];
	LoadDivGraph(File, num, Xnum, Ynum, Xsize, Ysize, buf);
	for (int i = 0; i < number; i++) {
		handle.push_back(buf[i]);
	}
	GetGraphSize(handle[0], &sizeX, &sizeY);
	delete[] buf;
}

suken::CPicture::~CPicture() {
}

void suken::CPicture::Set(const char* File) {
	if (handle.empty()) {
		int buf;
		buf = LoadGraph(File);
		handle.push_back(buf);
		GetGraphSize(handle[0], &sizeX, &sizeY);
	}
	else {
		handle.clear();
		int buf;
		buf = LoadGraph(File);
		handle.push_back(buf);
		GetGraphSize(handle[0], &sizeX, &sizeY);
	}
}

void suken::CPicture::Set(const char* File, int num, int Xnum, int Ynum, int Xsize, int Ysize) {
	if (handle.empty()) {
		number = num < 1 ? 1 : num;
		int* buf = new int[number];
		LoadDivGraph(File, num, Xnum, Ynum, Xsize, Ysize, buf);
		for (int i = 0; i < number; i++) {
			handle.push_back(buf[i]);
		}
		GetGraphSize(handle[0], &sizeX, &sizeY);
		delete[] buf;
	}
	else {
		handle.clear();
		number = num < 1 ? 1 : num;
		int* buf = new int[number];
		LoadDivGraph(File, num, Xnum, Ynum, Xsize, Ysize, buf);
		for (int i = 0; i < number; i++) {
			handle.push_back(buf[i]);
		}
		GetGraphSize(handle[0], &sizeX, &sizeY);
		delete[] buf;
	}
}

void suken::CPicture::Draw() {
	DrawGraph(0, 0, handle[0], true);
}
void suken::CPicture::Draw(int num) {
	DrawGraph(0, 0, handle[num], true);
}


void suken::CPicture::Draw(int x, int y, bool turnFlag) {
	if (turnFlag == 0) {
		DrawGraph(x, y, handle[0], true);
	}
	else {
		DrawTurnGraph(x, y, handle[0], true);
	}
}

void suken::CPicture::Draw(Vector2D v, bool turnFlag) {
	if (turnFlag == 0) {
		DrawGraph(v.x, v.y, handle[0], true);
	}
	else {
		DrawTurnGraph(v.x, v.y, handle[0], true);
	}
}

void suken::CPicture::Draw(int x, int y, int num, bool turnFlag) {
	if (turnFlag == 0) {
		DrawGraph(x, y, handle[num], true);
	}
	else {
		DrawTurnGraph(x, y, handle[num], true);
	}
}

void suken::CPicture::Draw(Vector2D v, int num, bool turnFlag) {
	if (turnFlag == 0) {
		DrawGraph(v.x, v.y, handle[num], true);
	}
	else {
		DrawTurnGraph(v.x, v.y, handle[num], true);
	}
}

void suken::CPicture::DrawRota(int x, int y, double angle, bool turnFlag) {
	DrawRotaGraphF(x, y, 1, angle, handle[0], true, turnFlag);
}

void suken::CPicture::DrawRota(Vector2D v, double angle, bool turnFlag) {
	DrawRotaGraphF(v.x, v.y, 1, angle, handle[0], true, turnFlag);
}

void suken::CPicture::DrawRota(int x, int y, double angle, int num, bool turnFlag) {
	DrawRotaGraph(x, y, 1, angle, handle[num], true, turnFlag);
}

void suken::CPicture::DrawRota(Vector2D v, double angle, int num, bool turnFlag) {
	DrawRotaGraph(v.x, v.y, 1, angle, handle[num], true, turnFlag);
}

void suken::CPicture::DrawExtend(int x1, int y1, int x2, int y2) {
	DrawExtendGraph(x1, y1, x2, y2, handle[0], true);
}

void suken::CPicture::DrawExtend(Vector2D v1, Vector2D v2) {
	DrawExtendGraph(v1.x, v1.y, v2.x, v2.y, handle[0], true);
}

void suken::CPicture::DrawExtend(int x1, int y1, int x2, int y2, int num) {
	DrawExtendGraph(x1, y1, x2, y2, handle[num], true);
}

void suken::CPicture::DrawExtend(Vector2D v1, Vector2D v2, int num) {
	DrawExtendGraph(v1.x, v1.y, v2.x, v2.y, handle[num], true);
}

int suken::CPicture::GetSizeX() {
	return sizeX;
}

int suken::CPicture::GetSizeY() {
	return sizeY;
}

int suken::CPicture::GetHandle(int num) {
	return handle[num];
}