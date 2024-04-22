#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dz2.h"


int main(void) {
    char string[SIZE];
    char tmp[SIZE];

    FILE *fp = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson10/dz2/file.txt", "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    FILE *pfile = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson10/dz2/outfile.txt", "a+");

    if (pfile == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fgets(string, SIZE, fp);

    del_space(string, tmp);
    fprintf(pfile, "%s", tmp);

    fclose(pfile);
    fclose(fp);
}

