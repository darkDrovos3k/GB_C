#include <stdio.h>

#define SIZE 12


int main(void) {
    int a[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }

    for (int k = 0; k < 4; k++) {
        int tmp = a[SIZE - 1];
        for (int i = SIZE - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = tmp;
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}