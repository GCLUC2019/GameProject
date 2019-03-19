#pragma once
#include"../../stdafx.h"
 struct GameData
{
	 CVector2D m_scroll;
	 int m_score;
	 int m_dead_cnt;
};
extern GameData g_game_data;
