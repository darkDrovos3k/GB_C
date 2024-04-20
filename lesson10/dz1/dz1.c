#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50


int main(void) {
    char string[SIZE];
    char tmp[SIZE];

    FILE *fp = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson10/dz1/file.txt", "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    FILE *pfile = fopen("/Users/drovos3k/CLionProjects/GB/C/lesson10/dz1/outfile.txt", "a+");

    if (pfile == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fgets(string, SIZE, fp);

    int size_string = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != ' ') {
            size_string++;
        }
    }

    if (size_string % 2 != 0) {
        size_string -= 1;
    }

    int flag = 0;
    for (int i = 0; i <= size_string; i++) {
        if (string[i] == ' ') {
            tmp[i] = string[i];
            tmp[i - 1] = string[i + 1];
            tmp[i + 1] = string[i - 1];
            i += 1;
            if (i % 2 == 0) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        } else if (i % 2 == 0 && flag == 0) {
            tmp[i + 1] = string[i];
        } else if (i % 2 != 0 && flag == 0) {
            tmp[i - 1] = string[i];
        } else if (i % 2 == 0 && flag == 1) {
            tmp[i - 1] = string[i];
        } else if (i % 2 != 0 && flag == 1) {
            tmp[i + 1] = string[i];
        }
    }

    unsigned long res = strlen(string) - size_string;

    if (res == 2) {
        tmp[size_string + 1] = string[strlen(string) - 1];
        tmp[size_string + 2] = '\0';
    }
    else {
        tmp[size_string + 1] = '\0';
    }
}

