#include "EnemyManager.h"
#include "../GameProject/Game/GameData/GameData.h"
#include "../EnemyBase/Enemy/Enemy01.h"
#include "../EnemyBase/Enemy/Enemy02.h"
//#include "../EnemyBase/Enemy/Enemy03.h"
#include "../EnemyBase/Enemy/Enemy04.h"
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
	WaveLoad1();
	//EnemyLoad();
}

void EnemyManager::Update()
{
	if (g_game_data.m_dead_cnt >= 3 && m_wave1_2_flg == false) {
		m_wave1_2_flg = true;
		WaveLoad1();
	}

	

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

void EnemyManager::EnemyLoad()
{
	//FILE *fp;
	//fopen_s(&fp, "../data/EnemyData/EnemyData.txt", "r");
	//if (fp == NULL) {
	//	printf("ファイルが開けません");
	//	return;
	//}
	////①ファイルの終わりまで繰り返す
	//while (!feof(fp)) {
	//	char key[64];
	//	//②単語（一つの文字列）を読み込む
	//	fscanf_s(fp, "%s", key, 64);
	//	//③読み込んだ単語がEnemyDataなら
	//	if (strcmp(key, "EnemyData") == 0) {
	//		while (!feof(fp)) {
	//			//④単語（一つの文字列）を読み込む
	//			fscanf_s(fp, "%s", key, 64);
	//			//⑤Endが出でたら、読み込み終了
	//			if (strcmp(key, "END") == 0) break;
	//			//⑥そうじゃなかったら敵のデータを読みこむ
	//			//　敵を生成する
	//			int x, y;
	//			int enemy_type = atoi(key);
	//			fscanf_s(fp, "%d %d", &x, &y);
	//			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(x, y)));
	//		}
	//	}
	//}
	//fclose(fp);

}

void EnemyManager::WaveLoad1()
{
	FILE *fp;
	fopen_s(&fp, "../data/EnemyData/EnemyData.txt", "r");
	if (fp == NULL) {
		printf("ファイルが開けません");
		return;
	}
	//①ファイルの終わりまで繰り返す
	while (!feof(fp)) {
		char wave_key[64];
		//②単語（一つの文字列）を読み込む
		fscanf_s(fp, "%s", wave_key, 64);
		//③読み込んだ単語がEnemyDataなら
		if (strcmp(wave_key, "WaveData1_1") == 0) {
			while (!feof(fp)) {
				//⑤Endが出でたら、読み込み終了
				if (strcmp(wave_key, "END1_1") == 0) break;
				char key[64];
				//②単語（一つの文字列）を読み込む
				fscanf_s(fp, "%s", key, 64);
				//③読み込んだ単語がEnemyDataなら
				if (strcmp(key, "EnemyData1_1") == 0) {
					while (!feof(fp)) {
						//④単語（一つの文字列）を読み込む
						fscanf_s(fp, "%s", key, 64);
						//⑤Endが出でたら、読み込み終了
						if (strcmp(key, "END_Enemy1_1") == 0) break;
						//⑥そうじゃなかったら敵のデータを読みこむ
						//　敵を生成する
						int x, y;
						int enemy_type = atoi(key);
						fscanf_s(fp, "%d %d", &x, &y);

						switch (enemy_type)
						{
						case eEnemy01:
							TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(x, y)));
							break;
						case eEnemy02:
							TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(x, y)));
							break;
						case eEnemy04:
							TaskManager::GetInstance()->AddTask(new Enemy04(CVector2D(x,y)));
							break;
						case eEnemy05:
							TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(x, y)));
							break;
						default:
							break;
						}
					}
				}
			}
		}


		if (g_game_data.m_dead_cnt >= 4) {
			char wave2_key[64];
			//②単語（一つの文字列）を読み込む
			fscanf_s(fp, "%s", wave2_key, 64);
			//③読み込んだ単語がEnemyDataなら
			if (strcmp(wave2_key, "WaveData1_2") == 0) {
				while (!feof(fp)) {
					//⑤Endが出でたら、読み込み終了
					if (strcmp(wave2_key, "END1_2") == 0) break;
					char key[64];
					//②単語（一つの文字列）を読み込む
					fscanf_s(fp, "%s", key, 64);
					//③読み込んだ単語がEnemyDataなら
					if (strcmp(key, "EnemyData1_2") == 0) {
						while (!feof(fp)) {
							//④単語（一つの文字列）を読み込む
							fscanf_s(fp, "%s", key, 64);
							//⑤Endが出でたら、読み込み終了
							if (strcmp(key, "END_Enemy1_2") == 0) break;
							//⑥そうじゃなかったら敵のデータを読みこむ
							//　敵を生成する
							int x, y;
							int enemy_type2 = atoi(key);
							fscanf_s(fp, "%d %d", &x, &y);

							switch (enemy_type2)
							{
							case eEnemy01:
								TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(x, y)));
								break;
							case eEnemy02:
								TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(x, y)));
								break;
							case eEnemy04:
								TaskManager::GetInstance()->AddTask(new Enemy04(CVector2D(x, y)));
								break;
							case eEnemy05:
								TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(x, y)));
								break;
							default:
								break;
							}
						}
					}
				}
			}
		}

	}
	fclose(fp);
}


