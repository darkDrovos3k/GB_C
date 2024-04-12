#include <stdio.h>

#define SIZE 20

void sort_even_odd(int size, int a[]);
void print_array(int a[], int size);
void scanf_array(int a[], int size);


int main(void) {
    int a[SIZE] = {0};

    scanf_array(a, SIZE);
    sort_even_odd(SIZE, a);

    return 0;
}

void sort_even_odd(int size, int a[]) {
    int b[SIZE] = {0};
    int c[SIZE] = {0};
    int res[SIZE] = {0};

    int count_b = 0;
    int count_c = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 == 0) {
            b[count_b++] = a[i];
        }
        else {
            c[count_c++] = a[i];
        }
    }

    for (int i = 0 ; i < count_b; i++) {
        res[i] = b[i];
    }

    for (int i = 0 ; count_b < size; i++) {
        res[count_b++] = c[i];
    }

    print_array(res, SIZE);
}

void print_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}

void scanf_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }
}