/*
CKey�N���X
�L�[�{�[�h���͂��擾����
*/
class CKey {
public:
	static bool Flg[256]; //�L�[��������Ă��鎞��true
	//Push��static(�X�^�e�B�b�N)���\�b�h
	//key��������Ă����true
	static bool Push(char key);
	//�L�[�������ꂽ�u�Ԃ���true��Ԃ�
	static bool Once(char key);
};
