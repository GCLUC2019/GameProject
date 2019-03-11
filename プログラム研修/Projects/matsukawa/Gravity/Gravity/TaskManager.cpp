#include "TaskManager.h"
TaskManager* TaskManager::mp_instance=nullptr;



TaskManager::TaskManager():
mp_head(nullptr),
mp_tail(nullptr)
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::AddTask(Task * p)
{
	
	if (mp_head == nullptr) {
		mp_head = p;
		p->mp_prev = nullptr;
		p->mp_next = nullptr;
		mp_tail = p;

		return;
	}

	Task* t = mp_head;
		while (true)
		{
			//printf("���[�v\n");
			//if (p->GetPriorty() < t->GetPriorty()) {
			//	printf("p;%d t:%d\n", p->m_priority, t->m_priority);
			//	// �}�� 
			//	Task *prev =t->mp_prev;
			//	if(prev !=nullptr) prev->mp_next = p;
			//	t->mp_prev = p;
			//	p->mp_next = t;
			//	p->mp_prev = prev;
			//	if (prev != nullptr&&t == mp_head)printf("�擪�ł�\n");
			//	// �擪�̏ꍇ 
			//	if (t == mp_head) mp_head = p;
			//	printf("��O�ɑ}��\n");
			//	return;
			//}
			Task* next = t->mp_next;
			if (next == nullptr) {
				t->mp_next = p;
				p->mp_prev = t;
				mp_tail = p;
				printf("�����ɒǉ�\n");
				break;
			}
			if (t == next)printf("�G���[\n");
			t = next;
		}
}

void TaskManager::SelectKill()
{
	Task* head = mp_head;
	while (head)
	{
		Task* next = head->mp_next;
		printf("��������\n");
		if (head->mp_killFlag = true)Kill(head->mp_task);
			if (next)head = next;
			else return;
	}
}

void TaskManager::SetKillAll()
{
	Task* head = mp_head;
	while (head)
	{
		head->SetKill();
		head = head->mp_next;
	}
}

void TaskManager::UpdateAll()
{
	Task* head = mp_head;
	while (head)
	{
		head->Update();
		head = head->mp_next;
	}
}

void TaskManager::DrawAll()
{
	Task* head = mp_head;
	while (head)
	{
		head->Draw();
		head = head->mp_next;
	}
}

void TaskManager::KillAll()
{
	Task*p = mp_head;
	while (p)
	{
		Task* next = p->mp_next;
		Kill(p->mp_task);
		p = next;
		printf("�������܂���\n");
	}
}

void TaskManager::ChangePrio(Task * p, int priorty)
{
	RemoveTask(p);
	p->SetPriority(priorty);
	AddTask(p);
}

void TaskManager::RemoveTask(Task * p)
{
	Task* prev = p->mp_prev;
	Task* next = p->mp_next;
	if (prev != nullptr) prev->mp_next = next;
	if (next != nullptr) next->mp_prev = prev;
	p->mp_prev = nullptr;
	p->mp_next = nullptr;
	if (mp_head == p) mp_head = next;
	if (mp_tail == p) mp_tail = prev;
}

void TaskManager::Kill(Task * p)
{
	if (p == nullptr)return;
	Task *next = nullptr;
	Task *prev = nullptr;
	if (p->mp_next != nullptr) next = p->mp_next;
	if (p->mp_prev != nullptr) prev = p->mp_prev;
	if (p == mp_head)mp_head = mp_head->mp_next;
	if(next !=nullptr)next->mp_prev = prev;
	if(prev!=nullptr)prev->mp_next = next;
	//���X�g���珜�O 
	delete p;
	p = nullptr;
}

TaskManager * TaskManager::GetInstance()
{
	//�C���X�^���X����x�̂ݐ������Ċi�[
	if (mp_instance == nullptr) mp_instance = new TaskManager();
	//�����Ԃ�
	return mp_instance;
}
