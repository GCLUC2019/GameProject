#include<stdio.h>
#include "Task.h"


Task::Task() :
	m_prev(nullptr),
	m_next(nullptr),
	m_S_Weigh(0)
{
	


}
Task::Task(int _m_S_Weigh, int _m_type) :
	m_prev(nullptr),
	m_next(nullptr)
{
	m_type = m_type;
	m_S_Weigh = _m_S_Weigh;


}
void Task::Draw() {
	printf("%d\n", m_S_Weigh);
}

Task::~Task()
{
	printf("�폜\n");
}
