#include <ctype.h>
#include "dz3.h"


int main(void) {
    char string[SIZE];
    char tmp[SIZE];

    FILE *fp = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson10/dz3/file.txt", "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    FILE *pfile = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson10/dz3/outfile.txt", "w");

    if (pfile == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fgets(string, SIZE, fp);
    replace_exp(string, tmp, pfile);

    fclose(fp);

    return 0;
}

