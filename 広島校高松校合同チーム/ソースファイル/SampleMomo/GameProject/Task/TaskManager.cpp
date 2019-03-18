#include "TaskManager.h"
#include "stdio.h"
#include "stdlib.h"
#include "Task.h"

static TaskManager* s_instance_p = nullptr;

void TaskManager::AddTask(Task * _task)
{
	m_task_num++;


	//m_is_changed_task_tree = true;

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

Task** TaskManager::FindTaskArray(int _task_id)
{
	int task_num = 0;
	
	//�Y���^�X�N�̌��𒲂ׂ�
	Task* t = GetHead();
	if (t == nullptr) return nullptr;

	while (true) {
		if (t->GetTaskId() == _task_id) task_num++;
		t = t->GetNextTask();
		if (t == nullptr) break;
	}

	//�z��쐬
	Task** task_array = (Task**)calloc(task_num + 1,sizeof(Task*));

	//�Y���^�X�N��z��Ɋi�[
	task_num = 0;
	t = GetHead();
	while (true) {
		if (t->GetTaskId() == _task_id) {
			task_array[task_num++] = t;
		}

		t = t->GetNextTask();
		if (t == nullptr) break;
	}

	//�����͕K��nullptr(�ԕ�)
	task_array[task_num] = nullptr;

	return task_array;
}

void TaskManager::DeleteTask(Task * _task)
{
	//m_is_changed_task_tree = true;

	if (m_head_task == _task) {
		Task* head_next = m_head_task->GetNextTask();
		m_head_task = head_next;
		if (head_next != nullptr) head_next->SetBeforeTask(nullptr);
		delete _task;
		m_task_num--;
		return;
	}

	Task* next = _task->GetNextTask();
	Task* before = _task->GetBeforeTask();

	if (before != nullptr) {
		if(next != nullptr) before->SetNextTask(next);
		else before->SetNextTask(nullptr);
	}

	if (next != nullptr) {
		if(before != nullptr) next->SetBeforeTask(before);
		else next->SetBeforeTask(nullptr);
	}

	delete _task;
	m_task_num--;
}

void TaskManager::DeleteAllTask()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//Update��Delete�����s����Ă����v�Ȃ悤��
		t->Delete();
		t = t_next;
	}
}

void TaskManager::CheckDeleteAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//Update��Delete�����s����Ă����v�Ȃ悤��
		if(t->GetIsDelete() == true) t->Delete();
		t = t_next;
	}
}

void TaskManager::BeforeUpdateAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();
		if (t->GetIsDelete() == false) t->BeforeUpdate();
		t = t_next;
	}
}

void TaskManager::UpdateAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//Update��Delete�����s����Ă����v�Ȃ悤��
		if (t->GetIsDelete() == false) t->Update();
		t = t_next;
	}
}

void TaskManager::AfterUpdateAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();
		if (t->GetIsDelete() == false) t->AfterUpdate();
		t = t_next;
	}
}

void TaskManager::BeforeCollisionAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();
		if (t->GetIsDelete() == false) t->BeforeCollisionCheck();
		t = t_next;
	}
}

void TaskManager::CollisionAll()
{
	//�y�ʉ�
	register Task* t = GetHead();

	while (true) {
		if (t == nullptr) break;
		register Task* t_next = t->GetNextTask();//CollisionCheck��Delete�����s����Ă����v�Ȃ悤��
		register Task* t_c = GetHead();
		while (true) {
			if (t_c == nullptr) break;
			register Task* t_c_next = t_c->GetNextTask();//CollisionCheck��Delete�����s����Ă����v�Ȃ悤��
														 //�����C���X�^���X���m�Ȃ珇�Ԃ��΂�
			if (t == t_c) {
				t_c = t_c_next;
				if (t_c == nullptr) break;
				continue;
			}

			if (t->GetIsDelete() == false && t_c->GetIsDelete() == false) t->CollisionCheck(t_c);
			t_c = t_c_next;
		}
		t = t_next;
	}
	/*
	register Task* t = GetHead();

	while (true) {
		if (t == nullptr) break;
		register Task* t_next = t->GetNextTask();//CollisionCheck��Delete�����s����Ă����v�Ȃ悤��
		register Task* t_c = GetHead();
		while (true) {
			if (t_c == nullptr) break;
			register Task* t_c_next = t_c->GetNextTask();//CollisionCheck��Delete�����s����Ă����v�Ȃ悤��
			//�����C���X�^���X���m�Ȃ珇�Ԃ��΂�
			if (t == t_c) {
				t_c = t_c_next;
				if (t_c == nullptr) break;
				continue;
			}

			if (t->GetIsDelete() == false&& t_c->GetIsDelete() == false) t->CollisionCheck(t_c);
			t_c = t_c_next;
		}
		t = t_next;
	}
	*/
	
}

