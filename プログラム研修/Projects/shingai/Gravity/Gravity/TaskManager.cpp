#include "TaskManager.h"
#include "stdio.h"
#include "stdlib.h"
#include "Task.h"

static TaskManager* s_instance_p = nullptr;

void TaskManager::AddTask(Task * _task)
{
	m_task_num++;

	if (m_head_task == nullptr) {
		m_head_task = _task;
		return;
	}

	Task* t = m_head_task;
	while (true) {
		if (t->GetNextTask() != nullptr) {
			t = t->GetNextTask();
		}
		else {
			t->SetNextTask(_task);
			_task->SetBeforeTask(t);
			break;
		}
	}
	//Sort();
}

Task * TaskManager::FindTask(int _task_id)
{
	Task* t = GetHead();
	while (true) {
		if (t->GetTaskId() == _task_id) return t;
		t = t->GetNextTask();
		if (t == nullptr) break;
	}
	return nullptr;
}

Task** TaskManager::FindTaskArray(int _task_id)
{
	int task_num = 0;
	
	//該当タスクの個数を調べる
	Task* t = GetHead();
	if (t == nullptr) return nullptr;

	while (true) {
		if (t->GetTaskId() == _task_id) task_num++;
		t = t->GetNextTask();
		if (t == nullptr) break;
	}

	//配列作成
	Task** task_array = (Task**)calloc(task_num + 1,sizeof(Task*));

	//該当タスクを配列に格納
	task_num = 0;
	t = GetHead();
	while (true) {
		if (t->GetTaskId() == _task_id) {
			task_array[task_num++] = t;
		}

		t = t->GetNextTask();
		if (t == nullptr) break;
	}

	//末尾は必ずnullptr(番兵)
	task_array[task_num] = nullptr;

	return task_array;
}

void TaskManager::DeleteTask(Task * _task)
{
	if (m_head_task == _task) {
		Task* head_next = m_head_task->GetNextTask();
		m_head_task = head_next;
		if (head_next != nullptr) head_next->SetBeforeTask(nullptr);
		delete _task;
		m_task_num--;
		return;
	}

	Task* t = m_head_task->GetNextTask();

	while (true) {
		if (t == _task) {
			Task* next = t->GetNextTask();
			Task* before = t->GetBeforeTask();


			if (before != nullptr) {
				before->SetNextTask(next);
				if (next != nullptr) next->SetBeforeTask(before);
			}


			delete _task;
			m_task_num--;
			//Sort();
			return;
		}

		t = t->GetNextTask();
		if (t == nullptr) break;
	}
}

void TaskManager::DeleteAllTask()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//UpdateでDeleteが実行されても大丈夫なように
		t->Delete();
		t = t_next;
	}
}

void TaskManager::CheckDeleteAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//UpdateでDeleteが実行されても大丈夫なように
		if(t->GetIsDelete() == true) t->Delete();
		t = t_next;
	}
}

void TaskManager::UpdateAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//UpdateでDeleteが実行されても大丈夫なように
		t->Update();
		t = t_next;
	}
}

void TaskManager::CollisionAll()
{
	Task* t = GetHead();

	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//CollisionCheckでDeleteが実行されても大丈夫なように
		Task* t_c = GetHead();
		while (true) {
			if (t_c == nullptr) break;
			Task* t_c_next = t_c->GetNextTask();//CollisionCheckでDeleteが実行されても大丈夫なように
			//同じインスタンス同士なら順番を飛ばす
			if (t == t_c) {
				t_c = t_c_next;
				if (t_c == nullptr) break;
				continue;
			}

			t->CollisionCheck(t_c);
			t_c = t_c_next;
		}
		t = t_next;
	}
	
}

void TaskManager::DrawAll()
{
	Task* t = GetHead();
	while (true) {
		if (t == nullptr) break;
		Task* t_next = t->GetNextTask();//DrawでDeleteが実行されても大丈夫なように
		t->Draw();
		t = t_next;
	}
}


//タスクを描画優先度に合わせてソートする。
//新規タスク追加時 タスク削除時に呼ばれる。

//Zソートとしても使えるソート
//描画順番は後の方が優先度が高い(前に表示される)ので値が大きい程順番を後にする。
//なので昇順ソート

