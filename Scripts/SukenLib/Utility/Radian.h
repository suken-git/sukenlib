#pragma once

#include"../Manager.h"
#include<math.h>

namespace suken {

	double DegToRad(double deg);

	float DegToRad(float deg);

	float DegToRad(int deg);

	class CRadian {
	private:
		double value;

		void Adjust();
	public:
		CRadian();
		CRadian(int deg);
		CRadian(double rad);

		void Reverse();

		bool Compare(double radA,double radB);
		bool Compare(CRadian radA, CRadian radB);

		bool CompareE(double radA, double radB);
		bool CompareE(CRadian radA, CRadian radB);

		double Sin();
		double Cos();
		double Tan();

		CRadian operator ,(CRadian rad);

		CRadian operator !();

		double operator ()();

		operator float();
		operator double();
		operator suken::CRadianF();

		bool operator ==(double rad);
		bool operator ==(CRadian rad);

		bool operator !=(double rad);
		bool operator !=(CRadian rad);

		CRadian operator *=(int num);
		CRadian operator *=(double rad);
		CRadian operator *=(CRadian rad);

		CRadian operator *(int num);
		CRadian operator *(double rad);
		CRadian operator *(CRadian rad);

		CRadian operator +=(double rad);
		CRadian operator +=(CRadian rad);

		CRadian operator +(double rad);
		CRadian operator +(CRadian rad);

		CRadian operator +();

		CRadian operator -=(double rad);
		CRadian operator -=(CRadian rad);

		CRadian operator -(double rad);
		CRadian operator -(CRadian rad);

		CRadian operator -();

		CRadian operator /=(int num);
		CRadian operator /=(double rad);
		CRadian operator /=(CRadian rad);

		CRadian operator /(int num);
		CRadian operator /(double rad);
		CRadian operator /(CRadian rad);

		CRadian operator =(double rad);
		CRadian operator =(CRadian rad);
	};

	class CRadianF {
	private:
		float value;

		void Adjust();
	public:
		CRadianF();
		CRadianF(int deg);
		CRadianF(float rad);

		void Reverse();

		bool Compare(float radA, float radB);
		bool Compare(CRadianF radA, CRadianF radB);

		bool CompareE(float radA, float radB);
		bool CompareE(CRadianF radA, CRadianF radB);

		float Sin();
		float Cos();
		float Tan();

		CRadianF operator ,(CRadianF rad);

		CRadianF operator !();

		float operator ()();

		operator float();
		operator double();
		operator suken::CRadian();

		bool operator ==(float rad);
		bool operator ==(CRadianF rad);

		bool operator !=(float rad);
		bool operator !=(CRadianF rad);

		CRadianF operator *=(int num);
		CRadianF operator *=(float rad);
		CRadianF operator *=(CRadianF rad);

		CRadianF operator *(int num);
		CRadianF operator *(float rad);
		CRadianF operator *(CRadianF rad);

		CRadianF operator +=(float rad);
		CRadianF operator +=(CRadianF rad);

		CRadianF operator +(float rad);
		CRadianF operator +(CRadianF rad);

		CRadianF operator +();

		CRadianF operator -=(float rad);
		CRadianF operator -=(CRadianF rad);

		CRadianF operator -(float rad);
		CRadianF operator -(CRadianF rad);

		CRadianF operator -();

		CRadianF operator /=(int num);
		CRadianF operator /=(float rad);
		CRadianF operator /=(CRadianF rad);

		CRadianF operator /(int num);
		CRadianF operator /(float rad);
		CRadianF operator /(CRadianF rad);

		CRadianF operator =(float rad);
		CRadianF operator =(CRadianF rad);
	};

}