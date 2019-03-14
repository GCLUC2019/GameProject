/*!
 *	@brief		画像管理クラス
 *	
 */

#pragma once

#include "CRect.h"
#include "CMatrix.h"
#include "CTexture.h"

class CImage : public CTexture {
public:
	CVector2D	m_center;	//中心位置(pixel)
	CVector2D	m_size;	//サイズ(pixel)
	CRect		m_src_rect;	//表示元矩形
	float		m_ang;		//回転値
	bool		m_flipH;	//左右反転
	CColorRGBA	m_color;	//色
	

public:
	CVector2D	m_pos;		//位置(pixel)
	CImage();
	virtual ~CImage();
	/*!
		@brief	ファイルから画像を読み込む（24bitbmp,png対応）
		@param	path		[in] ファイル名
		@retval	結果:true接触 false非接触
	**/
	bool Load(const char* path);
	static CImage* LoadImage(const char* path);
	

	/*!
		@brief	表示位置を設定する
		@param	x		[in] 横位置
		@param	y		[in] 縦位置
		@retval	無し
	**/
	void SetPos(float x,float y) {
		m_pos.x = x; m_pos.y = y;
	}
	void SetPos(CVector2D p) {
		m_pos = p;
	}

	CVector2D* GetPosPointer()
	{
		return &m_pos;
	}

	/*!
		@brief	回転の中心位置を設定する
		@param	x		[in] 横位置
		@param	y		[in] 縦位置
		@retval	無し
	**/
	void SetCenter(float x,float y) {
		m_center.x = x; m_center.y = y;
	}
	void SetCenter(CVector2D p) {
		m_center = p;
	}

	/*!
		@brief	表示サイズを設定する
		@param	w		[in] 幅
		@param	h		[in] 高さ
		@retval	無し
	**/
	void SetSize(float w,float h) {
		m_size.x = w; m_size.y = h;
	}
	void SetSize(CVector2D s) {
		m_size = s;
	}
	CVector2D GetSize() {
		return m_size;
	}
	/*!
		@brief	表示元矩形を設定
		@param	left	[in] 左位置
		@param	top		[in] 上位置
		@param	right	[in] 右位置
		@param	bottom	[in] 下位置
		@retval	無し
	**/
	void SetRect(float left,float top,float right,float bottom){
		m_src_rect.m_left = left; m_src_rect.m_right = right;
		m_src_rect.m_top = top; m_src_rect.m_bottom = bottom;
	}

	/*!
		@brief	回転値を設定
		@param	ang		[in] 回転値
		@retval	無し
	**/
	void SetAng(float ang){
		m_ang = ang;
	}

	/*!
		@brief	左右反転フラグを設定
		@param	f		[in] true:通常 false:水平反転
		@retval	無し
	**/
	void SetFlipH(bool f) {
		m_flipH = f;
	}

	/*!
		@brief	色を設定
		@param	r		[in] 赤成分
		@param	g		[in] 緑成分
		@param	b		[in] 青成分
		@param	a		[in] 不透明度
		@retval	無し
	**/
	void SetColor(float r, float g, float b,float a){
		m_color.r = r;
		m_color.g = g;
		m_color.b = b;
		m_color.a = a;
	}
	/*!
		@brief	描画を行う
		@retval	無し
	**/
	void Draw();

	/*!
	@brief	画像同士の衝突判定
	@param	img		[in] 衝突対象物
	@retval	接触：true　,非接触:false
	**/
	bool CollitionImage(const CImage &img);


	/*!
	@brief	画像と矩形の衝突判定
	@param	rect		[in] 衝突矩形
	@retval	接触：true　,非接触:false
	**/
	bool CollitionRect(const CRect &rect);


	/*!
	@brief	画像と点の衝突判定
	@param	img		[in] 衝突対象物
	@retval	接触：true　,非接触:false
	**/
	bool CollitionPoint(const CVector2D &pos);

	virtual unsigned int GetDataSize() {
		return m_width * m_height * 4;
	};
};