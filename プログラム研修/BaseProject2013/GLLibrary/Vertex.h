#pragma once
#include "CVector.h"
#include "windows.h"

//���_�\����
struct MY_VERTEX
{
	SVector3D		vPos;//���_�ʒu
	SVector3D		vNorm;//���_�@��
	SVector2D		vTex;//UV���W
	float			bBoneWeight[4];//�{�[���@�d��
	float			bBoneIndex[4];//�{�[���@�ԍ�
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