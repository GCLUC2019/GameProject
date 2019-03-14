#pragma once
#include "GL.h"
#include "CMatrix.h"
namespace Utility {
	/*!
		@brief	Degree（度）をRadianに変換
		@param	d				[in] 角度
		@retval	Radianに変換された角度
	**/

	inline float DgreeToRadian(float d) {
		return (float)(d*M_PI / 180.0f);
	}
	inline float RadianToDgree(float d) {
		return (float)(d *180.0f/ M_PI);
	}
	/*!
		@brief	角度の正規化
		@param	a				[in] 角度
		@retval	-PI～PI
	**/

	inline float NormalizeAngle(float a) {
		if (a>M_PI) return (float)(a - M_PI * 2);
		else if (a<-M_PI) return (float)(a + M_PI * 2);
		return a;
	}
	/*!
		@brief	角度の差を取得
		@param	a			[in] 角度
		@param	b			[in] 角度
		@retval	aとbの角度の差
	**/
	inline float DiffAngle(float a, float b) {
		if(a*b < 0){
			if(fabsf(a)+fabsf(b) > M_PI) {
				if (b<0) a -= (float)M_PI * 2;
				else a+=(float)M_PI*2;
			}
		}
		return a-b;
	}
	/*!
		@brief	乱数取得
		@param	min				[in] 最低値
		@param	max				[in] 最大値
		@retval	最低値～最大値の乱数
	**/

	template <typename T> inline T Rand(T min,T max) {
		return min + ((max-min) * rand()/ RAND_MAX);
	}
	/*!
	@brief	線を引く
	@param	s				[in] 線分の始点
	@param	e				[in] 線分の終点
	@param	color			[in] 色
	@retval	無し
	**/
	void DrawLine(const CVector2D &s, const CVector2D &e, const CVector4D &color);

	/*!
	@brief	矩形の描画
	@param	pos				[in] 位置
	@param	size				[in] 大きさ
	@param	color			[in] 色
	@retval	無し
	**/
	void DrawQuad(const CVector2D &pos, const CVector2D &size, const CVector4D &color);


	
}

#define RtoD(x) Utility::RadianToDgree(x)
#define DtoR(x) Utility::DgreeToRadian(x)