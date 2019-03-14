#pragma once
/**
* @file		CAnimImage.h
* @brief	�A�j���[�V�����摜�N���X
*
*/

#include "CImage.h"


struct TexAnim {
	int pat;		//�g�p�摜No�i�摜�̍���O�`�j
	int cnt;		//���̉摜�܂ł̑ҋ@�t���[��
};

#define ANIMDATA(data) { data,sizeof(data) / sizeof(data[0])}

struct TexAnimData{
	TexAnim	*pData;
	int		size;
};
class CAnimImage : public CImage {
private:
	TexAnimData	*m_animData;
	int			m_animJam;
	int			m_animIndex;
	float		m_animCount;
	bool		m_animLoop;
	float		m_animSpeed;
	int			m_pat_width;
	int			m_pat_height;
	bool		m_copy;
public:
	/*!
	@brief	�R���X�g���N�^
	**/
	CAnimImage();
	/*!
	@brief	�f�X�g���N�^
	**/
	~CAnimImage();

	/*!
	@brief	�ǂݍ���
	@param	filename	[in] �摜�t�@�C��
	@param	d			[in] TexAnimData�z��̐擪�A�h���X
	@param	width		[in] �ꖇ������̕�
	@param	height		[in] �ꖇ������̍���
	**/
	static CAnimImage* LoadImage(const char* filename, TexAnimData *d = nullptr, int width = 0, int height = 0);

	bool Load(const char* filename, TexAnimData *d = nullptr, int width = 0, int height = 0);

	/*!
	@brief	�R�s�[�R���X�g���N�^
	@param	img			[in] �ǂݍ��ݍς݂̉摜�I�u�W�F�N�g
	@param	d			[in] TexAnimData�z��̐擪�A�h���X
	@param	width		[in] �ꖇ������̕�
	@param	height		[in] �ꖇ������̍���
	**/
	CAnimImage(const CImage& img, TexAnimData *d=nullptr, int width=0, int height=0);
	/*!
	@brief	�R�s�[�R���X�g���N�^
	@param	img			[in] �ǂݍ��ݍς݂̉摜�I�u�W�F�N�g
	@param	d			[in] TexAnimData�z��̐擪�A�h���X
	@param	width		[in] �ꖇ������̕�
	@param	height		[in] �ꖇ������̍���
	**/
	CAnimImage(const CImage* img, TexAnimData *d = nullptr, int width = 0, int height = 0);
	/*!
	@brief	������Z�I�[�o�[���[�h
	@param	img			[in] �ǂݍ��ݍς݂̉摜�I�u�W�F�N�g
	**/
	CAnimImage& operator = (const CImage& img);
	/*!
	@brief	�A�j���[�V�����̍X�V
	**/
	void UpdateAnimation();
	/*!
	@brief	�A�j���[�V�����f�[�^�̃Z�b�g
	@param	d			[in] TexAnimData�z��̐擪�A�h���X
	@param	width		[in] �ꖇ������̕�
	@param	height		[in] �ꖇ������̍���
	**/
	void AttachAnimationData(TexAnimData *d,int width, int height);
	/*!
	@brief	�A�j���[�V�����؂�ւ�
	@param	num			[in] �A�j���[�V�����ԍ�
	@param	loop		[in] �A�j���[�V�������[�v�t���O
	@param	index		[in] �J�n�ʒu
	@param	check		[in] ���ɍĐ����Ȃ�؂�ւ��Ȃ��i�ăX�^�[�g���Ȃ��j
	**/
	void ChangeAnimation(int num, bool loop = true, int index = 0,  bool check = true);
	/*!
	@brief	�A�j���[�V�������x�ύX
	@param	speed		[in] �Đ����x�i�f�t�H���g1�j
	**/
	void SetAnimationSpeed(float speed);
	/*!
	@brief	�A�j���[�V�����I���`�F�b�N
	@retval	�I���Ȃ�true
	**/
	bool CheckAnimationEnd();
	/*!
	@brief	�Đ����̃A�j���[�V�����f�[�^�̎擾�v�t���O
	@retval	���݂̃A�j���[�V�����f�[�^
	**/
	const TexAnim* GetAnimationParam() const {
		return &m_animData[m_animJam].pData[m_animIndex];
	}
	/*!
	@brief	���݂̍Đ��ʒu���擾
	@retval	�Đ��ʒu
	**/
	int GetIndex() {
		return m_animIndex;
	}
	/*!
	@brief	���݂̃J�E���g���擾
	@retval	�J�E���g
	**/
	int GetCount() {
		return m_animCount;
	}
	/*!
	@brief	�`��
	@retval	����
	**/
	void Draw();

};
