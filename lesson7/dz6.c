#include <stdio.h>

#define SIZE 10

struct num {
    int count;
    int number;
};


int main(void) {
    int a[SIZE] = {0};
    struct num n = {0, 0};

    for (int i = 0; i < SIZE; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }

    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int k = i; k < SIZE; k++) {
            if (a[i] == a[k]) {
                count++;
            }
        }
        if (count > n.count) {
            n.count = count;
            n.number = a[i];
        }
        count = 0;
    }

    printf("%d\n", n.number);

    return 0;
}