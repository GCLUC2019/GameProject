#include "TaskManager.h"
#include "stdio.h"
#include "stdlib.h"
#include "Task.h"

static bool s_is_init = false;
static TaskManager* s_task_manager_p[eTaskManagerMax];

void TaskManager::AddTask(Task * _task)
{
	m_task_num++;

	if (m_head_task == nullptr) {
		m_head_task = _task;
		return;
	}

	Task* t = m_head_task;
	while (true) {
		if (t->GetNextTask() != nullptr) {
			t = t->GetNextTask();
		}
		else {
			t->SetNextTask(_task);
			_task->SetBeforeTask(t);
			break;
		}
	}
}

Task * TaskManager::FindTask(int _task_id)
{
	Task* t = GetHead();
	while (true) {
		if (t->GetTaskId() == _task_id) return t;
		t = t->GetNextTask();
		if (t == nullptr) break;
	}
	return nullptr;
}

void TaskManager::DeleteTask(Task * _task)
{
	if (m_head_task == _task) {
		Task* head_next = m_head_task->GetNextTask();
		m_head_task = head_next;
		if (head_next != nullptr) head_next->SetBeforeTask(nullptr);
		delete _task;
		m_task_num--;
		return;
	}

	Task* t = m_head_task->GetNextTask();

	while (true) {
		if (t == _task) {
			Task* next = t->GetNextTask();
			Task* before = t->GetBeforeTask();


			if (before != nullptr) {
				before->SetNextTask(next);
				if (next != nullptr) next->SetBeforeTask(before);
			}


			delete _task;
			m_task_num--;
			return;
		}

		t = t->GetNextTask();
		if (t == nullptr) break;
	}
}

void TaskManager::UpdateAll()
{
	Task* t = GetHead();
	while (true) {
		t->Update();
		t = t->GetNextTask();
		if (t == nullptr) break;
	}
}

void TaskManager::UpdateAllSort()
{
	//�z����쐬(calloc�ŗ̈�m��)

	//Task�|�C���^�^�z��(�z���\���ׂ�Task�|�C���^�^�|�C���^�𗘗p����)
	Task** task_array = (Task**)calloc(m_task_num, sizeof(Task*));


	//int�^�z��
	int* task_up_array = (int*)calloc(m_task_num, sizeof(int));


	//���Ƃ̓\�[�g���Ă�������

	//�Ƃ肠�����\�[�g�p�̏����W�߂�
	Task* t = GetHead();


	//�����Ő錾���Ă�̂Ŏ�舵������
	int i = 0;
	while (true) {
		task_array[i] = t;
		task_up_array[i] = t->GetUpdatePriority();
		t = t->GetNextTask();
		i++;
		if (t == nullptr) break;
	}


	//�\�[�g��Ƃ���(�o�u���\�[�g)
	for (int i = 0; i < m_task_num; i++) {
		for (int k = 0; k < m_task_num; k++) {
			if (task_up_array[i] > task_up_array[k]) {

				//�X�V���Ԕz��̓���ւ�
				int work = task_up_array[i];
				task_up_array[i] = task_up_array[k];
				task_up_array[k] = work;

				//�|�C���^�̓���ւ�
				Task* work_task_p = task_array[i];
				task_array[i] = task_array[k];
				task_array[k] = work_task_p;

			}
		}
	}

	for (int i = 0; i < m_task_num; i++) {
		printf("%d�Ԗڂ�Task up %d\n", i, task_up_array[i]);
		task_array[i]->Update();
	}


	//�Ƃ肠�����擾�����f�[�^���m�F

	//calloc�Ŏ擾�����̈�����
	free(task_array);
	free(task_up_array);
}

void TaskManager::DrawAll()
{
	Task* t = GetHead();
	while (true) {
		t->Draw();
		t = t->GetNextTask();
		if (t == nullptr) break;
	}
}


//Z�\�[�g�Ƃ��Ă��g����\�[�g
//�`�揇�Ԃ͌�̕����D��x������(�O�ɕ\�������)
//�̂Œl���傫�������Ԃ���ɂ���B
//�Ȃ̂ŏ����\�[�g

void TaskManager::DrawAllSort()
{
	//�z����쐬(calloc�ŗ̈�m��)
	
	//Task�|�C���^�^�z��(�z���\���ׂ�Task�|�C���^�^�|�C���^�𗘗p����)
	Task** task_array = (Task**)calloc(m_task_num,sizeof(Task*));


	//int�^�z��
	int* task_dp_array = (int*)calloc(m_task_num,sizeof(int));


	//���Ƃ̓\�[�g���Ă�������

	//�Ƃ肠�����\�[�g�p�̏����W�߂�
	Task* t = GetHead();


	//�����Ő錾���Ă�̂Ŏ�舵������
	int i = 0;
	while (true) {
		task_array[i] = t;
		task_dp_array[i] = t->GetDrawPriority();
		t = t->GetNextTask();
		i++;
		if (t == nullptr) break;
	}


	//�\�[�g��Ƃ���(�o�u���\�[�g)
	for (int i = 0; i < m_task_num; i++) {
		for (int k = 0; k < m_task_num; k++) {
			if (task_dp_array[i] < task_dp_array[k]) {
				
				//�`�揇�Ԕz��̓���ւ�
				int work = task_dp_array[i];
				task_dp_array[i] = task_dp_array[k];
				task_dp_array[k] = work;

				//�|�C���^�̓���ւ�
				Task* work_task_p = task_array[i];
				task_array[i] = task_array[k];
				task_array[k] = work_task_p;

			}
		}
	}

	for (int i = 0; i < m_task_num; i++) {
		printf("%d�Ԗڂ�Task dp %d\n",i, task_dp_array[i]);
		task_array[i]->Draw();
	}


	//�Ƃ肠�����擾�����f�[�^���m�F

	//calloc�Ŏ擾�����̈�����
	free(task_array);
	free(task_dp_array);
}

void TaskManager::CheckInit()
{
	if (s_is_init == false) {
		s_is_init = true;
		for (int i = 0; i < eTaskManagerMax; i++) {
			s_task_manager_p[i] = new TaskManager();
		}
	}
}

TaskManager * TaskManager::GetTaskManagerPointer(int _task_manager_id)
{
	CheckInit();
	return s_task_manager_p[_task_manager_id];
}
