#include "BossStage.h"
#include "../../Game/GameData/GameData.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../../Game/Stage/CollisionBox.h"
BossStage::BossStage():Task(eBossStage)
{
    m_img = COPY_RESOURCE("BossStage", CImage*);
    m_pos = CVector2D(640, 600);
    TaskManager::GetInstance()->AddTask(new CollisionBox(CVector2D(222, 0), CRect(-222, -22, 222, 22)));
    TaskManager::GetInstance()->AddTask(new CollisionBox(CVector2D(1120, 0), CRect(-222, -22, 222, 22)));

}

void BossStage::Update()
{
}

void BossStage::Draw()
{
    m_img.SetPos(0, -(1200-720)- g_game_data.m_scroll.y/3);
    m_img.SetSize(1280, 1200);
    m_img.Draw();
}
