#ifndef CVECTOR2_H
#define CVECTOR2_H

class CVector2{
public:
	float x;
	float y;
	float dot(const CVector2 &v);
	float Length();

	CVector2()
		:x(0.0f)
		, y(0.0f)
	{}

	CVector2(float x, float y)
		:x(x)
		, y(y)
	{}

	const CVector2 operator+(const CVector2 &v)const;

	const CVector2 operator-(const CVector2 &v)const;

	const CVector2 operator*(float f)const;
};


#endif