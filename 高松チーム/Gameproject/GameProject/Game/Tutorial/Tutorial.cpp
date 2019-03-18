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
    //���݂̕\���e�L�X�g�ʒu������
    m_line = 0;
    //�e�L�X�g�s��������
    m_line_size = 0;
    FILE *fp;	//�t�@�C���|�C���^
                //�@�t�@�C�����J��
    fopen_s(&fp, "../data/text.txt", "r");
    //�J���Ȃ������牽�����Ȃ�
    if (!fp) return;

    //�A�t�@�C���̏I���܂ŌJ��Ԃ��A�e�L�X�g��ǂݍ���
    while (!feof(fp)) {
        //�P�s�ǂݍ���
        fgets(m_text[m_line_size], 128, fp);
        //�s�������Z�@�ǂݍ��񂾍s�����J�E���g����
        m_line_size++;
    }
    //�B�t�@�C�������
    fclose(fp);
    if (m_line <= m_line_size) {
        //1�s�\��
        m_font.Draw(100, 700, 1, 1, 1, m_text[m_line]);
    }
}

void Tutorial::Draw()
{

}
