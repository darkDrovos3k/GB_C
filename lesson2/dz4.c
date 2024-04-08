#include <stdio.h>

int main(void) {
    int a, b, c, d, e;
    int f = 0;
    int count = 0;
    float res;

    scanf("%d", &a);

    b = a / 1000;
    c = (a % 1000) / 100;
    d = (a % 100) / 10;
    e = a % 10;
    f = 0;
    count = 0;
    int g[4] = {b, c, d, e};

    for (int i = 0; i <= 3; i++) {
        if (g[i] > 0) {
            f += g[i];
            count++;
        }
    }

    res = (float) f / (float) count;
    printf("%.2f\n", res);

    return 0;
}