void TaskManager::Sort()
{
	//配列を作成(callocで領域確保)

	//Taskポインタ型配列(配列を表す為にTaskポインタ型ポインタを利用する)
	Task** task_array = (Task**)calloc(m_task_num, sizeof(Task*));


	//int型配列
	int* task_dp_array = (int*)calloc(m_task_num, sizeof(int));


	//あとはソートしていくだけ

	//とりあえずソート用の情報を集める
	Task* t = GetHead();


	//ここで宣言してるので取り扱い注意
	int i = 0;
	while (true) {
		if (t == nullptr) break;
		task_array[i] = t;
		task_dp_array[i] = t->GetDrawPriority();
		t = t->GetNextTask();
		i++;
	}

	//ソート作業する(バブルソート)
	/*
	for (int i = 0; i < m_task_num; i++) {
		for (int k = 0; k < m_task_num; k++) {
			if (task_dp_array[i] < task_dp_array[k]) {

				//描画順番配列の入れ替え
				int work = task_dp_array[i];
				task_dp_array[i] = task_dp_array[k];
				task_dp_array[k] = work;

				//ポインタの入れ替え
				Task* work_task_p = task_array[i];
				task_array[i] = task_array[k];
				task_array[k] = work_task_p;

			}
		}
	}
	*/


	printf("m_task_num %d\n", m_task_num);

	//ソート作業する(クイックソート)
	QuickSort(task_array,task_dp_array,m_task_num);


	
	//タスクリストを再構成
	m_head_task = task_array[0];
	m_head_task->SetBeforeTask(nullptr);


	Task* tp;
	for (int i = 0; i < m_task_num; i++) {
		tp = task_array[i];
		if (i == m_task_num - 1) {
			tp->SetNextTask(nullptr);
		}
		else {
			tp->SetNextTask(task_array[i + 1]);
			task_array[i + 1]->SetBeforeTask(tp);
		}

		
	}


	//とりあえず取得したデータを確認
	//callocで取得した領域を解放
	free(task_array);
	free(task_dp_array);
}

void TaskManager::QuickSort(Task ** _task_array, int * _task_dp_array, int _task_num)
{
	printf("QuickSort呼ばれた\n");
	
	int base_ad = _task_num / 2;

	while (true) {
		bool is_last_left = false;
		bool is_last_right = false;



		//右と左で別々か

		int left_ad = 0;
		
		while (true) {
			if (_task_dp_array[left_ad] > _task_dp_array[base_ad]) {
				break;
			}

			left_ad++;

			if (left_ad >= base_ad) {
				left_ad = base_ad;
				//printf("左ソート完了\n");
				is_last_left = true;
				break;
			}
		}

		int right_ad = _task_num - 1;
		while (true) {
			if (_task_dp_array[right_ad] < _task_dp_array[base_ad]) {
				break;
			}

			right_ad--;

			if (right_ad <= base_ad) {
				right_ad = base_ad;
				//printf("右ソート完了\n");
				is_last_right = true;
				break;
			}
		}

		//bool is_end = false;
		//printf("右%d 左%d\n", _task_dp_array[left_ad], _task_dp_array[right_ad]);
		//if (_task_dp_array[left_ad] == _task_dp_array[right_ad] && (is_last_right == true || is_last_left == true)) is_end = true;


		//もし衝突した場合
		if (is_last_left == true && is_last_right == true){
			//printf("ソート完了\n");
			//base_adを変えて再帰処理かぁ
			int left_task_num = _task_num / 2;
			int right_task_num = _task_num - left_task_num;
			//printf("クイックソート再帰呼び出し\n");
			if(left_task_num > 1) QuickSort(_task_array, _task_dp_array, left_task_num);
			if(right_task_num > 1) QuickSort(_task_array + left_task_num, _task_dp_array + left_task_num, right_task_num);
			break;
		}


		//printf("入れ替え\n");
		//入れ替え
		int work = _task_dp_array[left_ad];
		_task_dp_array[left_ad] = _task_dp_array[right_ad];
		_task_dp_array[right_ad] = work;

		Task* work_task_p = _task_array[left_ad];
		_task_array[left_ad] = _task_array[right_ad];
		_task_array[right_ad] = work_task_p;
	}
}

TaskManager * TaskManager::GetInstance()
{
	if (s_instance_p == nullptr) s_instance_p = new TaskManager();
	return s_instance_p;
}

void TaskManager::ClearInstance()
{
	if (s_instance_p == nullptr) return;
	delete s_instance_p;
	s_instance_p = nullptr;
}