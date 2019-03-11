#pragma once
/*　担当
	国見　class GameClear
*/
#include "../../Base/Task.h"
#include "../Resource/Resource.h"　

class GameClear : public Task {
private:
	CImage m_gameclear_img;
	CVector2D m_gameclear_pos;

public:
	GameClear();
	void Update();
	void Draw();

};