#include "stdio.h"

int main() {
	double v, v0;
	double g, t;
	double h, h0;
	
	v0 = 4.9;
	h0 = 29.4;
	g = 9.8;

	for (int i = 0; i < 6; i++) {
		t = i;
		h = h0+(v0*t) - (0.5*g * t*t);
		printf("%d�b��F%f���[�g���̍����ɂȂ�܂�\n", i, h);
	}
	


	getchar();
	return 0;
}