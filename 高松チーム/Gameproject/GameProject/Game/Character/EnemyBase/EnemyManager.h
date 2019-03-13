#pragma once
#include "../../../Base/Task.h"
/*　担当
　　国見
*/

class EnemyManager : public Task {
private:
	enum {
		eWave1_1,
		eWave1_2,
		eWave2_1,
		eWave2_2,
	};

private:
	int m_wave_flg;		//ウェーブフラグ
	int m_appear_type;	//描画タイプ
	int m_cnt;
	
	//各ウェーブフラグ//
	bool m_wave1_1_flg; 
	bool m_wave1_2_flg;
	bool m_wave2_1_flg;
	bool m_wave2_2_flg;

protected:
	CVector2D m_pos;	//敵位置
public:
	EnemyManager();
	void Update();
	void Draw();

};