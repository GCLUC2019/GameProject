#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2D(0, -20);
}

//�o���ʒu�̐�
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#ifdef _DEBUG
	#define DEBUG_PRINT(s) printf(s)
#else
	#define DEBUG_PRINT(s)
#endif 

#define POINT_MAX 5
CVector2D point_data[] = {
	CVector2D(123,456),
	CVector2D(23,45),
	CVector2D(542,98),
	CVector2D(323,356),
	CVector2D(823,656)
};



const int point_data_size = ARRAY_SIZE(point_data);
Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	DEBUG_PRINT("�f�o�b�O���ł�");

	int i = rand() % point_data_size;
	static_assert(POINT_MAX == point_data_size, "�v�f���I�[�o�[");  //�R���p�C�����ɃG���[���o��
	assert(i < point_data_size);  //�f�o�b�O���̂ݗL��
	m_pos = point_data[i];
	m_vec = CVector2D(0, -20);

#ifdef _DEBUG
	printf("%d�ԖڂɃ{�[�����o�������܂���\n", i + 1);
#endif // _DEBUG
}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{

	m_vec.y += GRAVITY * SPF;
	m_pos += m_vec;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}

void Ball::SetVector(const CVector2D& vec)
{
	m_vec = vec;
}
