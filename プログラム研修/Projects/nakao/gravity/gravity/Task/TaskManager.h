#pragma once
#include"Task.h"

class TaskManager {
private:
	static Task * m_head;	//�擪�|�C���^
	static Task * m_last;	//�����|�C���^

public:
	TaskManager();
	/*!
	@brief	�擪�ɐڑ�
	@param	Task* t			[in] �쐬�����I�u�W�F�N�g�̃|�C���^
	**/
	static void Addf(Task* t);
	/*!
	@brief	�����ɐڑ�
	@param	Task* t			[in] �쐬�����I�u�W�F�N�g�̃|�C���^
	**/
	static void Add(Task* t);
	static Task* GetHead() {
		return m_head;
	}
	static Task* GetLast() {
		return m_last;
	}
	/*!
	@brief	�����ɐڑ�
	@param	bool f			[in]�t���O�@ture�Ȃ珸��flse�Ȃ�~�� 
	**/
	static void TaskSort(bool f);
	
	static void SetHead(Task* t) {
		m_head = t;
	}
	static void SetLast(Task* t) {
		m_last = t;
	}
	/*!
	@brief	����ւ��֐��@t1��t2�����ւ���
	@param	Task* t1			[in] ����ւ������I�u�W�F�N�g�̃|�C���^
	@param	Task* t2			[in] ����ւ������I�u�W�F�N�g�̃|�C���^
	**/
	static void Swap(Task* t1, Task* t2);
	/*!
	@brief	���X�g�S�Ă�Draw�֐����Ăяo��
	@param	Task* t			[in] �I�u�W�F�N�g�̃|�C���^
	@param	bool f			[in] �t���O�@ture�Ȃ�擪����flse�Ȃ疖������
	**/
	static void DrawAll(Task* t, bool f);
};
