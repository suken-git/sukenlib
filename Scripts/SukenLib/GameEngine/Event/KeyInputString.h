#pragma once
#include"../../Manager.h"
#include <DxLib.h>
#include <string>

namespace suken {

	class CKeyInput {
	public:
		CKeyInput();

		~CKeyInput();

		void Draw(int x, int y, bool activeOnly = false);

		void Actve();

		int GetWidth();

		bool GetActive();

		void SetFont(const char* font, int thick = 1, bool ItalicFlag = false, int fontType = -1, int edgeSize = -1);

		static void SetColor(unsigned int color, unsigned int edgeColor = 0, unsigned int backColor = 0xFFFFFF, unsigned int backEdgeColor = 0);
	protected:
		std::string str;
		int size;
		int width, height;
		int font;
		int num;
		bool fActive;

		static bool fActiveElse;
		static unsigned int color, edgeColor, backColor,backEdgeColor;

		virtual void KeyInput();
		void Add(const char* c);
	};

	class CKeyInputNum : public CKeyInput {
	public:
		CKeyInputNum();
		CKeyInputNum(int* link, char size, int height,const char* font = nullptr);

	private:
		int* link;

		void KeyInput();
	};

	class CKeyInputString : public CKeyInput {
	public:
		CKeyInputString();
		CKeyInputString(std::string* link, char size, int height, const char* font = nullptr);

	private:
		std::string* link;

		void KeyInput();
	};
}