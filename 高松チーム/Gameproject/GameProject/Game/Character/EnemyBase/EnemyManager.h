#pragma once
#include "../../../Base/Task.h"
/*�@�S��
�@�@����
*/

class EnemyManager : public Task {
private:
	int m_wave_flg;
protected:
	CVector2D m_pos;	//�G�ʒu
public:
	EnemyManager();
	void Update();
	void Draw();

};