#include "CObject.h"

CObject::CObject(int _task_manager_id, int _task_id, int _update_priority, int _draw_priority) : Task(_task_manager_id,_task_id,_update_priority,_draw_priority)
{
}

CObject::~CObject()
{
}

void CObject::Update(float delta_time)
{
}

void CObject::Draw()
{
}
