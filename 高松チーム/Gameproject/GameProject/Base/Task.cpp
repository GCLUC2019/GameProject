#include "Task.h"
#include"TaskManager.h"

Task::Task(int _type) {
    m_type = _type;
    //printf("Task‚ª¶¬‚³‚ê‚Ü‚µ‚½\n");
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

void Task::ThisSort()
{

	bool s = false;


	do {
		s = false;
		if (this->GetPrev() != nullptr&&this->GetPos().y < this->GetPrev()->GetPos().y) {
			TaskManager::Swap(this, this->GetPrev());
			s = true;
		}
		if (this->GetNext() != nullptr&&this->GetPos().y > this->GetNext()->GetPos().y) {
			TaskManager::Swap(this, this->GetNext());
			s = true;
		}
	} while (s);
}






