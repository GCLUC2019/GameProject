#pragma once
#include "CObject.h"
#include "../Global.h"

class CCharacter;
class CCharacterEnemy;

#define GAME_WAVE_ENEMY_MAX (3000)

/*
敵のグループが出現して倒されるまでのゲームシーンでのウェーブを管理する。
ギミックの1つとして取り扱う。
ウェーブが完了されたらゲームシーンに完了されたことを報告する。
敵の管理とウェーブ終了を伝えるだけの機能
*/


//ポインタで管理し
class CGameSceneWave : public CObject {
private:
	int m_pop_enemy_num = 0;
	int m_count_dead = 0;
	CCharacter* m_pop_enemy_p[GAME_WAVE_ENEMY_MAX];
public:
	CGameSceneWave(int _wave_id);
	~CGameSceneWave();
	void CheckDeadCount();

	void Init();

	//ポップさせた敵が倒された場合の処理
	void DeadEnemy(int _character_id);
};