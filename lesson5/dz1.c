#include <stdio.h>

long long grains(int cell);


int main(void) {
    int cell;

    scanf("%d", &cell);
    printf("%llu", grains(cell));

    return 0;
}

long long grains(int cell) {
    long long g = 1;

    for (int i = 1; i < cell; i++) {
        g *= 2;
    }

    return g;
}