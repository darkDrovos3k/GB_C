#include <stdio.h>

#define SIZE 10

void change_max_min(int size, int a[]);
void print_array(int a[], int size);
void scanf_array(int a[], int size);


int main(void) {
    int a[SIZE] = {0};

    scanf_array(a, SIZE);
    change_max_min(SIZE, a);

    return 0;
}

void change_max_min(int size, int a[]) {

    for (int i = 0; i < size ; i++) {
        for (int k = 0; k < size; k++) {
            if (a[i] > a[k]) {
                int tmp = a[i];
                a[i] = a[k];
                a[k] = tmp;
            }
        }
    }

    print_array(a, size);
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