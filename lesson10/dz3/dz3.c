#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50


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

    unsigned long size = strlen(string) - 1;

    for (int i = 0; 0 < size; size--) {
        if (string[size] != '/') {
            tmp[i++] = string[size];
        }
        else if (string[size] == '/') {
            size += 1;
            tmp[i] = '\0';
            break;
        }
    }

    char *res = malloc((size + 5) * sizeof(char));
    memcpy(res, string, size);

    for (int i = 0; i < strlen(tmp); i++) {
        *(res + size++) = tmp[i];
    }

    strcat(res, ".html");

    puts(res);
    free(res);

    fclose(pfile);
    fclose(fp);
}

