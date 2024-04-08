#include <stdio.h>

#define SIZE 12


int main(void) {
    int a[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }

    for (int i = 0, j = 8; i <= 4 && j <= 11; i++, j++) {
        int b = a[i];
        int c = a[j];
        a[i] = c;
        a[j] = b;
    }

    for (int i = 0; i < 12; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}