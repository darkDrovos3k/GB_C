#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count_word_last_symbol(char a[], char symbol, FILE *pfile);


int main(void) {
    char s[50];
    char symbol = 'a';

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
    count_word_last_symbol(s, symbol, pfile);
    fclose(fp);

    return 0;
}

void count_word_last_symbol(char a[], char symbol, FILE *pfile) {
    int count = 0;
    unsigned long size = strlen(a);

    for (int i = 0; i <= size; i++) {
        if ((a[i] == ' ' && a[i - 1] == symbol) || (a[i] == '\0' && a[i - 1] == symbol)) {
            count++;
        }
    }

    fprintf(pfile, "%d", count);
    fclose(pfile);
}