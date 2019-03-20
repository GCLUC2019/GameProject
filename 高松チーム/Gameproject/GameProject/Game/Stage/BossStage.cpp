#include "BossStage.h"
#include "../../Game/GameData/GameData.h"
BossStage::BossStage():Task(eBossStage)
{
    m_img = COPY_RESOURCE("BossStage", CImage*);
    m_pos = CVector2D(640, 600);
}

void BossStage::Update()
{
}

void BossStage::Draw()
{
    m_img.SetPos(640 - g_game_data.m_scroll.x, 300 - g_game_data.m_scroll.y/3);
    m_img.SetCenter(640, 600);
    m_img.SetSize(1280, 1200);
    m_img.Draw();
}
