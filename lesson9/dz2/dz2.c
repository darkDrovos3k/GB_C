#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_A_B(char a[], FILE *pfile);

int main(void) {
    char s[50];

    FILE *fp = fopen("file.txt", "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    FILE *pfile = fopen("outfile.txt", "w");

    if (pfile == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fgets(s, 50, fp);
    reverse_A_B(s, pfile);

    fclose(fp);

    return 0;
}

void reverse_A_B(char a[], FILE *pfile) {
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

    fprintf(pfile, "%s", a);
    fclose(pfile);
}

