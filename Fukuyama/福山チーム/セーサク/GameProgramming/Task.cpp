#include "Task.h"
#include "TaskManager.h"
#include "GID.h"
#include <stdio.h>

//�f�t�H���g�R���X�g���N�^
Task::Task() :
m_updateLink(eUp_Max, this),
m_renderLink(eRd_Max, this),
m_id(eId_Max)
{

}

Task::Task(int id, int updatePrio, int renderPrio) :
m_updateLink(updatePrio, this),
m_renderLink(renderPrio, this),
m_id(id),
m_destroyFlg(false)
{
	//	printf("CTask[%d] Prio[%d/%d]\n", id, updatePrio, renderPrio);
	//�^�X�N�쐬��A�����Ń}�l�[�W���[�ɓo�^
	TaskManager::GetInstance()->AddTask(this);
}

Task::~Task()
{

}

void Task::Update(float delta_time)
{
	//	printf("Update[%d] Prio[%d]\n", m_id, m_updateLink.GetPriority());
}

void Task::Render()
{
}

void Task::ChangeUpdatePrio(int updatePrio)
{
	TaskManager::GetInstance()->ChangeUpdatePrio(this, updatePrio);
}

void Task::ChangeRenderPrio(int renderPrio)
{
	TaskManager::GetInstance()->ChangeRenderPrio(this, renderPrio);
}
