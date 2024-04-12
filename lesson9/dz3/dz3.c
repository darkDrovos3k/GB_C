#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void array_find_number(char a[], FILE *pfile);
int compare(const void *a, const void *b);


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
    fclose(fp);
    array_find_number(s, pfile);

    return 0;
}

void array_find_number(char a[], FILE *pfile) {
    char numb[4];
    int num[10];
    int count_num = 0;
    int count_numb = 0;

    for (int i = 0; i < 50; i++) {
        while (a[i] >= '0' && a[i] <= '9' && a[i] != ' ') {
            numb[count_numb++] = a[i];
            i++;
        }
        numb[count_numb++] = '\0';
        if (numb[0] != '\0') {
            num[count_num++] = atoi(numb);
        }
        numb[0] = '\0';
        count_numb = 0;
    }

    qsort(num, count_num, sizeof(int), compare);
    for (int i = 0; i < count_num; i++) {
        fprintf(pfile, "%d ", num[i]);
    }

    fclose(pfile);
}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

