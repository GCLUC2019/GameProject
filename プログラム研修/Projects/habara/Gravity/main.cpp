#include<stdio.h>
#include<iostream>
#include<list>

using namespace std;

class Task{
public:
	Task*mp_next;
public:
	Task();
	virtual void Draw();
};
Task::Task():mp_next(nullptr){
}

void Task::Draw(){
	printf("TaskDraw\n");
}

class TaskManager{
private:
	Task*head;
	static TaskManager*instance;
public:
	TaskManager();
	void DrawAll();
	void Add(Task*t);
	void Delete(Task*t);

};

TaskManager::TaskManager(){

}

class A :public Task{
public:
	void Draw();
};

void A::Draw(){
	printf("ADraw\n");
}


Task*head;

int main(){
	//タスクを１つ生成
	head = new Task();

	//３つのタスクを追加
	for (int i = 0; i < 3; ++i){
		Task*t = new A();
		Task*n = head;
		//末尾のタスクまで進める
		while (n->mp_next){
			n = n->mp_next;
		}
		n->mp_next = t;
		//タスクをつなげる

	}

	//headから最後のタスクのDraw関数を呼び出す
	Task*t = head;
	while (t){
		t->Draw();
		t = t->mp_next;
	}
	system(" pause");
	return 0;
	
}


