#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remove_repeat_symbol(char a[], FILE *pfile);

struct sym {
    char s_array[50];
    int s_count;
    int s_array_count;
};


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
    remove_repeat_symbol(s, pfile);

    fclose(fp);
    fclose(pfile);

    return 0;
}

void remove_repeat_symbol(char a[], FILE *pfile) {
    unsigned long size = strlen(a);
    struct sym symbol = {0, 0, 0};

    for (int i = 0; i < size; i++) {
        symbol.s_count = 0;

        if (a[i] == ' ') {
            continue;
        }

        for (int k = 0; k <= strlen(symbol.s_array); k++) {
            if (a[i] != symbol.s_array[k]) {
                symbol.s_count++;
            }
        }

        if (symbol.s_count == symbol.s_array_count + 1 || symbol.s_array_count == 0) {
            symbol.s_array[symbol.s_array_count++] = a[i];
        }
    }

    fprintf(pfile, "%s", symbol.s_array);
    fclose(pfile);
}