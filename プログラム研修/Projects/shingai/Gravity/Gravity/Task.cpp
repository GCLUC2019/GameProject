#include "Task.h"
#include <stdio.h>
#include "TaskManager.h"

Task::Task(int _task_manager_id, int _task_id, int _draw_priority)
{
	m_task_manager_id = _task_manager_id;
	m_task_id = _task_id;
	m_draw_priority = _draw_priority;
	TaskManager::GetTaskManagerPointer(_task_manager_id)->AddTask(this);
}

void Task::Delete()
{
	TaskManager::GetTaskManagerPointer(m_task_manager_id)->DeleteTask(this);
}

Task::~Task()
{
	printf("ƒ^ƒXƒNíœ\n");
}


void Task::Update()
{
}

void Task::Draw() {
	printf("TaskDraw\n");
}
