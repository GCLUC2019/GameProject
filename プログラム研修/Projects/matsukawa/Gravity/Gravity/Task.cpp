#include "Task.h"
#include "TaskManagement.h"
#include <iostream>

Task::Task() :
	mp_task(nullptr),
	mp_prev(nullptr),
	mp_next(nullptr),
	m_id(Task_id),
	m_priority(Task_prio),
	mp_killFlag(false)
{
	cnt = rand() % 10;
}

Task::Task(int id, int priority) :
	mp_task(nullptr),
	mp_prev(nullptr),
	mp_next(nullptr),
	m_id(id),
	m_priority(priority),
     mp_killFlag(false)
{
	cnt = rand() % 10;
}

Task::~Task()
{
}

void Task::Update()
{
	cnt++;
}


void Task::Draw()
{
	printf("TaskDraw:%d: cnt;%d\n",m_priority,cnt);
}

void Task::ChangeTaskPrio(int priority)
{
	TaskManagement::GetIns()->ChangePrio(this,priority);
}
