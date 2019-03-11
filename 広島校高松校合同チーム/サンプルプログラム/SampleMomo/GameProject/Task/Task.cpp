#include "Task.h"
#include <stdio.h>
#include "TaskManager.h"

Task::Task(int _task_id, int _draw_priority)
{
	m_task_id = _task_id;
	m_draw_priority = _draw_priority;
}

void Task::Delete()
{
	TaskManager::GetInstance()->DeleteTask(this);
}

Task::~Task()
{
	//printf("task_id %d �^�X�N�폜\n",m_task_id);
}

void Task::BeforeUpdate()
{
}


void Task::Update()
{

}

void Task::AfterUpdate()
{
}

void Task::Draw() {
	//printf("TaskDraw Dp %d\n",m_draw_priority);
}

void Task::BeforeCollisionCheck()
{
}

void Task::CollisionCheck(Task * _collision_task)
{

}
