#include <stdio.h>

#define SIZE 10


int main(void) {
    int a[SIZE] = {0};
    int b[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        int tmp = a[i] /10 % 10;
        if (tmp == 0 && a[i] >= 100) {
            b[i] = a[i];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (b[i] != 0) {
            printf("%d ", b[i]);
        }
    }

    return 0;
}