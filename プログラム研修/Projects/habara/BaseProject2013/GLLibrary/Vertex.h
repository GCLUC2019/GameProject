#pragma once
#include "CVector.h"
#include "windows.h"

//頂点構造体
struct MY_VERTEX
{
	SVector3D		vPos;//頂点位置
	SVector3D		vNorm;//頂点法線
	SVector2D		vTex;//UV座標
	float			bBoneWeight[4];//ボーン　重み
	float			bBoneIndex[4];//ボーン　番号
	MY_VERTEX()
	{
		ZeroMemory(this,sizeof(MY_VERTEX));
	}
};

struct SXVector3{
	union {
		float f[3];
		struct{
			float x;
			float y;
			float z;
		};
	};
};
struct SXVector4{
	union {
		float f[4];
		struct{
			float x;
			float y;
			float z;
			float w;
		};
	};
};
struct SXIndex3{
	int idx[3];
};
struct SXIndex4{
	int idx[4];
};

struct SXColorRGB{
	float r;
	float g;
	float b;
};


struct SXColorRGBA{
	float r;
	float g;
	float b;
	float a;
};

struct SXTexCode2{
	float u;
	float v;
};