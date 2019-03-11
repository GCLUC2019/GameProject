#include "TaskManagement.h"
TaskManagement* TaskManagement::mp_t_ins = nullptr;

TaskManagement::TaskManagement():
	mp_head(nullptr),
	mp_tail(nullptr)
{
}

TaskManagement::~TaskManagement()
{

}

void TaskManagement::Add(Task * _add)
{
	//�����A�擪�ɂȂɂ��Ȃ�������A
	if (mp_head == nullptr) {
		SetHead(_add);
		return;
	}

	Task * now = mp_head;
	//�擪���疖���܂ŌJ��Ԃ�
	while (now)
	{
		//�ǉ��������^�X�N�̗D��x�ƁA
		//���݃|�C���^���w���^�X�N�̗D��x���r
		if (_add->m_priority < now->m_priority) {
			InsertTask(_add, now);
			return;
		}

		Task* next = now->mp_next;
		//�D��x���Ⴂ�ꍇ�͖����ɒǉ�
		if (next == nullptr) {
			SetTail(_add, now);
			return;
		}
		now = next;
	}


}

void TaskManagement::SetHead(Task* add_t)
{
	//�擪�������Ȃ����A
	if (mp_head == nullptr) {
		mp_tail = add_t;
		add_t->mp_next = nullptr;
	}
	//�擪�̎��̗v�f�����鎞�A
	else if (mp_head->mp_next != nullptr) {
		Task*head_next = mp_head->mp_next;
		add_t->mp_next = head_next;
		SetTail(mp_head, mp_tail);
	}
	
	//���ʏ���
	add_t->mp_prev = nullptr;
	mp_head = add_t;
}

void TaskManagement::SetTail(Task* add_t, Task* now_t)
{
	now_t->mp_next = add_t;
	add_t->mp_prev = now_t;
	mp_tail = add_t;
}

void TaskManagement::InsertTask(Task* add_t, Task* now_t)
{
	//���ݎw���^�X�N�̑O�̃^�X�N���ꎞ�ۑ�
	Task * befor_p = now_t->mp_prev;

	//�ꎞ�ۑ������^�X�N��mp_head��
	//mp_prev���w���Ă����ꍇ�A
	if (befor_p != nullptr)
		//�ǉ��������^�X�N�̃|�C���^���i�[
		befor_p->mp_next = add_t;
	now_t->mp_prev = add_t;
	add_t->mp_next = now_t;
	add_t->mp_prev = befor_p;

	//���ݎw���Ă���|�C���^���擪�̏ꍇ�A
	if (now_t == mp_head)
		//����ǉ������^�X�N�̃|�C���^��
		//�擪�ɒu��������
		mp_head = add_t;
}

void TaskManagement::UpdateAll()
{
	Task*now = mp_head;
	while (now) {
		now->Update();
		now = now->mp_next;
	}
}

void TaskManagement::DrawAll()
{
	Task*now = mp_head;
	while (now) {
		now->Draw();
		now = now->mp_next;
	}
}

void TaskManagement::DrawTailAll()
{
	Task*now = mp_tail;
	while (now) {
		now->Draw();
		now = now->mp_prev;
	}
}

void TaskManagement::FlagKill()
{
	Task*now = mp_head;
	while (now)
	{
		//���݂̃|�C���^�̎��̃|�C���^���ꎞ�ۑ�
		Task*next = now->mp_next;
		//�t���O�������Ă�����A���݂̃|�C���^��j��
		if (now->mp_killFlag == true)Kill(now);
		//���̃|�C���^������΁A���݂̃|�C���^�ɂ���
		if (next)now = next;
		else return;
	}
}

void TaskManagement::KillFlagAll()
{
	Task*now = mp_head;
	while (now)
	{
		now->SetKill();
		now = now->mp_next;
		printf("��������\n");
	}
}

