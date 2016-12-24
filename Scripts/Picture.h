#pragma once

#include"Suken.h"

class CPicture {
public:
	CPicture();

	CPicture(char* File);

	CPicture(char* File, int num, int Xnum, int Ynum, int Xsize, int Ysize);

	~CPicture();

	void Set(char* File);

	void Set(char* File, int num, int Xnum, int Ynum, int Xsize, int Ysize);

	void Draw();

	void Draw(int num);

	void Draw(int x, int y, bool turnFlag = 0);

	void Draw(int x, int y, int num, bool turnFlag = 0);

	void DrawRota(int x, int y, double angle, bool turnFlag = 0);

	void DrawRota(int x, int y, double angle, int num, bool turnFlag = 0);

	void DrawExtend(int x1, int y1, int x2, int y2);

	void DrawExtend(int x1, int y1, int x2, int y2, int num);

	int GetSizeX();

	int GetSizeY();

	int GetHandle(int num = 0);

private:
	int *handle;
	int number;
	int sizeX, sizeY;
};