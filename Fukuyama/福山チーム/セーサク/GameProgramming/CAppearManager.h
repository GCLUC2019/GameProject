//小川



#pragma once
#include "Cstdafx.h"
#include "Task.h"
class CAppearManager : public Task {
private:

	float m_time; //!時間計測用

public:
	/*!
	@brief	コンストラクタ
	**/
	CAppearManager();
	/*!
	@brief	デストラクタ
	**/
	~CAppearManager();
	/*!
	@brief	更新処理
	@param	delta_time			[in] 前回の更新からの経過時間
	**/
	void Update(float delta_time);
	/*!
	@brief	描画処理
	**/
	void Render();
};

