#include <stdio.h>


int main(void) {
    int n;

    scanf("%d", &n);
    n /= 100;

    if (n >= 1 && n <= 9){
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}