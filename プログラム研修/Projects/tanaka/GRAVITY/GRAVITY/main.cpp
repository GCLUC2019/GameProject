#include <stdio.h>
#define GRAVITY -9.8f
int main() {
    double V0 = 4.9f;
    double h0 = 29.4f;
    for (int i = 0; i < 6; ++i) {
        double h = h0 + V0 * i + (GRAVITY*i*i)/2;
        printf("%d •bŒã %f m\n", i, h);
}
    getchar();
    return 0;
}