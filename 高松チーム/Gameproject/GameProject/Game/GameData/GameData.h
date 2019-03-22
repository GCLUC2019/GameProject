#pragma once
#include"../../stdafx.h"
 struct GameData
{
	 CVector2D m_scroll;
	 int m_score;
	 int m_dead_cnt;
	 float m_boss_hp = 100;
	 bool m_player_switch_flg;
	 bool m_gamescene_flg;
	 bool m_font_flg;
};
extern GameData g_game_data;
