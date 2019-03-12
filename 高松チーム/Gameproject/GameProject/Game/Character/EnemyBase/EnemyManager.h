#pragma once
#include "../../../Base/Task.h"
/*　担当
　　国見
*/

class EnemyManager : public Task {
private:
	int m_wave_flg;
protected:
	CVector2D m_pos;	//敵位置
public:
	EnemyManager();
	void Update();
	void Draw();

};