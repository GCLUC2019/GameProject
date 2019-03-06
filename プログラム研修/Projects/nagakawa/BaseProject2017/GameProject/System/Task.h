/**
* @Brief	�^�X�N�V�X�e�����
*/

#ifndef TASK_GUARD
#define TASK_GUARD

#include "TaskLinker.h"
#include "../GID.h"

class Task
{
protected:
	TaskLinker m_updateLink;				//�X�V�p�����N 
	TaskLinker m_renderLink;				//�`��p�����N 
	int		   m_id;						//�^�X�NID
	bool	   m_destroyFlg;				//�폜�t���O

public:
	Task();						    
	Task(int id, int updateprio, int renderPrio);
	virtual ~Task();
	virtual void Update(float delta_time);
	virtual void Render();					//�h����ŕ`��
	void ChangeUpdatePrio(int updatePrio);	//�X�V���ʕύX
	void ChangeRenderPrio(int renderPrio);	//�`�揇�ʕύX
								
	void SetKill()							//�폜�t���OON 
	{
		m_destroyFlg = true;
	}

	inline int GetUpdatePrio() const		//�X�V���ʎ擾�֐�
	{
		return m_updateLink.GetPriority();
	}

	inline int GetRenderPrio() const		//�`�揇�ʎ擾�֐�
	{
		return m_renderLink.GetPriority();
	}

	inline int GetID() const				//�^�X�NID�擾 
	{
		return m_id; 
	}

	friend class TaskManager;
};

#endif