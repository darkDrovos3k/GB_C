#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_A_B(char a[]);

int main(void) {
    char s[50];

    FILE *fp = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson9/dz2/file.txt", "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fgets(s, 50, fp);
    fclose(fp);
    reverse_A_B(s);

    return 0;
}

void reverse_A_B(char a[]) {
    for(int i = 0; i < strlen(a); i++) {
        if (a[i] == 'a') {
            a[i] = 'b';
        }
        else if (a[i] == 'A') {
            a[i] = 'B';
        }
        else if (a[i] == 'b') {
            a[i] = 'a';
        }
        else if (a[i] == 'B') {
            a[i] = 'A';
        }
    }

    puts(a);
}

