#include "Task.h"
#include"TaskManager.h"

CVector2D Task::m_scroll = CVector2D(0, 0);
Task::Task(int _type) {
    m_type = _type;
    printf("Task‚ª¶¬‚³‚ê‚Ü‚µ‚½\n");
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






