#pragma once
class Task;


//�R�����g�������܂��傤
//private�ɑ厖�ȏ��͂��܂�
//�R���X�g���N�^�Ń^�C�v�ƗD��x��^���Ă��
//�擪���璲�ׂĂ����D��x���Ⴍ�Ȃ�Ƃ���֑}��
//�t�����h�N���X�𗘗p���ē���̃I�u�W�F�N�g�ɂ͎g�p������   friend class Task
//friend class TaskManager
//





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
