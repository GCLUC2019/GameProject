#pragma once
#include "CObject.h"
#include "../Global.h"

#define GAME_SCENE_OBJECT_MAX (3000)

class CGameScene : public CObject {
private:
	int m_game_scene_object_num = 0;
	Task * m_game_scene_object_p[GAME_SCENE_OBJECT_MAX];
	CVector3D m_game_scene_limit_pos_max;
	CVector3D m_game_scene_limit_pos_min;
public:
	CGameScene();
	~CGameScene();
	void Init();
	void Setup();

	void SetGameSceneLimitPosMax(const CVector3D& _limit_pos) { m_game_scene_limit_pos_max = _limit_pos; };
	const CVector3D& GetGameSceneLimitPosMax() {return m_game_scene_limit_pos_max;  };
	
	void SetGameSceneLimitPosMin(const CVector3D& _limit_pos) { m_game_scene_limit_pos_min = _limit_pos; };
	const CVector3D& GetGameSceneLimitPosMin() { return m_game_scene_limit_pos_min; };

	void AddGameSceneObject(Task* _object);
	void ClearGameSceneObject();

	//ウェーブが完了したら呼ばれる
	void WaveDone();

	void GameOver();

	static CGameScene* GetInstance();
};