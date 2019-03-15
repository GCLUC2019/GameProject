#pragma once

class Task;

//�}�����ł���Ε`�揇�ԂƂ����o�u���\�[�g�Ƃ����ׂ̍����������Ȃ��Ă悢

//class TaskManager;

class TaskManager {
private:
	
	friend class Task;
	int m_task_num = 0;
	Task * m_head_task = nullptr;

	void QuickSort(Task** _task_array, int* _task_dp_array, int _task_num) {
		register int base_ad = _task_num / 2;
		register bool is_last_left;
		register bool is_last_right;
		register int left_ad;
		register int right_ad;
		register int left_task_num = _task_num / 2;
		register int right_task_num = _task_num - left_task_num;
		register int work;
		register Task* work_task_p;


		while (true) {
			is_last_left = false;
			is_last_right = false;


			left_ad = 0;
			while (true) {
				if (_task_dp_array[left_ad] > _task_dp_array[base_ad]) break;
				left_ad++;
				if (left_ad >= base_ad) {
					left_ad = base_ad;
					is_last_left = true;
					break;
				}
			}

			right_ad = _task_num - 1;
			while (true) {
				if (_task_dp_array[right_ad] < _task_dp_array[base_ad]) break;
				right_ad--;
				if (right_ad <= base_ad) {
					right_ad = base_ad;
					is_last_right = true;
					break;
				}
			}

			if (is_last_left == true && is_last_right == true) {
				if (left_task_num > 1) QuickSort(_task_array, _task_dp_array, left_task_num);
				if (right_task_num > 1) QuickSort(_task_array + left_task_num, _task_dp_array + left_task_num, right_task_num);
				break;
			}
				
				
			work = _task_dp_array[left_ad];
			_task_dp_array[left_ad] = _task_dp_array[right_ad];
			_task_dp_array[right_ad] = work;

			work_task_p = _task_array[left_ad];
			_task_array[left_ad] = _task_array[right_ad];
			_task_array[right_ad] = work_task_p;
			}
		}


	Task* GetHead() { return m_head_task; };

	//�^�X�N�c���[�ɍ폜�E�ǉ����̕ύX�������Ă��邩�ǂ����B
	bool m_is_changed_task_tree = false;

	//�^�X�N�̃c���[�̓��e���ύX�Ȃ�(�ǉ��E�폜���s���ĂȂ��ꍇ)�ɔz����g���܂킷�ׂ̂���
	Task** m_keep_task_array = nullptr;
	int* m_keep_task_dp_array = nullptr;


public:
	//@brief �^�X�N��ǉ�����
	//@param [in] _task �Y���^�X�N�ւ̃|�C���^
	void AddTask(Task* _task);

	//@brief �^�X�NID����^�X�N��T�����A��ԍŏ��Ɍ����������̂�Ԃ��B
	//@param [in] _task_id �T���^�X�N��ID
	Task* FindTask(int _task_id);

	//@brief �^�X�NID����^�X�N��T�����A�Y��ID�̃^�X�N�ō\�����ꂽ�z����쐬���A���̔z��̃|�C���^��Ԃ��B�g�p��́A���[�N�h�~�̂��߂�free�֐��ŃN���A���邱�ƁB
	//@param [in] _task_id �T���^�X�N��ID
	Task** FindTaskArray(int _task_id);

	//@brief �Y���^�X�N���폜����
	//@param [in] _task_id �폜����^�X�N�̃|�C���^
	void DeleteTask(Task* _task);

	//@brief �S�Ẵ^�X�N���폜����
	void DeleteAllTask();

	//@brief �폜�t���O���m�F���A�폜�t���O���ݒ肳��Ă���^�X�N��S�č폜����
	void CheckDeleteAll();

	//@brief �S�Ẵ^�X�N��BeforeUpdate�֐������s����B
	void BeforeUpdateAll();

	//@brief �S�Ẵ^�X�N��Update�֐������s����B
	void UpdateAll();

	//@brief �S�Ẵ^�X�N��AfterUpdate�֐������s����B
	void AfterUpdateAll();


	//@brief �S�Ẵ^�X�N��BeforeCollisionCheck�֐������s����B
	void BeforeCollisionAll();

	//@brief �S�Ẵ^�X�N�ɑ΂���CollisionCheck�֐������s����B
	void CollisionAll();

	//@brief �S�Ẵ^�X�N�ɑ΂���Draw�֐������s����B
	void DrawAll();

	//@brief �`��D��x�ɉ����ă^�X�N�̏��Ԃ��\�[�g����B
	void Sort();

	//@brief �C���X�^���X���擾����B
	static TaskManager* GetInstance();

	//@brief �C���X�^���X���N���A
	static void ClearInstance();
};

/*
2019/03/07 TaskManager�N���X��`�B��{�@�\�����Bby shingai
2019/03/08 �o�O�C����\�[�g�������N�C�b�N�\�[�g�ɕύX�B by shingai
2019/03/11 BeforeUpdate���ǉ��ɍ��킹���֐��ǉ��B
*/
