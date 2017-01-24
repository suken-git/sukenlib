#pragma once
#include"../../Manager.h"
#include <DxLib.h>
#include <string>

namespace suken {

	class CKeyInputNum {
	public:
		CKeyInputNum();
		CKeyInputNum(int* link, char size, int height,const char* font = nullptr);

		~CKeyInputNum();

		void Draw(int x, int y, bool activeOnly = false);

		void Actve();

		void SetFont(const char* font,int color, int thick, bool ItalicFlag = false, int fontType = -1, int edgeSize = -1, int edgeColor = 0);

	private:
		std::string str;
		int* link;
		int size;
		int width,height;
		int font;
		int num;
		bool fActive;
		int color,edgeColor;

		void KeyInput();
		void Add(const char* c);
	};

	class CKeyInputString {
	public:
		CKeyInputString();
		CKeyInputString(std::string* link, char size, int height, const char* font = nullptr);

		~CKeyInputString();

		void Draw(int x, int y, bool activeOnly = false);

		void Actve();

		void SetFont(const char* font, int color, int thick, bool ItalicFlag = false, int fontType = -1, int edgeSize = -1, int edgeColor = 0);

	private:
		std::string str;
		std::string* link;
		int size;
		int width, height;
		int font;
		int num;
		bool fActive;
		int color, edgeColor;

		void KeyInput();
		void Add(const char* c);
	};
}