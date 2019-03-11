#pragma once
#include "Task.h"
#include <list>

//�^�X�NID
enum {
	Task_id = 0,
	TaskA_id = 1,
};

//�^�X�N�D��x
enum {
	Task_prio = 0,
	TaskA_prio = 1,
};


class TaskManagement
{
private:
	//�^�X�N�}�l�W�����g�V�X�e���̃C���X�^���X
	static TaskManagement* mp_t_ins;
protected:
	Task * mp_head;   //�擪�|�C���^
	Task * mp_tail;   //�����|�C���^
public:
	TaskManagement();
	~TaskManagement();
	//�^�X�N�ǉ��֐��i�����͒ǉ��������^�X�N�̃|�C���^�j
	void Add(Task* _add);
	//�擪�^�X�N�Z�b�g�֐��i�����͐擪�ɒu�������^�X�N�̃|�C���^�j
	void SetHead(Task* add_t);
	//�����^�X�N�Z�b�g�֐�(�����͖����ɒu�������^�X�N�̃|�C���^�j
	void SetTail(Task* add_t, Task* now_t);
	//�^�X�N�}���֐��i�����͑}�������������^�X�N�Ƃ��̏ꏊ�ɂ���^�X�N�j
	void InsertTask(Task* add_t, Task* now_t);
	//�^�X�N��S�ăA�b�v�f�[�g
	void UpdateAll();       
	//�^�X�N��S�ĕ`��
	void DrawAll();
	//�������珇�Ԃɕ`�悷��
	void DrawTailAll();
	//�t���O���������^�X�N�����L��
	void FlagKill();
	//�j���t���O��S�ė��Ă�֐�
	void KillFlagAll();
	//�^�X�N��S�Ĕj������֐�
	void KillAll();
	//�^�X�N���E�֐��i�����͊O�������^�X�N�j
	void RemoveTask(Task* rem_p);
	//�^�X�N�D��x�ύX�֐�(�����͕ς������^�X�N�ƗD��x�j
	void ChangePrio(Task* change_p, int priority);
	//�^�X�N�j���֐�(�����͔j���������^�X�N
	void Kill(Task* kill_p);

	//�^�X�N�擾�֐�(�����͎擾�������^�X�N��ID)
	Task* GetTask(int&id)const;
	//�^�X�N���X�g�擾�֐�
	std::list<Task*> GetTasks(int& id) const;	
	//���J�E���g�֐�
	int GetCount(int& id)const;

	//�^�X�N�}�l�W�����g�̃|�C���^�����擾
	static TaskManagement* GetIns();
	//�C���X�^���X�̃N���A
	static void ClearIns();
};
