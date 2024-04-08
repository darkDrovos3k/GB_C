#include <stdio.h>

int sum_mul(int n);

int main(void) {
    int n;

    scanf("%d", &n);

    if (sum_mul(n)) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}


int sum_mul(int n) {
    int a, b, c, sum, mul;

    a = n / 100;
    b = (n % 100) / 10;
    c = n % 10;

    sum = a + b + c;
    mul = a * b * c;

    return (sum == mul);
}