#include <stdio.h>

int main(void) {
    int a, b, c, d, e;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int array[5] = {a, b, c, d, e};
    int max = 0;
    for (int i = 0; i < 5; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    printf("%d", max);

    return 0;
}