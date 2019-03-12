#include<stdio.h>
#include<iostream>
#include<list>
#include"C_Task.h"
#include"CTaskManager.h"
using namespace std;

class A :public CTask{
public:
	void Draw();
};

void A::Draw(){
	printf("ADraw\n");
}

CTask*head;

int main(){
	getchar();


	/*float v = 0;
	float v0 = 4.9;
	float g = 9.8;
	float h = 0;
	float h0 = 29.4;
	int t = 0;

	for (t = 0; t < 6; t++)
	{
		if (h = h0 + v0*t + 0.5*(-g) + t * 2);
		{
			cout << t; " •bŒã "; h0; "\n";


		}
		
	}*/

	TaskManager m;
	m.Add(new CTask());
	head = new CTask();

	for (int i = 0; i < 3; ++i){
		m.Add(new A());
		CTask*t = new A();
		CTask*n = head;
	

	while (n->mpnext)
	{
		n = n->mpnext;
	}
	n->mpnext = t;
}
	
	system("pause");

return 0;
}

