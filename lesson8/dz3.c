#include <stdio.h>

#define SIZE 84

int find_max_array(int size, int a[]);
void scanf_array(int a[], int size);


int main(void) {
    int a[SIZE] = {0};

    scanf_array(a, SIZE);
    printf("%d\n", find_max_array(SIZE, a));

    return 0;
}

int find_max_array(int size, int a[]) {
    int max = 0;

    for (int i = 0; i < size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    return max;
}

void scanf_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }
}