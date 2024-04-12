#include <stdio.h>

#define SIZE 100

int is_two_same(int size, int a[]);
void scanf_array(int a[], int size);


int main(void) {
    int a[SIZE] = {0};

    scanf_array(a, SIZE);
    is_two_same(SIZE, a);

    return 0;
}

int is_two_same(int size, int a[]) {
    int count = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int k = 0; k < size - 1; k++) {
            if (a[i] == a[k]) {
                count++;
            }
        }
        if (count >= 2) {
            return printf("YES\n");
        }
        count = 0;
    }
    printf("NO\n");
}

void scanf_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }
}