#include "Task.h"
#include"TaskManager.h"


Task::Task(int _type) {
    m_type = _type;
    printf("Task����������܂���\n");
}

void Task::Update()
{
}

void Task::HitCheck(Task * _t)
{
}

void Task::Draw()
{
	printf("Task Draw\n");
}






