#ifndef CMATRIX33_H
#define CMATRIX33_H
#include <string.h>
#include "CVector2.h"

class CMatrix33{
public:
	void Identity();

	float m[3][3];
	CMatrix33(){
		Identity();
	}
	void Print();

	void SetRotation(float degree);

	const CVector2 MultiVector2(const CVector2 &v)const;

	void SetTranslate(float x,float y);

	const CMatrix33 MultiMatrix33(const CMatrix33 &a)const;

	const CVector2 operator*(const CVector2 &v)const;

	const CMatrix33 operator*(const CMatrix33 &a)const;

	void SetScale(float x, float y);

};

#endif