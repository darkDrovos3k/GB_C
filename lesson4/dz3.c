#include <stdio.h>


int main(void) {
    int n;

    scanf("%d", &n);
    while (n > 0) {
        if((n % 10) % 2){
            printf("NO\n");
            return 0;
        }
        n /= 10;
    }
    printf("YES\n");
    return 0;
}