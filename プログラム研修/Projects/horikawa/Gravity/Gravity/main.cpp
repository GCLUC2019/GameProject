#include <stdio.h>
#include <iostream>


int main() {

	float t = 0;
	/*printf("計測したい秒数を入力してください");
	scanf_s("%f", &t);*/

	float P = 29.4 - 4.9 * t * (t - 1);

	/*printf("%f", P);*/

	for (int i = 0; i < 6; ++i) {
		P = 29.4 - 4.9 * i * (i - 1);
		printf("%d秒後%fｍ\n", i, P);
	}

	//getchar();
	system("pause");
	return 0;
}