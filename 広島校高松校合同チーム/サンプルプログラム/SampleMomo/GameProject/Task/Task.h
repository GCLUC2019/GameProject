#pragma once
#include "TaskManager.h"

class Task {
private:
	//�t�����h�N���X�Ƃ��ă^�X�N�}�l�[�W�����w��
	friend class TaskManager;

	int m_task_id;

	//�`��D��x �������D�悵�ĕ`�悳��� == �ォ��`�悳���(�D��x�������� ��ʂ̑O�ɏo�₷���Ȃ�)
	int m_draw_priority = 0;

	//�폜�t���O(�ꊇ�폜�̕����y���P�[�X�Ȃǂɗp����)
	bool m_is_delete = false;

	Task * m_before_task = nullptr;
	Task * m_next_task = nullptr;

	//TaskManager�N���X���g�p����֐�
	void SetBeforeTask(Task* _before) { m_before_task = _before; };
	Task* GetBeforeTask() { return m_before_task; };

	void SetNextTask(Task* _next) { m_next_task = _next; };
	Task* GetNextTask() { return m_next_task; };

	//@brief �^�X�N�𑦍��ɍ폜����B
	void Delete();
public:
	//@brief �^�X�N�N���X�R���X�g���N�^
	//@param [in] _task_id �^�X�N���ʗp��ID
	//@param [in] _draw_priority �`��D��x(�l�̑傫�����̂�D�悵�Ď�O�ɕ`�悷��)
	Task(int _task_id = 0,int _draw_priority = 0);

	//@brief �^�X�N�N���X�f�X�g���N�^
	virtual ~Task();

	//@brief �X�V�p�֐�(�X�V�̑O�ɌĂ΂��X�V����)
	virtual void BeforeUpdate();

	//@brief �X�V�p�֐�
	virtual void Update();

	//@brief �X�V�p�֐�(��ɌĂ΂��X�V����)
	virtual void AfterUpdate();

	//@brief �`��X�V�p�֐�
	virtual void Draw();

	//@brief �Փ˃`�F�b�N�O�X�V�֐�
	virtual void BeforeCollisionCheck();


	//@brief �Փ˃`�F�b�N�p�֐�
	virtual void CollisionCheck(Task* _collision_task);
	

	//@brief �`��D��x�̐ݒ�
	//@param [in] _priority �`��D��x �������A��O�ɕ`�悷��B
	void SetDrawPriority(int _priority) { m_draw_priority = _priority; };

	//@brief �`��D��x�̎擾
	int GetDrawPriority() { return m_draw_priority; };

	//@brief �^�X�NID�̐ݒ�
	//@param [in] _priority _task_id �ݒ肷��^�X�NID
	void SetTaskId(int _task_id) { m_task_id = _task_id; };

	//@brief �^�X�NID�̎擾
	int GetTaskId() { return m_task_id; };

	

	//@brief �^�X�N�ɍ폜�t���O��ݒ肷��B(�X�V�������I����A�ꊇ�ɍ폜�����)
	void SetIsDelete() {m_is_delete = true; };//�폜�t���O���I���ɂ���

	//@brief �폜�t���O�̉ۂ��擾����B
	bool GetIsDelete() { return m_is_delete; };
};

/*
2019/03/07 Task�N���X��`�B��{�@�\�����B by shingai
2019/03/08 TaskManager�N���X�ւ̏C���ɍ��킹�����K�͂ȏC���B by shingai
2019/03/11 BeforeUpdate���A�Q�[���̐���ɖ��ɗ������o�֐��ǉ��B
*/
