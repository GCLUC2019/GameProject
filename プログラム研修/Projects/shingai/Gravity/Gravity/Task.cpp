#include "Task.h"
#include <stdio.h>
#include "TaskManager.h"

Task::Task(int _task_id, int _draw_priority)
{
	m_task_id = _task_id;
	m_draw_priority = _draw_priority;
	TaskManager::GetInstance()->AddTask(this);
}

void Task::Delete()
{
	TaskManager::GetInstance()->DeleteTask(this);
}

Task::~Task()
{
	printf("task_id %d ƒ^ƒXƒNíœ\n",m_task_id);
}


void Task::Update()
{
}

void Task::Draw() {
	printf("TaskDraw Dp %d\n",m_draw_priority);
}

void Task::CollisionCheck(Task * _collision_task)
{

}
