#include <stdio.h>


int main(void) {
    int n, temp;
    int rev = 0;

    scanf("%d", &n);
    while (n != 0) {
        temp = n % 10;
        rev = rev * 10 + temp;
        n /= 10;
    }

    printf("%d\n", rev);

    return 0;
}