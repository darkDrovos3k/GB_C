#include <stdio.h>
#include <limits.h>

int main(void) {
    int a, b, c, d, e;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int array[5] = {a, b, c, d, e};
    int min = INT_MAX;
    for (int i = 0; i < 5; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    printf("%d", min);

    return 0;
}