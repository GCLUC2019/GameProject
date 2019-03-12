#include "BossManager.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"


#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768
BossManager::BossManager()
{
	m_img = COPY_RESOURCE("Boss", CAnimImage*);
	m_img2 = COPY_RESOURCE("Boss", CImage*);
	m_img3 = COPY_RESOURCE("Boss", CImage*);
	m_img4 = COPY_RESOURCE("Boss", CAnimImage*);

	m_pos = CVector2D(1280 - BOSS_X_SIZE / 2,720 - BOSS_Y_SIZE / 2);
	m_pos2 = CVector2D(1280 - BOSS_X_SIZE / 1.5, 720 - BOSS_Y_SIZE / 3);
	m_pos3 = CVector2D(1280 - BOSS_X_SIZE / 3, 720 - BOSS_Y_SIZE / 3);
	m_pos4 = CVector2D(1280 - BOSS_X_SIZE / 2, 720 - BOSS_Y_SIZE / 4);

}

void BossManager::Update()
{
	m_img.ChangeAnimation(eBossHeadAnim);
	m_img4.ChangeAnimation(eBossTailAnim);

	m_img.UpdateAnimation();
	m_img4.UpdateAnimation();

}

void BossManager::Draw()
{
	m_img.SetPos(m_pos);
	m_img2.SetPos(m_pos2);
	m_img3.SetPos(m_pos3);
	m_img4.SetPos(m_pos4);

	m_img.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	m_img2.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	m_img3.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	m_img4.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);

	m_img.SetRect(0, 0, BOSS_X_SIZE, BOSS_Y_SIZE);
	m_img2.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 2, BOSS_X_SIZE * 2, BOSS_Y_SIZE * 3);
	m_img3.SetRect(0, BOSS_Y_SIZE * 2, BOSS_X_SIZE, BOSS_Y_SIZE * 3);
	m_img4.SetRect(0, BOSS_Y_SIZE, BOSS_X_SIZE, BOSS_Y_SIZE * 2);

	m_img.Draw();
	m_img2.Draw();
	m_img3.Draw();
	m_img4.Draw();
}
