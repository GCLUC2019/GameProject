#include "Tutorial.h"
#include "../Character/Player.h"
#include "../Character/EnemyBase/Enemy/TutorialEnemy.h"
#include "../Stage/ground.h"
#include "../Resource/Resource.h"
#include "../GameProject/Game/Scene/Title.h"

Tutorial::Tutorial() : Task(eGameTutorial)
{
	new Resource();
	TaskManager::GetInstance()->AddTask(new Stage01());
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new TutorialEnemy(CVector2D(800, 450)));
}

Tutorial::~Tutorial()
{
	TaskManager::KillAll();
	TaskManager::GetInstance()->AddTask(new Title());
}

void Tutorial::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton6))
		SetKill();
}

void Tutorial::DescriptionUI()
{
    //現在の表示テキスト位置初期化
    m_line = 0;
    //テキスト行数初期化
    m_line_size = 0;
    FILE *fp;	//ファイルポインタ
                //①ファイルを開く
    fopen_s(&fp, "../data/text.txt", "r");
    //開けなかったら何もしない
    if (!fp) return;

    //②ファイルの終わりまで繰り返し、テキストを読み込む
    while (!feof(fp)) {
        //１行読み込む
        fgets(m_text[m_line_size], 128, fp);
        //行数を加算　読み込んだ行数をカウントする
        m_line_size++;
    }
    //③ファイルを閉じる
    fclose(fp);
    if (m_line <= m_line_size) {
        //1行表示
        m_font.Draw(100, 700, 1, 1, 1, m_text[m_line]);
    }
}

void Tutorial::Draw()
{

}
