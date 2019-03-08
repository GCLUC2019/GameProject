#include<stdio.h>

#include "Task.h"


Task::Task() :
	m_prev(nullptr),
	m_next(nullptr),
	m_S_Weigh(0)
{
	


}
Task::Task(int _m_S_Weigh) :
	m_prev(nullptr),
	m_next(nullptr)
{
	m_S_Weigh = _m_S_Weigh;


}
void Task::Draw() {
	printf("%d\n", m_S_Weigh);
}
