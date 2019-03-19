#ifndef CCHARACTER_H
#define CCHARACTER_H
//四角形クラスのインクルード
#include "CRectangle.h"

/*
キャラクタクラス
*/
class CCharacter : public CRectangle {
public:
	//有効無効フラグ
	bool mEnabled;//true:有効 false:無効
	//列挙型の定義
	enum ETag {
		EBLOCK,			//ブロック
		EPLAYERBULLET,	//プレイヤー弾
		EPLAYER,		//プレイヤー
		EENEMY,			//敵
	};
	ETag mTag;	//キャラの識別

	//状態識別子
	enum EState {
		ERUN,		//移動中
		EJUMPUP,	//ジャンプ上
		EJUMPDOWN,	//ジャンプ下
		ECRY,		//泣いている
	};
	EState mState; //状態

	//コンストラクタ
	CCharacter(CTexture *t, int ax, int ay, int aw, int ah, int u0, int u1, int v0, int v1);

	//仮想関数 描画処理
	virtual void Render() {
		//画像描画
		Draw(*mpTexture, mU[0], mU[1], mV[0], mV[1]);
	}

	//仮想関数 更新処理
	virtual void Update() {}

	//衝突処理
	virtual bool Collision(CCharacter *m, CCharacter *y) { return false; };

	//テクスチャマッピングの設定
	void SetUv(int u0, int u1, int v0, int v1);
};

#endif
