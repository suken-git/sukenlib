#include "KeyInputString.h"
#include "Event.h"

#define Key(Key) if(Event.key.GetDown(Event.key.Key))

bool suken::CKeyInput::fActiveElse = false;
unsigned int suken::CKeyInput::color = 0;
unsigned int suken::CKeyInput::edgeColor = 0;
unsigned int suken::CKeyInput::backColor = 0xFFFFFF;
unsigned int suken::CKeyInput::backEdgeColor = 0;

suken::CKeyInput::CKeyInput() {

}

suken::CKeyInputNum::CKeyInputNum() {
	str = "";
	link = nullptr;
	size = 9;
	width = 0;
	height = 0;
	font = NULL;
	num = 0;
	fActive = false;
	color = 0;
	edgeColor = 0;

	str.reserve(size);
}

suken::CKeyInputNum::CKeyInputNum(int* link, char size, int height, const char* font) {
	str = std::to_string((long long)*link);
	this->link = link;
	this->size = size > 9 ? 9 : size;
	this->height = height;
	this->font = CreateFontToHandle(font, height, -1);
	fActive = false;
	color = 0;
	edgeColor = 0;
	while (str.size() > this->size) {
		str.pop_back();
	}
	num = str.size();
	str.reserve(this->size);
	width = GetDrawStringWidthToHandle(str.c_str(), str.size(),this->font) + 2;
}

suken::CKeyInputString::CKeyInputString() {
	str = "";
	link = nullptr;
	size = 0;
	width = 0;
	height = 0;
	font = NULL;
	num = 0;
	fActive = false;
	color = 0;
	edgeColor = 0;

	str.reserve(size);
}

suken::CKeyInputString::CKeyInputString(std::string* link, char size, int height, const char* font) {
	str = *link;
	this->link = link;
	this->size = size;
	this->height = height;
	this->font = CreateFontToHandle(font, height, -1);
	fActive = false;
	color = 0;
	edgeColor = 0;
	while (str.size() > this->size) {
		str.pop_back();
	}
	num = str.size();
	str.reserve(this->size);
	width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
}

suken::CKeyInput::~CKeyInput() {
	//DeleteFontToHandle(font);
}

void suken::CKeyInput::Add(const char* c) {
	if (str.size() < size) {
		str.insert(num, c);
		width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
		num++;
	}
}

void suken::CKeyInput::Draw(int x, int y, bool activeOnly) {
	if (!activeOnly) {
		if (!fActiveElse) {
			if (str.size() == 0) {
				if (Event.LMouse.GetClick(x, y, x + height, y + height)) {
					fActive = true;
					fActiveElse = true;
				}
			}
			else {
				if (Event.LMouse.GetClick(x, y, x + width, y + height)) {
					fActive = true;
					fActiveElse = true;
				}
			}
		}
	}

	if (fActive) {
		KeyInput();

		DrawBox(x, y, x + width, y + height, backColor, true);
		DrawBox(x, y, x + width, y + height, backEdgeColor, false);
		DrawBox(x + GetDrawStringWidthToHandle(str.c_str(), num, this->font), y + 1, x + GetDrawStringWidthToHandle(str.c_str(), num, this->font) + 2, y + height - 1, 0xFF0000, true);
		DrawStringToHandle(x + 1, y, str.c_str(), color, font, edgeColor);
	}
	else if (!activeOnly) {
		DrawStringToHandle(x + 1, y, str.c_str(), color, font, edgeColor);
	}
}

void suken::CKeyInput::Actve() {
	if (!fActiveElse) {
		fActive = true;
		fActiveElse = true;
	}
}

int suken::CKeyInput::GetWidth() {
	return width;
}

bool suken::CKeyInput::GetActive() {
	return fActive;
}

void suken::CKeyInput::SetFont(const char* font, int thick, bool ItalicFlag, int fontType, int edgeSize) {
	this->font = CreateFontToHandle(font, height, thick, fontType, -1, edgeSize, ItalicFlag);
	width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
}

void suken::CKeyInput::SetColor(unsigned int color, unsigned int edgeColor, unsigned int backColor, unsigned int backEdgeColor) {
	suken::CKeyInput::color = color;
	suken::CKeyInput::edgeColor = edgeColor;
	suken::CKeyInput::backColor = backColor;
	suken::CKeyInput::backEdgeColor = backEdgeColor;
}

