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
	void DeleteTask(Task* _task);

	void UpdateAll();
	void DrawAll();
	void Sort();

	static TaskManager* GetInstance();
	static void ClearInstance();
};

/*
2019/03/07 TaskManager�N���X��`�B��{�@�\�����B by shingai
*/
