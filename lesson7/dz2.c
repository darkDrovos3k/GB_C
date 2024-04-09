#include <stdio.h>
#include <limits.h>

#define SIZE 5


int main(void) {
    int a[SIZE] = {0};
    int min = INT_MAX;

    for (int i = 0; i < SIZE; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }

    for (int i = 0; i < 5; i++) {
        if(a[i] < min) {
            min = a[i];
        }
    }

    printf("%d", min);

    return 0;
}