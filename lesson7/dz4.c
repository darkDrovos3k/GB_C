#include <stdio.h>

#define SIZE 10


int main(void) {
    int a[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int k = i; k < SIZE - 1; k++) {
            if (a[i] % 10 >= a[k] % 10) {
                int tmp = a[i];
                a[i] = a[k];
                a[k] = tmp;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}