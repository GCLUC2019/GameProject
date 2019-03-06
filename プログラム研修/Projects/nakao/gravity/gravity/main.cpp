#include <stdio.h>


float Gravity = -9.8;
float spd,spd_0,h,h_0;
int time;


int main() {
	spd_0 = 4.9;
	h_0 = 29.4;
	for (time = 0; time < 5; time++) {
		h = h_0 + spd_0 * time + Gravity * (time*time) / 2;
		printf("%d•bŒã%.5f\n",time,h);	
	}
	
	printf("I—¹");


	getchar();
	return 0;
}