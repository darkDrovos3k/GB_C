#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void max_word_string(char a[], FILE *pfile);


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
    max_word_string(s, pfile);
    fclose(fp);

    return 0;
}

void max_word_string(char a[], FILE *pfile) {
    int count_tmp = 0;
    char s_array[50];
    unsigned long size = strlen(a);
    char tmp[size];

    for (int i = 0; i <= size; i++) {
        if (a[i] != ' ' && a[i] != '\0') {
            tmp[count_tmp++] = a[i];
        }
        else {
            tmp[count_tmp] = '\0';
            if (strlen(tmp) > strlen(s_array)) {
                s_array[0] = '\0';
                memcpy(s_array, tmp, strlen(tmp));
                s_array[count_tmp] = '\0';
                tmp[0] = '\0';
                count_tmp = 0;
            }
        }
    }

    fprintf(pfile, "%s", s_array);
    fclose(pfile);
}