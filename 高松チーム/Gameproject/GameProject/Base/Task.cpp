#include "Task.h"
#include"TaskManager.h"

Task::Task(int _type) {
    m_type = _type;
    printf("Taskが生成されました\n");
}

Task::~Task()
{
}

void Task::Update()
{
}

void Task::HitCheck(/*Task * _t*/)
{
}

void Task::Draw()
{
	//printf("Task Draw\n");
}






