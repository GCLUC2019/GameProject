#pragma once
/*　担当
	国見　class Enemy05
*/
#include "../EnemyBase.h"

class Enemy05 : public EnemyBase {
private:
	
public:
	Enemy05();
	void Move();
	void Attack();
	void Update();
	void Draw();
	
};