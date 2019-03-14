#pragma once
/**
* @file		CAnimImage.h
* @brief	アニメーション画像クラス
*
*/

#include "CImage.h"


struct TexAnim {
	int pat;		//使用画像No（画像の左上０～）
	int cnt;		//次の画像までの待機フレーム
};

#define ANIMDATA(data) { data,sizeof(data) / sizeof(data[0])}

struct TexAnimData{
	TexAnim	*pData;
	int		size;
};
class CAnimImage : public CImage {
private:
	TexAnimData	*m_animData;
	int			m_animJam;
	int			m_animIndex;
	float		m_animCount;
	bool		m_animLoop;
	float		m_animSpeed;
	int			m_pat_width;
	int			m_pat_height;
	bool		m_copy;
public:
	/*!
	@brief	コンストラクタ
	**/
	CAnimImage();
	/*!
	@brief	デストラクタ
	**/
	~CAnimImage();

	/*!
	@brief	読み込み
	@param	filename	[in] 画像ファイル
	@param	d			[in] TexAnimData配列の先頭アドレス
	@param	width		[in] 一枚当たりの幅
	@param	height		[in] 一枚当たりの高さ
	**/
	static CAnimImage* LoadImage(const char* filename, TexAnimData *d = nullptr, int width = 0, int height = 0);

	bool Load(const char* filename, TexAnimData *d = nullptr, int width = 0, int height = 0);

	/*!
	@brief	コピーコンストラクタ
	@param	img			[in] 読み込み済みの画像オブジェクト
	@param	d			[in] TexAnimData配列の先頭アドレス
	@param	width		[in] 一枚当たりの幅
	@param	height		[in] 一枚当たりの高さ
	**/
	CAnimImage(const CImage& img, TexAnimData *d=nullptr, int width=0, int height=0);
	/*!
	@brief	コピーコンストラクタ
	@param	img			[in] 読み込み済みの画像オブジェクト
	@param	d			[in] TexAnimData配列の先頭アドレス
	@param	width		[in] 一枚当たりの幅
	@param	height		[in] 一枚当たりの高さ
	**/
	CAnimImage(const CImage* img, TexAnimData *d = nullptr, int width = 0, int height = 0);
	/*!
	@brief	代入演算オーバーロード
	@param	img			[in] 読み込み済みの画像オブジェクト
	**/
	CAnimImage& operator = (const CImage& img);
	/*!
	@brief	アニメーションの更新
	**/
	void UpdateAnimation();
	/*!
	@brief	アニメーションデータのセット
	@param	d			[in] TexAnimData配列の先頭アドレス
	@param	width		[in] 一枚当たりの幅
	@param	height		[in] 一枚当たりの高さ
	**/
	void AttachAnimationData(TexAnimData *d,int width, int height);
	/*!
	@brief	アニメーション切り替え
	@param	num			[in] アニメーション番号
	@param	loop		[in] アニメーションループフラグ
	@param	index		[in] 開始位置
	@param	check		[in] 既に再生中なら切り替えない（再スタートしない）
	**/
	void ChangeAnimation(int num, bool loop = true, int index = 0,  bool check = true);
	/*!
	@brief	アニメーション速度変更
	@param	speed		[in] 再生速度（デフォルト1）
	**/
	void SetAnimationSpeed(float speed);
	/*!
	@brief	アニメーション終了チェック
	@retval	終了ならtrue
	**/
	bool CheckAnimationEnd();
	/*!
	@brief	再生中のアニメーションデータの取得プフラグ
	@retval	現在のアニメーションデータ
	**/
	const TexAnim* GetAnimationParam() const {
		return &m_animData[m_animJam].pData[m_animIndex];
	}
	/*!
	@brief	現在の再生位置を取得
	@retval	再生位置
	**/
	int GetIndex() {
		return m_animIndex;
	}
	/*!
	@brief	現在のカウントを取得
	@retval	カウント
	**/
	int GetCount() {
		return m_animCount;
	}
	/*!
	@brief	描画
	@retval	無し
	**/
	void Draw();

};
