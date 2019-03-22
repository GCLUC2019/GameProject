#include "Tutorial.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../Character/Player.h"
#include "../Character/EnemyBase/Enemy/TutorialEnemy.h"
#include "../Stage/ground.h"
#include "../Resource/Resource.h"
#include "../GameProject/Game/Scene/Title.h"
#include "../GameProject/Game/UI/UI.h"

Tutorial::Tutorial() : Task(eGameTutorial)
{
	new TutorialResource();

	TaskManager::GetInstance()->AddTask(new Stage01());
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new TutorialEnemy(CVector2D(800, 550)));
	TaskManager::GetInstance()->AddTask(new Balloon());
	TaskManager::GetInstance()->AddTask(new DescriptionUI());
	TaskManager::GetInstance()->AddTask(new UI());
	SOUND("n82")->Play(true);
}

Tutorial::~Tutorial()
{
	SOUND("n82")->Stop();
	TaskManager::GetInstance()->AddTask(new Title());

}

void Tutorial::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton5))
		TaskManager::KillAll();
}

void Tutorial::Draw()
{

}

Balloon::Balloon() : Task(CharacterData::eBalloon)
{
	m_img = COPY_RESOURCE("BalloonUI", CImage*);
	m_pos = CVector2D(5, 595);
	cnt = 0;
}

void Balloon::Update()
{
	
	if (CInput::GetState(0, CInput::ePush, CInput::eButton6)) ++cnt;
	if (cnt >= 9) SetKill();
}

void Balloon::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetSize(1270, 120);
	m_img.Draw();
}



DescriptionUI::DescriptionUI() : Task(eDescriptionUI),
m_font("",32)
{
	//���݂̕\���e�L�X�g�ʒu������
	m_line = 0;
	//�e�L�X�g�s��������
	m_line_size = 0;
	FILE *fp;	//�t�@�C���|�C���^
				//�@�t�@�C�����J��
	fopen_s(&fp, "../data/UIData/UIData.txt", "r");
	//�J���Ȃ������牽�����Ȃ�
	if (!fp) {
		printf("�t�@�C�����J���܂���");
		return;
	}
	//�A�t�@�C���̏I���܂ŌJ��Ԃ��A�e�L�X�g��ǂݍ���
	while (!feof(fp)) {
		//�P�s�ǂݍ���
		fgets(m_text[m_line_size], 128, fp);
		//�s�������Z�@�ǂݍ��񂾍s�����J�E���g����
		m_line_size++;
	}
	//�B�t�@�C�������
	fclose(fp);
	
}

void DescriptionUI::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton6)) {
		m_line++;
	}
}

void DescriptionUI::Draw()
{
	if (m_line <= m_line_size) {
		//1�s�\��
		m_font.Draw(20, 665, 1, 1, 1, m_text[m_line]);
	}
}