void suken::CKeyInput::KeyInput() {

}

void suken::CKeyInputNum::KeyInput() {
	Key(RIGHT) {
		if (num < str.size()) {
			num++;
		}
	}
	Key(LEFT) {
		if (num > 0) {
			num--;
		}
	}

	Key(NUM0)Add("0");
	Key(NUM1)Add("1");
	Key(NUM2)Add("2");
	Key(NUM3)Add("3");
	Key(NUM4)Add("4");
	Key(NUM5)Add("5");
	Key(NUM6)Add("6");
	Key(NUM7)Add("7");
	Key(NUM8)Add("8");
	Key(NUM9)Add("9");

	Key(BACK) {
		if (num != 0) {
			str.erase(str.begin() + (num - 1));
			width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
			num--;
		}
	}

	Key(_DELETE) {
		if (num != str.size()) {
			str.erase(str.begin() + num);
			width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
		}
	}

	Key(ESCAPE) {
		fActive = false;
		fActiveElse = false;
		str = std::to_string((long long)*link);
		num = str.size();
		width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
	}

	Key(RETURN) {
		fActive = false;
		fActiveElse = false;
		*link = atoi(str.c_str());
		str = std::to_string((long long)*link);
		num = str.size();
		width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
	}
}

void suken::CKeyInputString::KeyInput() {
	Key(RIGHT) {
		if (num < str.size()) {
			num++;
		}
	}
	Key(LEFT) {
		if (num > 0) {
			num--;
		}
	}

	Key(NUM0)Add("0");
	Key(NUM1)Add("1");
	Key(NUM2)Add("2");
	Key(NUM3)Add("3");
	Key(NUM4)Add("4");
	Key(NUM5)Add("5");
	Key(NUM6)Add("6");
	Key(NUM7)Add("7");
	Key(NUM8)Add("8");
	Key(NUM9)Add("9");

	if (Event.key.GetPush(Event.key.LSHIFT) || Event.key.GetPush(Event.key.RSHIFT)) {
		Key(A)Add("A");
		Key(B)Add("B");
		Key(C)Add("C");
		Key(D)Add("D");
		Key(E)Add("E");
		Key(F)Add("F");
		Key(G)Add("G");
		Key(H)Add("H");
		Key(I)Add("I");
		Key(J)Add("J");
		Key(K)Add("K");
		Key(L)Add("L");
		Key(M)Add("M");
		Key(N)Add("N");
		Key(O)Add("O");
		Key(P)Add("P");
		Key(Q)Add("Q");
		Key(R)Add("R");
		Key(S)Add("S");
		Key(T)Add("T");
		Key(U)Add("U");
		Key(V)Add("V");
		Key(W)Add("W");
		Key(X)Add("X");
		Key(Y)Add("Y");
		Key(Z)Add("Z");
		Key(BACKSLASH)Add("_");
	}
	else {
		Key(A)Add("a");
		Key(B)Add("b");
		Key(C)Add("c");
		Key(D)Add("d");
		Key(E)Add("e");
		Key(F)Add("f");
		Key(G)Add("g");
		Key(H)Add("h");
		Key(I)Add("i");
		Key(J)Add("j");
		Key(K)Add("k");
		Key(L)Add("l");
		Key(M)Add("m");
		Key(N)Add("n");
		Key(O)Add("o");
		Key(P)Add("p");
		Key(Q)Add("q");
		Key(R)Add("r");
		Key(S)Add("s");
		Key(T)Add("t");
		Key(U)Add("u");
		Key(V)Add("v");
		Key(W)Add("w");
		Key(X)Add("x");
		Key(Y)Add("y");
		Key(Z)Add("z");
	}

	Key(BACK) {
		if (num != 0) {
			str.erase(str.begin() + (num - 1));
			width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
			num--;
		}
	}

	Key(_DELETE) {
		if (num != str.size()) {
			str.erase(str.begin() + num);
			width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
		}
	}

	Key(ESCAPE) {
		fActive = false;
		fActiveElse = false;
		str = *link;
		num = str.size();
		width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
	}

	Key(RETURN) {
		fActive = false;
		fActiveElse = false;
		*link = str;
		num = str.size();
		width = GetDrawStringWidthToHandle(str.c_str(), str.size(), this->font) + 2;
	}
}