//放物線シミュレーション
#include <stdio.h>

int main() 
{
	double v = 4.9;
	double h = 29.4;
	double g = 9.8;
	double a = 0;

	for (int i = 0; i < 6; ++i)
	{
		a = h + v * i + (0.5f * -g * (i*i));
		printf("%d秒後 %f m\n", i, a);
	}

	getchar();
	return 0;
}