#include "TaskManagement.h"
TaskManagement* TaskManagement::mp_t_ins = nullptr;

TaskManagement::TaskManagement():
	mp_head(nullptr),
	mp_tail(nullptr)
{
}

TaskManagement::~TaskManagement()
{

}

void TaskManagement::Add(Task * _add)
{
	//もし、先頭になにもなかったら、
	if (mp_head == nullptr) {
		SetHead(_add);
		return;
	}

	Task * now = mp_head;
	//先頭から末尾まで繰り返す
	while (now)
	{
		//追加したいタスクの優先度と、
		//現在ポインタが指すタスクの優先度を比較
		if (_add->m_priority < now->m_priority) {
			InsertTask(_add, now);
			return;
		}

		Task* next = now->mp_next;
		//優先度が低い場合は末尾に追加
		if (next == nullptr) {
			SetTail(_add, now);
			return;
		}
		now = next;
	}


}

void TaskManagement::SetHead(Task* add_t)
{
	//先頭が何もない時、
	if (mp_head == nullptr) {
		mp_tail = add_t;
		add_t->mp_next = nullptr;
	}
	//先頭の次の要素がある時、
	else if (mp_head->mp_next != nullptr) {
		Task*head_next = mp_head->mp_next;
		add_t->mp_next = head_next;
		SetTail(mp_head, mp_tail);
	}
	
	//共通処理
	add_t->mp_prev = nullptr;
	mp_head = add_t;
}

void TaskManagement::SetTail(Task* add_t, Task* now_t)
{
	now_t->mp_next = add_t;
	add_t->mp_prev = now_t;
	mp_tail = add_t;
}

void TaskManagement::InsertTask(Task* add_t, Task* now_t)
{
	//現在指すタスクの前のタスクを一時保存
	Task * befor_p = now_t->mp_prev;

	//一時保存したタスクがmp_headの
	//mp_prevを指していた場合、
	if (befor_p != nullptr)
		//追加したいタスクのポインタを格納
		befor_p->mp_next = add_t;
	now_t->mp_prev = add_t;
	add_t->mp_next = now_t;
	add_t->mp_prev = befor_p;

	//現在指しているポインタが先頭の場合、
	if (now_t == mp_head)
		//今回追加したタスクのポインタを
		//先頭に置き換える
		mp_head = add_t;
}

void TaskManagement::UpdateAll()
{
	Task*now = mp_head;
	while (now) {
		now->Update();
		now = now->mp_next;
	}
}

void TaskManagement::DrawAll()
{
	Task*now = mp_head;
	while (now) {
		now->Draw();
		now = now->mp_next;
	}
}

void TaskManagement::DrawTailAll()
{
	Task*now = mp_tail;
	while (now) {
		now->Draw();
		now = now->mp_prev;
	}
}

void TaskManagement::FlagKill()
{
	Task*now = mp_head;
	while (now)
	{
		//現在のポインタの次のポインタを一時保存
		Task*next = now->mp_next;
		//フラグが立っていたら、現在のポインタを破棄
		if (now->mp_killFlag == true)Kill(now);
		//次のポインタがあれば、現在のポインタにする
		if (next)now = next;
		else return;
	}
}

void TaskManagement::KillFlagAll()
{
	Task*now = mp_head;
	while (now)
	{
		now->SetKill();
		now = now->mp_next;
		printf("成功した\n");
	}
}

void TaskManagement::KillAll()
{
	Task* now = mp_head;
	while (now)
	{
		//現在のポインタの次のポインタを一時保存
		Task*next = now->mp_next;
		Kill(now);
		printf("成功しました\n");
		now = next;
	}
}

void TaskManagement::RemoveTask(Task * rem_p)
{
	Task* before_p = rem_p->mp_prev;
	Task* after_p = rem_p->mp_next;
	//外すタスクの前にポインタがある場合
	if (before_p != nullptr)before_p->mp_next = after_p;
	//同様に次のポインタがある場合、
	if (after_p != nullptr)after_p->mp_prev = before_p;
	//外すタスクの前後を初期化する
	rem_p->mp_prev = nullptr;
	rem_p->mp_next = nullptr;
	//外すタスクが先頭だった場合
	if (rem_p == mp_head)mp_head = before_p;
	//外すタスクが末尾だった場合
	if (rem_p == mp_tail)mp_tail = after_p;
}

void TaskManagement::ChangePrio(Task * change_p, int priority)
{
	RemoveTask(change_p);
	change_p->SetPriority(priority);
	Add(change_p);
}

void TaskManagement::Kill(Task * kill_p)
{
	if (kill_p == nullptr)return;
	Task* bfeore_p = nullptr;
	Task* after_p = nullptr;
	//破棄したいタスクポインタが次のポインタを持っている場合、
	if (kill_p->mp_next != nullptr)after_p = kill_p->mp_next;
	//同様に前のポインタを持っている場合、
	if (kill_p->mp_prev != nullptr)bfeore_p = kill_p->mp_prev;
	//破棄したいポインタが先頭だった場合、
	if (kill_p == mp_head) mp_head = kill_p->mp_next;
	//取得した次のポインタがタスクを指している場合、
	if (after_p != nullptr)after_p->mp_prev = bfeore_p;
	//同様に前のポインタがある場合、
	if (bfeore_p != nullptr)bfeore_p->mp_next = after_p;
	//リストから除外
	RemoveTask(kill_p);
	//削除後に初期化
	delete kill_p;
	kill_p = nullptr;
}

Task * TaskManagement::GetTask(int & id) const
{
	//Idｗｐ持つタスクが存在すれば、そのポインタを返す
	Task*now = mp_head;
	while (now) {
		if (now->GetId() == id)return now;
		now = now->mp_next;
	}

	//それ以外ならヌルポインタを返す
	return nullptr;
}

std::list<Task*> TaskManagement::GetTasks(int & id) const
{
	std::list<Task*> list;
	Task* now = mp_head;
	while (now) {
		//取得したいタスクがあれば、リストに格納する
		if (now->GetId() == id)list.push_back(now->mp_task);;
		now = now->mp_next;
	}

	//そのリストを返す
	return list;

}

int TaskManagement::GetCount(int & id) const
{
	Task* now = mp_head;
	int task_cnt = 0;

	//指定したタスク数を返す
	while (now) {
		if (now->GetId() == id)task_cnt++;
		now = now->mp_next;
	}

	return task_cnt;
}


TaskManagement * TaskManagement::GetIns()
{
	//起動時に一度だけ、
	//TaskManagementクラスを生成しインスタンスに格納
	if (mp_t_ins == nullptr)
		mp_t_ins = new TaskManagement();

	//それを返す
	return mp_t_ins;
}

void TaskManagement::ClearIns()
{
	//メモリリーク回避
	if (mp_t_ins != nullptr)delete mp_t_ins;
	mp_t_ins = nullptr;
}
