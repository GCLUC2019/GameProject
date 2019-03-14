#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include"CVector2.h"
#include"CMatrix33.h"
#include "CTask.h"
#include "CTexture.h"

class CCollider;

class CRectangle:public CTask{
public:
	int x;	//中心のX座標
	int y, w, h;	//中心のY座標,幅,高さ
	int mU[2]; //マッピング横
	int mV[2]; //マッピング縦

	CTexture*mpTexture;
	CVector2 mUv[4];

	CRectangle()
		:mPosition(0.0f, 0.0f)
		, mRotation(0.0f)
		, mpTexture(0)
		, mScale(1.0f,1.0f)
	{}
	CVector2 mPosition;
	float mRotation;
	CMatrix33 mMatrix;
	CVector2 mVertex[4];
	void SetVertex(float left, float right, float bottom, float top);
	void Update();
	void Render();
	float mColor[4];
	void SetColor(float r, float g, float b, float a);
	virtual void OnCollision(CCollider*p){};
	void SetTexture(CTexture*t, float left, float right, float bottom, float top);
	CVector2 mScale;
	/*28
	テクスチャの描画
	*/
	void Draw(const CTexture &t, int left, int right, int bottom, int top);

};

#endif