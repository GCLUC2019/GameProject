#pragma once
#include "CObject.h"
#include "../Global.h"

#define GAME_SCENE_OBJECT_MAX (3000)

class CCharacterPlayer;

enum {
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
	float m_next_scene_pos = 0;//���̒n�_�܂œ��B����ƃV�[���J��
	CCharacterPlayer* m_player_object_p = nullptr;

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

	//�E�F�[�u������������Ă΂��
	void WaveDone();

	void Update();

	void CheckSceneChange();

	void GameOver();

	void StageClear();

	void PopPlayer();
	void DeletePlayer();
	void SetupScene();

	void ChangeScene(int _scene_id);

	static CGameScene* GetInstance();
};