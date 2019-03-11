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

	void SetGameSceneLimitPosMax(CVector3D _limit_pos) { m_game_scene_limit_pos_max = _limit_pos; };
	CVector3D GetGameSceneLimitPosMax() {return m_game_scene_limit_pos_max;  };
	
	void SetGameSceneLimitPosMin(CVector3D _limit_pos) { m_game_scene_limit_pos_min = _limit_pos; };
	CVector3D GetGameSceneLimitPosMin() { return m_game_scene_limit_pos_min; };

	void AddGameSceneObject(Task* _object);
	void ClearGameSceneObject();

	static CGameScene* GetInstance();
};