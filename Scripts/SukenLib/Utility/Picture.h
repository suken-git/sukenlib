#pragma once

#include<DxLib.h>
#include <vector>
#include "..\GameEngine\Physics\Vector2D.h"

namespace suken {

	class CPicture {
	public:
		CPicture();

		CPicture(const char* File);

		CPicture(const char* File, int num, int Xnum, int Ynum, int Xsize, int Ysize);

		~CPicture();

		void Set(const char* File);

		void Set(const char* File, int num, int Xnum, int Ynum, int Xsize, int Ysize);

		void Draw();

		void Draw(int num);

		void Draw(int x, int y, bool turnFlag = 0);
		void Draw(Vector2D v, bool turnFlag = 0);

		void Draw(int x, int y, int num, bool turnFlag = 0);
		void Draw(Vector2D v, int num, bool turnFlag = 0);

		void DrawRota(int x, int y, double angle, bool turnFlag = 0);
		void DrawRota(Vector2D v, double angle, bool turnFlag = 0);

		void DrawRota(int x, int y, double angle, int num, bool turnFlag = 0);
		void DrawRota(Vector2D v, double angle, int num, bool turnFlag = 0);

		void DrawExtend(int x1, int y1, int x2, int y2);
		void DrawExtend(Vector2D v1, Vector2D v2);

		void DrawExtend(int x1, int y1, int x2, int y2, int num);
		void DrawExtend(Vector2D v1, Vector2D v2, int num);

		int GetSizeX();

		int GetSizeY();

		int GetHandle(int num = 0);

	private:
		std::vector<int> handle;
		int number;
		int sizeX, sizeY;
	};

}