void TaskManager::DrawAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//Draw��Delete�����s����Ă����v�Ȃ悤��
		if (t->GetIsDelete() == false) t->Draw();
		t = t_next;
	}
}

void TaskManager::SortCollisionPriority()
{
	
}


void TaskManager::Sort(int _sort_type)
{
	//�y�ʉ�
	if (m_head_task == nullptr) return;

	register Task** task_array;
	register int* task_priority_array;

	//�z����쐬(calloc�ŗ̈�m��)
	task_array = (Task**)calloc(m_task_num, sizeof(Task*));
	task_priority_array = (int*)calloc(m_task_num, sizeof(int));

	//�\�[�g�p�̏����W�߂�
	register Task* t = GetHead();
	register Task* tp;

	//�����Ő錾���Ă�̂Ŏ�舵������
	register int i = 0;

	while (true) {
		if (t == nullptr) break;
		task_array[i] = t;

		switch (_sort_type) {
		case eSortDrawPriority:
			task_priority_array[i] = t->GetDrawPriority();
			break;
		case eSortCollisionPriority:
			task_priority_array[i] = t->GetCollisionPriority();
			break;
		}
		
		t = t->GetNextTask();
		i++;
	}

	//�\�[�g��Ƃ���(�N�C�b�N�\�[�g)
	QuickSort(task_array, task_priority_array, m_task_num);



	//�^�X�N���X�g���č\��
	m_head_task = task_array[0];
	m_head_task->SetBeforeTask(nullptr);



	for (register int i = 0; i < m_task_num; i++) {
		tp = task_array[i];
		if (i == m_task_num - 1) {
			tp->SetNextTask(nullptr);
		}
		else {
			tp->SetNextTask(task_array[i + 1]);
			task_array[i + 1]->SetBeforeTask(tp);
		}
	}
}

//�^�X�N��`��D��x�ɍ��킹�ă\�[�g����B
//�V�K�^�X�N�ǉ��� �^�X�N�폜���ɌĂ΂��B

//Z�\�[�g�Ƃ��Ă��g����\�[�g
//�`�揇�Ԃ͌�̕����D��x������(�O�ɕ\�������)�̂Œl���傫�������Ԃ���ɂ���B
//�Ȃ̂ŏ����\�[�g



//void TaskManager::SortDrawPriority()
//{
//	//�y�ʉ�
//	if (m_head_task == nullptr) return;
//
//	register Task** task_array;
//	register int* task_dp_array;
//
//	/*
//	//�g���܂킹��ꍇ�́A�g���܂킷
//	if (m_is_changed_task_tree == false) {
//		task_array = m_keep_task_array;
//		task_dp_array = m_keep_task_dp_array;
//	}
//	else {
//
//		//�z��̓��e���N���A
//		if (m_keep_task_array != nullptr) free(m_keep_task_array);
//		if (m_keep_task_dp_array != nullptr) free(m_keep_task_dp_array);
//
//		//�z����쐬(calloc�ŗ̈�m��)
//		task_array = (Task**)calloc(m_task_num, sizeof(Task*));
//		task_dp_array = (int*)calloc(m_task_num, sizeof(int));
//	}
//	*/
//
//	//�z����쐬(calloc�ŗ̈�m��)
//	task_array = (Task**)calloc(m_task_num, sizeof(Task*));
//	task_dp_array = (int*)calloc(m_task_num, sizeof(int));
//
//	//�\�[�g�p�̏����W�߂�
//	register Task* t = GetHead();
//	register Task* tp;
//
//	//�����Ő錾���Ă�̂Ŏ�舵������
//	register int i = 0;
//
//	while (true) {
//		if (t == nullptr) break;
//		task_array[i] = t;
//		task_dp_array[i] = t->GetDrawPriority();
//		t = t->GetNextTask();
//		i++;
//	}
//
//	//�\�[�g��Ƃ���(�N�C�b�N�\�[�g)
//	QuickSort(task_array, task_dp_array, m_task_num);
//
//
//
//	//�^�X�N���X�g���č\��
//	m_head_task = task_array[0];
//	m_head_task->SetBeforeTask(nullptr);
//
//
//	
//	for (register int i = 0; i < m_task_num; i++) {
//		tp = task_array[i];
//		if (i == m_task_num - 1) {
//			tp->SetNextTask(nullptr);
//		}
//		else {
//			tp->SetNextTask(task_array[i + 1]);
//			task_array[i + 1]->SetBeforeTask(tp);
//		}
//
//
//	}
//
//	//�g���܂킹�邩������Ȃ��̂ŃL�[�v���Ă���
//	//m_keep_task_array = task_array;
//	//m_keep_task_dp_array = task_dp_array;
//
//	//calloc�Ŏ擾�����̈�����
//	//free(task_array);
//	//free(task_dp_array);
//
//	//�y�ʉ��O
//	/*
//	if (m_head_task == nullptr) return;
//
//	//�z����쐬(calloc�ŗ̈�m��)
//
//	//Task�|�C���^�^�z��(�z���\���ׂ�Task�|�C���^�^�|�C���^�𗘗p����)
//	Task** task_array = (Task**)calloc(m_task_num, sizeof(Task*));
//
//
//	//int�^�z��
//	int* task_dp_array = (int*)calloc(m_task_num, sizeof(int));
//
//
//	//���Ƃ̓\�[�g���Ă�������
//
//	//�Ƃ肠�����\�[�g�p�̏����W�߂�
//	Task* t = GetHead();
//
//
//	//�����Ő錾���Ă�̂Ŏ�舵������
//	int i = 0;
//	while (true) {
//		if (t == nullptr) break;
//		task_array[i] = t;
//		task_dp_array[i] = t->GetDrawPriority();
//		t = t->GetNextTask();
//		i++;
//	}
//
//
//	//printf("m_task_num %d\n", m_task_num);
//
//	//�\�[�g��Ƃ���(�N�C�b�N�\�[�g)
//	QuickSort(task_array,task_dp_array,m_task_num);
//
//
//	
//	//�^�X�N���X�g���č\��
//	m_head_task = task_array[0];
//	m_head_task->SetBeforeTask(nullptr);
//
//
//	Task* tp;
//	for (int i = 0; i < m_task_num; i++) {
//		tp = task_array[i];
//		if (i == m_task_num - 1) {
//			tp->SetNextTask(nullptr);
//		}
//		else {
//			tp->SetNextTask(task_array[i + 1]);
//			task_array[i + 1]->SetBeforeTask(tp);
//		}
//
//		
//	}
//
//
//	//�Ƃ肠�����擾�����f�[�^���m�F
//	//calloc�Ŏ擾�����̈�����
//	free(task_array);
//	free(task_dp_array);
//	*/
//}


