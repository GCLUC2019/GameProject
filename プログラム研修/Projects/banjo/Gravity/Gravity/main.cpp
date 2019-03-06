#include <stdio.h>
#include <iostream>



int main() {
	float v0 = 4.9;
	float h0 = 29.4;
	float g = 9.8;
	float h = 0;
	
	for (int t = 0; t < 6; ++t) {
		h = h0 + v0 * t + (-g / 2 * (t*t));
		printf("%d•bŒã%fm\n",t, h);
	}

	


	getchar();
	return 0;

}