#pragma once
#include "CObject.h"
#include "../Global.h"

#define GAME_SCENE_OBJECT_MAX (3000)

#define RESERVE_MAX (12)
#define RESERVE_DEFAULT (6)

class CCharacterPlayer;

enum {
	eTutorial,
	eStage1,
	eStage1Boss,
};
class CGameScene : public CObject {
private:
	int m_game_scene_object_num = 0;
	Task * m_game_scene_object_p[GAME_SCENE_OBJECT_MAX];
	CVector3D m_game_scene_limit_pos_max;
	CVector3D m_game_scene_limit_pos_min;
	int m_now_scene = -1;

	int m_next_scene = -1;
	float m_next_scene_pos = 0;//この地点まで到達するとシーン遷移
	CCharacterPlayer* m_player_object_p = nullptr;

	int m_last_wave = -1;
	CVector3D m_check_point;

	//残機の数
	int m_reserve_num = 0;

	bool m_is_ended_tutorial = false;

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

	void EraseGameSceneObject(Task* _object);

	//ウェーブが完了したら呼ばれる
	void WaveDone(int _next_wave);

	void Update();

	void CheckSceneChange();

	void Miss();

	void StageClear();

	void PopPlayer();
	void DeletePlayer();
	void SetupScene();

	void ReturnTitle();
	void Continue();

	void ChangeScene(int _scene_id);

	int* GetReserveNumPointer() { return &m_reserve_num; };

	void SetCheckPoint(CVector3D _pos) { m_check_point = _pos; };

	CVector3D GetCheckPoint() { return m_check_point; };

	static CGameScene* GetInstance();
};