//QuickSort�C�����C����
/*
void TaskManager::QuickSort(Task ** _task_array, int * _task_dp_array, int _task_num)
{
	//printf("QuickSort�Ă΂ꂽ\n");
	
	int base_ad = _task_num / 2;

	while (true) {
		bool is_last_left = false;
		bool is_last_right = false;



		//�E�ƍ��ŕʁX��

		int left_ad = 0;
		
		while (true) {
			if (_task_dp_array[left_ad] > _task_dp_array[base_ad]) {
				break;
			}

			left_ad++;

			if (left_ad >= base_ad) {
				left_ad = base_ad;
				//printf("���\�[�g����\n");
				is_last_left = true;
				break;
			}
		}

		int right_ad = _task_num - 1;
		while (true) {
			if (_task_dp_array[right_ad] < _task_dp_array[base_ad]) {
				break;
			}

			right_ad--;

			if (right_ad <= base_ad) {
				right_ad = base_ad;
				//printf("�E�\�[�g����\n");
				is_last_right = true;
				break;
			}
		}

		//bool is_end = false;
		//printf("�E%d ��%d\n", _task_dp_array[left_ad], _task_dp_array[right_ad]);
		//if (_task_dp_array[left_ad] == _task_dp_array[right_ad] && (is_last_right == true || is_last_left == true)) is_end = true;


		//�����Փ˂����ꍇ
		if (is_last_left == true && is_last_right == true){
			//printf("�\�[�g����\n");
			//base_ad��ς��čċA��������
			int left_task_num = _task_num / 2;
			int right_task_num = _task_num - left_task_num;
			//printf("�N�C�b�N�\�[�g�ċA�Ăяo��\n");
			if(left_task_num > 1) QuickSort(_task_array, _task_dp_array, left_task_num);
			if(right_task_num > 1) QuickSort(_task_array + left_task_num, _task_dp_array + left_task_num, right_task_num);
			break;
		}


		//printf("����ւ�\n");
		//����ւ�
		int work = _task_dp_array[left_ad];
		_task_dp_array[left_ad] = _task_dp_array[right_ad];
		_task_dp_array[right_ad] = work;

		Task* work_task_p = _task_array[left_ad];
		_task_array[left_ad] = _task_array[right_ad];
		_task_array[right_ad] = work_task_p;
	}
}
*/


TaskManager * TaskManager::GetInstance()
{
	if (s_instance_p == nullptr) s_instance_p = new TaskManager();
	return s_instance_p;
}




void TaskManager::ClearInstance()
{
	if (s_instance_p == nullptr) return;
	delete s_instance_p;
	s_instance_p = nullptr;
}
