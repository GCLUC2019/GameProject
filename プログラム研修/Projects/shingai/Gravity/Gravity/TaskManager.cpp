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
	Sort();
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
			Sort();
			return;
		}

		t = t->GetNextTask();
		if (t == nullptr) break;
	}
}

void TaskManager::UpdateAll()
{
	Task* t = GetHead();
	while (true) {
		t->Update();
		t = t->GetNextTask();
		if (t == nullptr) break;
	}
}

void TaskManager::DrawAll()
{
	Task* t = GetHead();
	while (true) {
		t->Draw();
		t = t->GetNextTask();
		if (t == nullptr) break;
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
		task_array[i] = t;
		task_dp_array[i] = t->GetDrawPriority();
		t = t->GetNextTask();
		i++;
		if (t == nullptr) break;
	}


	//ソート作業する(バブルソート)
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