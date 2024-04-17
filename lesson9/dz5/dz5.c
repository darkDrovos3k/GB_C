#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void max_string_word(char a[], FILE *pfile);


int main(void) {
    char s[50];

    FILE *fp = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson9/dz5/file.txt", "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    FILE *pfile = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson9/dz5/outfile.txt", "w");

    if (pfile == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fgets(s, 50, fp);
    max_string_word(s, pfile);
    fclose(fp);

    return 0;
}

void max_string_word(char a[], FILE *pfile) {
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