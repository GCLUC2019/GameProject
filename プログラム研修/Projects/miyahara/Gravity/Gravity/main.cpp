#include <stdio.h>
#include <iostream>
//#include <string>
#include <list>
#include "Task.h"
#include "TaskManager.h"


//Task* head;

using namespace std;

int main(){
	//float v0, h0, g;
	//int h;
	//v0 = 4.9;
	//h0 = 29.4;
	//g = 9.8;
	//
	//for (int i = 0; i < 4; i++){
	//	if (h = h0 + v0 * i + 0.5 * (-g) *i*i);
	//	cout << i <<"秒後の高さは" << h << "\n";
	//}
	//タスクを1つ生成
	head = new Task();

	//3つのタスクを追加
	for (int i = 0;i < 3; ++i){
		Task *t = new A();
		Task *n = head;
		//タスクをつなげる
		while (n->mp_next){
			n = n->mp_next;
		}
		n->mp_next = t;
	}

	//headから最後のタスクのDraw関数を呼び出す
	Task *t = head;
	while (t){
		t->Draw();
		t = t->mp_next;
	}

	system("pause");
	return 0;
}