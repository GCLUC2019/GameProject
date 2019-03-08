#pragma once
class Task;

class TaskManager {
public:
	static TaskManager* mp_instance;
	static Task* mp_head;
public:
	static TaskManager* GetInstance() {
		//�C���X�^���X����x�̂ݐ������Ċi�[
		if (mp_instance == nullptr) mp_instance = new TaskManager();
		//�����Ԃ�
		return mp_instance;
	}

	void Add(Task* a);
	void DrawAll();
	void Delete(Task* a);
	struct SearchID* Search(int id);
};

struct SearchID
{
	Task* s_point = nullptr;
	SearchID* s_next = nullptr;
};
