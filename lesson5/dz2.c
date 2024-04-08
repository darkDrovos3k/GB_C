#include <stdio.h>

int nod(int a, int b);


int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d\n", nod(a, b));

    return 0;
}

int nod(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return a + b;

}