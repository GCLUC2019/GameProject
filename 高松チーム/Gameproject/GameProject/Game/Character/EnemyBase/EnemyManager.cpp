#include "EnemyManager.h"
#include "../EnemyBase/Enemy/Enemy01.h"
#include "../EnemyBase/Enemy/Enemy02.h"
#include "../EnemyBase/Enemy/Enemy05.h"

#define X_RAND_MIN 50
#define X_RAND_MAX 1230
#define Y_RAND_MIN 360
#define Y_RAND_MAX 670

EnemyManager::EnemyManager(): Task(CharacterData::eEnemyBaseManager),
	m_wave_flg(false),
	m_appear_type(EnemyManagerWave::eWave1_1),
	m_wave1_1_flg(false),
	m_wave1_2_flg(false),
	m_wave2_1_flg(false),
	m_wave2_2_flg(false)
{
	WaveLoad();
}

void EnemyManager::Update()
{

	

	++m_cnt;
	if (m_cnt >= 300)	m_appear_type = EnemyManagerWave::eWave1_2;
	if (m_cnt >= 1000)	m_appear_type = EnemyManagerWave::eWave2_1;
	if (m_cnt >= 1600)	m_appear_type = EnemyManagerWave::eWave2_2;

}

void EnemyManager::Draw()
{
	/*switch (m_appear_type) {
	case EnemyManagerWave::eWave1_1:
		if (m_wave1_1_flg == false) {
			m_wave1_1_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
		}
		break;

	case EnemyManagerWave::eWave1_2:
		if (m_wave1_2_flg == false && m_wave1_1_flg == true) {
			m_wave1_2_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
		}
		break;



	case EnemyManagerWave::eWave2_1:
		if (m_wave2_1_flg == false && m_wave1_2_flg == true) {
			m_wave2_1_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
		}
		break;

	case EnemyManagerWave::eWave2_2:
		if (m_wave2_2_flg == false && m_wave2_1_flg == true) {
			m_wave2_2_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(X_RAND_MIN, X_RAND_MAX), Utility::Rand(Y_RAND_MIN, Y_RAND_MAX))));
		}
		break;

	default:
		break;
	}*/
}

void EnemyManager::WaveLoad()
{
	FILE *fp;
	fopen_s(&fp, "../data/EnemyData/EnemyData.txt", "r");
	if (fp == NULL) {
		printf("ファイルが開けません");
		return;
	}
	//①ファイルの終わりまで繰り返す
	while (!feof(fp)) {
		char key[64];
		//②単語（一つの文字列）を読み込む
		fscanf_s(fp, "%s", key, 64);
		//③読み込んだ単語がEnemyDataなら
		if (strcmp(key, "EnemyData") == 0) {
			while (!feof(fp)) {
				//④単語（一つの文字列）を読み込む
				fscanf_s(fp, "%s", key, 64);
				//⑤Endが出でたら、読み込み終了
				if (strcmp(key, "END") == 0) break;
				//⑥そうじゃなかったら敵のデータを読みこむ
				//　敵を生成する
				int x, y;
				int enemy_type = atoi(key);
				fscanf_s(fp, "%d %d", &x, &y);
				TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(x, y)));
			}
		}
	}

	fclose(fp);
}


