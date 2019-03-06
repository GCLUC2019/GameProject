#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main(){
	

	float v0, h0, g;
	float h = 0;
	int t;
	v0 = 4.9;
	g = 9.8;
	h0 = 29.4;

	for (int t = 0; t < 6; t++){
		if (h = h0 + v0*t + 0.5* (-g)*t*t){
			cout << t << "•b‚ÌŽž‚Ì‚‚³‚Í" << h << "‚Å‚·"<<"\n";
		}
	}
	


	//getchar();
	system("pause");
	return 0;
}

