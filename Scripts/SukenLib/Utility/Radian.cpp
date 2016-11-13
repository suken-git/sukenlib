#include"Radian.h"

double suken::DegToRad(double deg) {
	return deg / 180 * 3.14159265358979323846;
}

float suken::DegToRad(float deg) {
	return deg / 180 * 3.14159265358979323846f;
}

float suken::DegToRad(int deg) {
	return (float)deg / 180 * 3.14159265358979323846f;
}

suken::CRadian::CRadian() {
	value = 0.0;
}

suken::CRadian::CRadian(int deg) {
	value = DegToRad((float)deg);
	this->Adjust();
}

suken::CRadian::CRadian(double rad) {
	value = rad;
	this->Adjust();
}

void suken::CRadian::Adjust() {
	while (value < 0) {
		value += DegToRad((double)360);
	}
	while (value >= DegToRad((double)360)) {
		value -= DegToRad((double)360);
	}
}

void suken::CRadian::Reverse() {
	value += suken::DegToRad(180);
	Adjust();
}

bool suken::CRadian::Compare(double radA, double radB) {
	if (radA < radB) {
		if (radA < this->value && this->value < radB) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA < this->value || this->value < radB) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool suken::CRadian::Compare(CRadian radA, CRadian radB) {
	if (radA() < radB()) {
		if (radA() < this->value && this->value < radB()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA() < this->value || this->value < radB()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool suken::CRadian::CompareE(double radA, double radB) {
	if (radA < radB) {
		if (radA <= this->value && this->value <= radB) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA <= this->value || this->value <= radB) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool suken::CRadian::CompareE(CRadian radA, CRadian radB) {
	if (radA() < radB()) {
		if (radA() <= this->value && this->value <= radB()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA() <= this->value || this->value <= radB()) {
			return true;
		}
		else {
			return false;
		}
	}
}

double suken::CRadian::Sin() {
	return sin(value);
}
double suken::CRadian::Cos() {
	return cos(value);
}
double suken::CRadian::Tan() {
	return tan(value);
}

suken::CRadian suken::CRadian::operator ,(CRadian rad) {
	return rad;
}

suken::CRadian suken::CRadian::operator !() {
	CRadian buf(*this);
	buf.Reverse();
	return buf;
}

double suken::CRadian::operator ()() {
	return this->value;
}

suken::CRadian::operator float() {
	return (float)this->value;
}

suken::CRadian::operator double() {
	return this->value;
}

suken::CRadian::operator suken::CRadianF() {
	suken::CRadianF buf((float)this->value);
	return buf;
}

bool suken::CRadian::operator ==(double rad) {
	return this->value == rad;
}

bool suken::CRadian::operator ==(CRadian rad) {
	return this->value == rad.value;
}

bool suken::CRadian::operator !=(double rad) {
	return !(this->value == rad);
}

bool suken::CRadian::operator !=(CRadian rad) {
	return !(this->value == rad.value);
}

suken::CRadian suken::CRadian::operator *=(int num) {
	this->value *= num;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator *=(double rad) {
	this->value *= rad;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator *=(CRadian rad) {
	this->value *= rad.value;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator *(int num) {
	CRadian buf(*this);
	buf *= num;
	return buf;
}

suken::CRadian suken::CRadian::operator *(double rad) {
	CRadian buf(*this);
	buf *= rad;
	return buf;
}

suken::CRadian suken::CRadian::operator *(CRadian rad) {
	CRadian buf(*this);
	buf *= rad;
	return buf;
}

suken::CRadian suken::CRadian::operator +=(double rad) {
	this->value += rad;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator +=(CRadian rad) {
	this->value += rad.value;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator +(double rad) {
	CRadian buf(*this);
	buf += rad;
	return buf;
}

suken::CRadian suken::CRadian::operator +(CRadian rad) {
	CRadian buf(*this);
	buf += rad;
	return buf;
}

suken::CRadian suken::CRadian::operator +() {
	return *this;
}

suken::CRadian suken::CRadian::operator -=(double rad) {
	this->value -= rad;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator -=(CRadian rad) {
	this->value -= rad.value;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator -(double rad) {
	CRadian buf(*this);
	buf -= rad;
	return buf;
}

suken::CRadian suken::CRadian::operator -(CRadian rad) {
	CRadian buf(*this);
	buf -= rad;
	return buf;
}

suken::CRadian suken::CRadian::operator -() {
	CRadian buf(*this);
	buf.value = -buf.value;
	buf.Adjust();
	return buf;
}

suken::CRadian suken::CRadian::operator /=(int num) {
	this->value /= num;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator /=(double rad) {
	this->value /= rad;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator /=(CRadian rad) {
	this->value /= rad.value;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator /(int num) {
	CRadian buf(*this);
	buf /= num;
	return buf;
}

suken::CRadian suken::CRadian::operator /(double rad) {
	CRadian buf(*this);
	buf /= rad;
	return buf;
}

suken::CRadian suken::CRadian::operator /(CRadian rad) {
	CRadian buf(*this);
	buf /= rad;
	return buf;
}

suken::CRadian suken::CRadian::operator =(double rad) {
	this->value = rad;
	this->Adjust();
	return *this;
}

suken::CRadian suken::CRadian::operator =(CRadian rad) {
	this->value = rad.value;
	this->Adjust();
	return *this;
}

suken::CRadianF::CRadianF() {
	value = 0.0f;
}

suken::CRadianF::CRadianF(int deg) {
	value = DegToRad((float)deg);
	this->Adjust();
}

suken::CRadianF::CRadianF(float rad) {
	value = rad;
	this->Adjust();
}

void suken::CRadianF::Adjust() {
	while (value < 0) {
		value += DegToRad((float)360);
	}
	while (value >= DegToRad((float)360)) {
		value -= DegToRad((float)360);
	}
}

void suken::CRadianF::Reverse() {
	value += suken::DegToRad(180);
	Adjust();
}

bool suken::CRadianF::Compare(float radA, float radB) {
	if (radA < radB) {
		if (radA < this->value && this->value < radB) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA < this->value || this->value < radB) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool suken::CRadianF::Compare(CRadianF radA, CRadianF radB) {
	if (radA() < radB()) {
		if (radA() < this->value && this->value < radB()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA() < this->value || this->value < radB()) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool suken::CRadianF::CompareE(float radA, float radB) {
	if (radA < radB) {
		if (radA <= this->value && this->value <= radB) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA <= this->value || this->value <= radB) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool suken::CRadianF::CompareE(CRadianF radA, CRadianF radB) {
	if (radA() < radB()) {
		if (radA() <= this->value && this->value <= radB()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (radA() <= this->value || this->value <= radB()) {
			return true;
		}
		else {
			return false;
		}
	}
}

float suken::CRadianF::Sin() {
	return sinf(value);
}
float suken::CRadianF::Cos() {
	return cosf(value);
}
float suken::CRadianF::Tan() {
	return tanf(value);
}

suken::CRadianF suken::CRadianF::operator ,(CRadianF rad) {
	return rad;
}

suken::CRadianF suken::CRadianF::operator !() {
	CRadianF buf(*this);
	buf.Reverse();
	return buf;
}

float suken::CRadianF::operator ()() {
	return this->value;
}

suken::CRadianF::operator float() {
	return (float)this->value;
}

suken::CRadianF::operator double() {
	return this->value;
}

suken::CRadianF::operator suken::CRadian() {
	suken::CRadian buf((double)this->value);
	return buf;
}

bool suken::CRadianF::operator ==(float rad) {
	return this->value == rad;
}

bool suken::CRadianF::operator ==(CRadianF rad) {
	return this->value == rad.value;
}

bool suken::CRadianF::operator !=(float rad) {
	return !(this->value == rad);
}

bool suken::CRadianF::operator !=(CRadianF rad) {
	return !(this->value == rad.value);
}

suken::CRadianF suken::CRadianF::operator *=(int num) {
	this->value *= num;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator *=(float rad) {
	this->value *= rad;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator *=(CRadianF rad) {
	this->value *= rad.value;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator *(int num) {
	CRadianF buf(*this);
	buf *= num;
	return buf;
}

suken::CRadianF suken::CRadianF::operator *(float rad) {
	CRadianF buf(*this);
	buf *= rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator *(CRadianF rad) {
	CRadianF buf(*this);
	buf *= rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator +=(float rad) {
	this->value += rad;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator +=(CRadianF rad) {
	this->value += rad.value;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator +(float rad) {
	CRadianF buf(*this);
	buf += rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator +(CRadianF rad) {
	CRadianF buf(*this);
	buf += rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator +() {
	return *this;
}

suken::CRadianF suken::CRadianF::operator -=(float rad) {
	this->value -= rad;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator -=(CRadianF rad) {
	this->value -= rad.value;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator -(float rad) {
	CRadianF buf(*this);
	buf -= rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator -(CRadianF rad) {
	CRadianF buf(*this);
	buf -= rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator -() {
	CRadianF buf(*this);
	buf.value = -buf.value;
	buf.Adjust();
	return buf;
}

suken::CRadianF suken::CRadianF::operator /=(int num) {
	this->value /= num;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator /=(float rad) {
	this->value /= rad;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator /=(CRadianF rad) {
	this->value /= rad.value;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator /(int num) {
	CRadianF buf(*this);
	buf /= num;
	return buf;
}

suken::CRadianF suken::CRadianF::operator /(float rad) {
	CRadianF buf(*this);
	buf /= rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator /(CRadianF rad) {
	CRadianF buf(*this);
	buf /= rad;
	return buf;
}

suken::CRadianF suken::CRadianF::operator =(float rad) {
	this->value = rad;
	this->Adjust();
	return *this;
}

suken::CRadianF suken::CRadianF::operator =(CRadianF rad) {
	this->value = rad.value;
	this->Adjust();
	return *this;
}