//小川

#ifndef CAppear_H
#define CAppear_H

#pragma once
#include "CStdafx.h"
#include "Task.h"
#include "CRectangle.h"

class CAppear : public Task {
private:
	CVector2 m_pos;		//ボールの位置
	CVector2 m_vec;		//ボールの移動量
public:
	/*!
	@brief	コンストラクタ
	@param	pos			[in] 出現位置
	**/
	CAppear();
	CAppear(const CVector2& pos);
	/*!
	@brief	デストラクタ
	**/
	~CAppear();
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
	@brief ボールの移動量を設定
	@@param _vector [in] 移動量
	**/
	void SetVector(const CVector2& _vector) { m_vec = _vector; };
};


#endif
