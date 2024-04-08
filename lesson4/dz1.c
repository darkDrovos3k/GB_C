#include <stdio.h>


int main(void) {
    int a, b;
    int sum = 0;

    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        int qud = i * i;
        sum += qud;
    }

    printf("%d", sum);

    return 0;
}