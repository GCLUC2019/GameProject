#pragma once
#include "CObject.h"

class CCharacter : public CObject {
private:
protected:
public:
	CCharacter(int _task_id, int _draw_priority);
	virtual ~CCharacter();
	virtual void Update();
	virtual void Draw();
	void CollisionCheck(Task* _collision_task);
	virtual void CollisionCheckCharacter(Task* _collision_task);
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/

