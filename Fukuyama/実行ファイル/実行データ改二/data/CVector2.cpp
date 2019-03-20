#include "CVector2.h"
#include "math.h"

const CVector2 CVector2::operator+(const CVector2 &v)const
{
	return CVector2(x + v.x, y + v.y);
}

const CVector2 CVector2::operator-(const CVector2 &v)const
{
	return CVector2(x - v.x, y - v.y);
}

const CVector2 CVector2::operator*(float f)const{
	return CVector2(x*f, y*f);
}

float CVector2::dot(const CVector2 &v){
	return x*v.x + y*v.y;
}

//í«â¡Å@äòìc
float CVector2::dot2(const CVector2 &v){
	return x*v.x + y*v.y;
}

float CVector2::Length(){
	return sqrtf(x*x + y*y);
}