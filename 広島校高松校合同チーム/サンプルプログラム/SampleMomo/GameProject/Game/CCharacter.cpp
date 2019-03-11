#include "CCharacter.h"

CCharacter::CCharacter(int _task_id, int _draw_priority) : CObject(_task_id, _draw_priority)
{

}

CCharacter::~CCharacter()
{

}

void CCharacter::Update()
{

}

void CCharacter::Draw()
{
}

void CCharacter::CollisionCheck(Task * _collision_task)
{

	CObject* ob = dynamic_cast<CObject*>(_collision_task);
	CVector3D ob_pos = ob->GetPos();
	CVector3D ob_rads = ob->GetRads();

	if (CollisionCheck3D(CVector3D(m_pos.x,m_pos_old.y,m_pos_old.z),m_rads,ob_pos,ob_rads)) {
		m_pos.x = m_pos_old.x;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.y = m_pos_old.y;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos_old.y, m_pos.z), m_rads, ob_pos, ob_rads)) {
		m_pos.z = m_pos_old.z;
	};

	CollisionCheckCharacter(_collision_task);
}

void CCharacter::CollisionCheckCharacter(Task * _collision_task)
{
}
