//#include<stdio.h>
#include<iostream>

using namespace std;

int V0 = 4.9;
int H0 = 29.4;
int Gravity = 9.8;
int H;
int t;

int main(){
	string input;
	//getchar();

	for (int t = 0; t < 6; t++){
		H = H0 + V0*t + (1/2) * (-Gravity)*t*t; {
			cout << H << "\n";
		}
	}

	system("pause");
	return 0;
}