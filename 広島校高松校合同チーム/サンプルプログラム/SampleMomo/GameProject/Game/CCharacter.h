#pragma once
#include "CObject.h"

class CCharacter : public CObject {
private:
protected:
public:
	CCharacter(int _task_manager_id, int _task_id, int _update_priority, int _draw_priority);
	virtual ~CCharacter();
	virtual void Update(float delta_time);
	virtual void Draw();
};