void TaskManagement::KillAll()
{
	Task* now = mp_head;
	while (now)
	{
		//���݂̃|�C���^�̎��̃|�C���^���ꎞ�ۑ�
		Task*next = now->mp_next;
		Kill(now);
		printf("�������܂���\n");
		now = next;
	}
}

void TaskManagement::RemoveTask(Task * rem_p)
{
	Task* before_p = rem_p->mp_prev;
	Task* after_p = rem_p->mp_next;
	//�O���^�X�N�̑O�Ƀ|�C���^������ꍇ
	if (before_p != nullptr)before_p->mp_next = after_p;
	//���l�Ɏ��̃|�C���^������ꍇ�A
	if (after_p != nullptr)after_p->mp_prev = before_p;
	//�O���^�X�N�̑O�������������
	rem_p->mp_prev = nullptr;
	rem_p->mp_next = nullptr;
	//�O���^�X�N���擪�������ꍇ
	if (rem_p == mp_head)mp_head = before_p;
	//�O���^�X�N�������������ꍇ
	if (rem_p == mp_tail)mp_tail = after_p;
}

void TaskManagement::ChangePrio(Task * change_p, int priority)
{
	RemoveTask(change_p);
	change_p->SetPriority(priority);
	Add(change_p);
}

void TaskManagement::Kill(Task * kill_p)
{
	if (kill_p == nullptr)return;
	Task* bfeore_p = nullptr;
	Task* after_p = nullptr;
	//�j���������^�X�N�|�C���^�����̃|�C���^�������Ă���ꍇ�A
	if (kill_p->mp_next != nullptr)after_p = kill_p->mp_next;
	//���l�ɑO�̃|�C���^�������Ă���ꍇ�A
	if (kill_p->mp_prev != nullptr)bfeore_p = kill_p->mp_prev;
	//�j���������|�C���^���擪�������ꍇ�A
	if (kill_p == mp_head) mp_head = kill_p->mp_next;
	//�擾�������̃|�C���^���^�X�N���w���Ă���ꍇ�A
	if (after_p != nullptr)after_p->mp_prev = bfeore_p;
	//���l�ɑO�̃|�C���^������ꍇ�A
	if (bfeore_p != nullptr)bfeore_p->mp_next = after_p;
	//���X�g���珜�O
	RemoveTask(kill_p);
	//�폜��ɏ�����
	delete kill_p;
	kill_p = nullptr;
}

Task * TaskManagement::GetTask(int & id) const
{
	//Id�������^�X�N�����݂���΁A���̃|�C���^��Ԃ�
	Task*now = mp_head;
	while (now) {
		if (now->GetId() == id)return now;
		now = now->mp_next;
	}

	//����ȊO�Ȃ�k���|�C���^��Ԃ�
	return nullptr;
}

std::list<Task*> TaskManagement::GetTasks(int & id) const
{
	std::list<Task*> list;
	Task* now = mp_head;
	while (now) {
		//�擾�������^�X�N������΁A���X�g�Ɋi�[����
		if (now->GetId() == id)list.push_back(now->mp_task);;
		now = now->mp_next;
	}

	//���̃��X�g��Ԃ�
	return list;

}

int TaskManagement::GetCount(int & id) const
{
	Task* now = mp_head;
	int task_cnt = 0;

	//�w�肵���^�X�N����Ԃ�
	while (now) {
		if (now->GetId() == id)task_cnt++;
		now = now->mp_next;
	}

	return task_cnt;
}


TaskManagement * TaskManagement::GetIns()
{
	//�N�����Ɉ�x�����A
	//TaskManagement�N���X�𐶐����C���X�^���X�Ɋi�[
	if (mp_t_ins == nullptr)
		mp_t_ins = new TaskManagement();

	//�����Ԃ�
	return mp_t_ins;
}

void TaskManagement::ClearIns()
{
	//���������[�N���
	if (mp_t_ins != nullptr)delete mp_t_ins;
	mp_t_ins = nullptr;
}
