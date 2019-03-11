#include "Task.h"
#include <iostream>

Task::Task()
{
	mp_prev = nullptr;
	mp_next = nullptr;
	TaskManager::GetInstance()->Add(this);
	m_id = rand() % 10;
}

void Task::Draw()
{
	printf("TaskDraw\n");
}
