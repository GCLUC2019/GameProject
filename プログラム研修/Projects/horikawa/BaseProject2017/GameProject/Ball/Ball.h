#pragma once
#include "../stdafx.h"
#include "../System/Task.h"
class Ball : public Task {
private:
	CVector2D m_pos;		//ボールの位置
	CVector2D m_vec;		//ボールの移動量
public:
	/*!
		@brief	コンストラクタ
		@param	pos			[in] 出現位置
	**/
	Ball(const CVector2D& pos);

	/*!
	@brief	デフォルトコンストラクタ
	@param	pos			[in] 出現位置
	**/
	Ball();

	/*!
		@brief	デストラクタ
	**/
	~Ball();
	/*!
		@brief	更新処理
		@param	delta_time			[in] 前回の更新からの経過時間
	**/
	void Update(float delta_time);
	/*!
		@brief	描画処理
	**/
	void Render();

	/*!
	@brief	ボールの移動量を設定
	@param	vec			[in] 移動量
	**/
	void SetVector(const CVector2D& vec) {           //ポインタを使用し処理を軽くする、短い処理はヘッダーに作り動作を軽くする(インライン関数
		m_vec = vec;
	}

	CVector2D GetVector() const {    //constは中身を変えさせない
		return m_vec;
	}
};