#include <stdio.h>
#include <iostream>


int main() {

	float t = 0;
	/*printf("�v���������b������͂��Ă�������");
	scanf_s("%f", &t);*/

	float P = 29.4 - 4.9 * t * (t - 1);

	/*printf("%f", P);*/

	for (int i = 0; i < 6; ++i) {
		P = 29.4 - 4.9 * i * (i - 1);
		printf("%d�b��%f��\n", i, P);
	}

	//getchar();
	system("pause");
	return 0;
}