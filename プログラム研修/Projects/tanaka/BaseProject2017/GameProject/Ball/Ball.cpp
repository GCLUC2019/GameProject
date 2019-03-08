#include "Ball.h"
#include "../Global.h"

CVector2D point_data[] = {
    CVector2D(100,100),
    CVector2D(1280-100,100),
    CVector2D(1280/2,780/2),
    CVector2D(100,780/2-100),
    CVector2D(1280-100,780/2-100),
};
const int point_data_size = ARRAY_SIZE(point_data);
//�������q���X�g
//�w�b�_�Œ�`���ꂽ���ɏ����������
//���S�ʂ��l������ƃ|�C���^�Ȃǂ̓R���X�g���N�^���Œ�`�����ق����ǂ�
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
    //int point_data_num = sizeof(point_data) / sizeof(point_data[0]);
    int r = rand() % POINT_MAX;
    //�m�F�f�o�b�O�p
    static_assert(POINT_MAX == point_data_size, "�v�f���I�[�o�[");//�x�����o����
    assert(r < POINT_MAX);
	m_pos = point_data[r];
    m_vec = CVector2D(0, -20);
}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{

    m_vec.y += GRAVITY * delta_time;
    m_pos += m_vec * delta_time;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}


