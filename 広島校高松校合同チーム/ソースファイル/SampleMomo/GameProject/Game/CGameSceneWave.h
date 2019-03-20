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

enum {
	eWave1,
	eWave2,
	eWave3,
	eWave4,
	eWave5,
	eWave6,
	eWave7,
	eWave8,
	eWave9,
	eWave10,
	eWave11,
	eWave12,
	eWave13,
	eWave14,
	eWave15,
	eWave16,
	eWave17,
	eWave18,
};


//ポインタで管理し
class CGameSceneWave : public CObject {
private:
	int m_wave_id;
	int m_next_wave_id;
	int m_pop_enemy_num = 0;
	int m_count_dead = 0;
	CCharacter* m_pop_enemy_p[GAME_WAVE_ENEMY_MAX];
public:
	CGameSceneWave(int _wave_id);
	~CGameSceneWave();
	void CheckDeadCount();

	void Init();
	void LoadWave(int _wave_id);

	//ポップさせた敵が倒された場合の処理
	void DeadEnemy(int _character_id);
};