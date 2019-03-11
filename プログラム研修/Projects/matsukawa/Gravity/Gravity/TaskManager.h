#pragma once
#include "Task.h"
#include <list>

class TaskManager
{
private:
	//�^�X�N�}�l�[�W���[�̃C���X�^���X
	static TaskManager* mp_instance;
protected:
	Task * mp_head;  //���X�g�̐擪
	Task * mp_tail;  //���X�g�̖���
public:
	TaskManager();
	~TaskManager();
	void AddTask(Task* p);    //�^�X�N�̒ǉ�
	void SelectKill();        //�w�肵���^�X�N�݂̂�j��
	void SetKillAll();        //�S�Ẵ^�X�N�̔j���t���O�𗧂Ă�
	void UpdateAll();         //�^�X�N��S�ăA�b�v�f�[�g
	void DrawAll();           //�^�X�N��S�ĕ`��
	void KillAll();           //�^�X�N��S�Ĕj��
	//�^�X�N�̗D�揇�ʂ̕ύX
	void ChangePrio(Task* p, int priorty);
	void RemoveTask(Task*p);  //�^�X�N�̘A�����O��

	void Kill(Task* p);
	static TaskManager* GetInstance();
};