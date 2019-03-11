#pragma once

class Task;

//�}�����ł���Ε`�揇�ԂƂ����o�u���\�[�g�Ƃ����ׂ̍����������Ȃ��Ă悢

class TaskManager {
private:
	int m_task_num = 0;
	Task * m_head_task = nullptr;
public:
	Task* GetHead() { return m_head_task; };
	void AddTask(Task* _task);
	Task* FindTask(int _task_id);

	//�Y����ID��Task��S�ĕԂ�
	Task** FindTaskArray(int _task_id);

	//�����ɊY���^�X�N���폜����
	void DeleteTask(Task* _task);
	void DeleteAllTask();

	//�폜�t���O��true�ɂȂ��Ă���^�X�N��S�č폜����
	void CheckDeleteAll();

	void UpdateAll();
	void CollisionAll();
	void DrawAll();
	void Sort();
	void QuickSort(Task** _task_array,int* _task_dp_array,int _task_num);

	static TaskManager* GetInstance();
	static void ClearInstance();
};

/*
2019/03/07 TaskManager�N���X��`�B��{�@�\�����Bby shingai
2019/03/08 �o�O�C����\�[�g�������N�C�b�N�\�[�g�ɕύX�B by shingai
*/
