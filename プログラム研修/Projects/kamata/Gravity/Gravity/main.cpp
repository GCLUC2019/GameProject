#include<iostream>
using namespace std;

int main(){
	float h=0;
	int t=0;

	for (t = 0; t <= 5; t += 1) {
		h = 29.4 + 4.9*t + 0.5*((-9.8)*(t * 2));
		cout <<t<< "•bŒã‚Í"<<h<<"m" << endl;
	}

	system("pause");
	return 0;
}

