#include "TaskA.h"
#include "TaskManagement.h"

TaskA::TaskA():Task(TaskA_id, TaskA_prio)
{
	
}

void TaskA::Update()
{
	cnt *= 2;
	if (cnt >= 5)ChangeTaskPrio(5);
}

void TaskA::Draw()
{
	printf("TaskA:%d: cnt;%d\n", m_priority, cnt);
}