#include <stdio.h>

void num(int n);


int main(void) {
    int n;
    scanf("%d", &n);
    num(n);
    return 0;
}

void num(int n) {
    if (n >= 10)
        num(n / 10);
    printf("%d ", n % 10);
}