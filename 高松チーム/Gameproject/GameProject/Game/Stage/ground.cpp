#include "ground.h"
#include "../Stage/ground.h"
#include "../GameData/GameData.h"

Stage01::Stage01() : Task(eStage01)
{
	
	//TaskManager::GetInstance()->AddTask(new SkyRed());
	TaskManager::GetInstance()->AddTask(new SkyBlue());
	TaskManager::GetInstance()->AddTask(new Bamboo());
	TaskManager::GetInstance()->AddTask(new Ground());
}


Ground::Ground() : Task(eGround)
{
	m_img = COPY_RESOURCE("Ground", CImage*);
}

void Ground::Update()
{

}

void Ground::Draw()
{
	m_img.SetSize(4000, 1400);
    m_img.SetPos(0 - g_game_data.m_scroll.x, -680 - g_game_data.m_scroll.y/3);
	m_img.Draw();
}



Bamboo::Bamboo() : Task(eBamboo)
{
	m_img = COPY_RESOURCE("Bamboo", CImage*);
}

void Bamboo::Update()
{
}

void Bamboo::Draw()
{
	m_img.SetSize(2000, 700);
	m_img.SetPos(0 - g_game_data.m_scroll.x,  - g_game_data.m_scroll.y/10);
	m_img.Draw();
}


SkyBlue::SkyBlue() : Task(eSkyBlue)
{
	m_img = COPY_RESOURCE("SkyBlue", CImage*);
}

void SkyBlue::Update()
{
}

void SkyBlue::Draw()
{
	m_img.SetSize(2000, 700);
	m_img.SetPos(0 - g_game_data.m_scroll.x, -200 - g_game_data.m_scroll.y / 10);
	m_img.Draw();
}


SkyRed::SkyRed() : Task(eSkyRed)
{
	m_img = COPY_RESOURCE("SkyRed", CImage*);
}

void SkyRed::Update()
{
}

void SkyRed::Draw()
{
	m_img.SetSize(2000, 700);
	m_img.SetPos(0 - g_game_data.m_scroll.x, -350 - g_game_data.m_scroll.y/10);
	m_img.Draw();
}


