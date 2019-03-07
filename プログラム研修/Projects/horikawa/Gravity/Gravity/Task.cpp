#include "Task.h"

Task::Task()
{
	mp_prev = NULL;
	mp_next = NULL;
}

void Task::Draw()
{
	printf("TaskDraw\n");
}
