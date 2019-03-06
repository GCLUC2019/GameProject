#include <stdio.h>

/*
実践問題
5秒間放物線のシミュレーションを行う
初速度 4.9m/s
初期高さ 29.4m
重力 9.8m/s


*/

int main() {

	double g = (-9.8);
	double v0 = 4.9;//初速度
	double h0 = 29.4;


	int t = 5;//秒数

	//高さを求めるかな

	
	
	for (int i = 0; i <= t; i++) {
		double h = h0 + v0 * i + (g / 2.0) *(i*i);
		printf("%d秒後%lfm\n", i,h);
	}
	

	getchar();
	getchar();
	return 0;
};