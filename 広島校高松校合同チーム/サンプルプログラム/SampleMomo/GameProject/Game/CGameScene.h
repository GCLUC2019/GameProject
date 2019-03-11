#pragma once
#include "CObject.h"
#include "../Global.h"

#define GAME_SCENE_OBJECT_MAX (3000)

class CGameScene : public CObject {
private:
	int m_game_scene_object_num = 0;
	Task * m_game_scene_object_p[GAME_SCENE_OBJECT_MAX];
	CVector3D m_game_scene_limit_pos;
public:
	CGameScene();
	~CGameScene();
	void Init();
	void Setup();
	void SetGameSceneLimitPos(CVector3D _limit_pos) { m_game_scene_limit_pos; };
	CVector3D GetGameSceneLimitPos() {return m_game_scene_limit_pos;  };
	void AddGameSceneObject(Task* _object);
	void ClearGameSceneObject();

	static CGameScene* GetInstance();
};