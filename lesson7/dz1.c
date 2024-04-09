#include <stdio.h>
#define SIZE 5


int main(void) {
    int a[SIZE] = {0};
    int sum = 0;

    for (int i = 0; i < SIZE; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }

    for (int i = 0; i < 5; i++) {
        sum += a[i];
    }

    printf("%.3f", sum/(float) SIZE);

    return 0;
}