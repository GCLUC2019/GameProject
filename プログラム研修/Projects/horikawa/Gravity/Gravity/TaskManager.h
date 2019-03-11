#pragma once
class Task;


//�R�����g�������܂��傤
//private�ɑ厖�ȏ��͂��܂�
//�R���X�g���N�^�Ń^�C�v�ƗD��x��^���Ă��
//�擪���璲�ׂĂ����D��x���Ⴍ�Ȃ�Ƃ���֑}��
//�t�����h�N���X�𗘗p���ē���̃I�u�W�F�N�g�ɂ͎g�p������   friend class Task
//friend class TaskManager
//





class TaskManager {
public:
	static TaskManager* mp_instance;
	static Task* mp_head;
public:
	static TaskManager* GetInstance() {
		//�C���X�^���X����x�̂ݐ������Ċi�[
		if (mp_instance == nullptr) mp_instance = new TaskManager();
		//�����Ԃ�
		return mp_instance;
	}
	//Task���p�������I�u�W�F�N�g���쐬�������ɌĂ΂�A�Ō���ɒǉ�����
	void Add(Task* a);
	//�S�ẴI�u�W�F�N�g�̕`�揈��
	void DrawAll();
	//�����ŗ^�����I�u�W�F�N�g�̍폜
	void Delete(Task* a);
	//�����ŗ^����ID�����I�u�W�F�N�g��P�������X�g�̍\���̂ł܂Ƃ߁A���̐擪��Ԃ�
	struct SearchID* Search(int id);
};

//�w�肳�ꂽ�I�u�W�F�N�g�������P�������X�g�ł܂Ƃ߂Ă����\����
struct SearchID
{
	Task* point = nullptr;
	SearchID* next = nullptr;
};
