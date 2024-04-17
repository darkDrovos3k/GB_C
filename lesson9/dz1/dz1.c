#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_word(char array[], int array_size, char a[], char b[]);
void print_symbol(char a[], char b[], FILE *pfile);

struct sym {
    char s;
    char array_s[10];
    int s_count;
};

int main(void) {
    char s[50];
    char word1[10];
    char word2[10];

    FILE *fp = fopen("file.txt", "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    FILE *pfile = fopen("outfile.txt", "a+");

    if (pfile == NULL) {
        printf("Ошибка открытия файла");
        exit(1);
    }

    fgets(s, 50, fp);
    fclose(fp);

    array_word(s, 50, word1, word2);
    print_symbol(word1, word2, pfile);

    return 0;
}

void array_word(char array[], int array_size, char a[], char b[]) {
    int count = 0;

    for (int i = 0; i < array_size; i++) {
        if (array[i] >= 'a' && array[i] <= 'z') {
            a[i] = array[i];
            count++;
        }
        else {
            a[count] = '\0';
            break;
        }
    }

    count++;

    for (int i = 0; count <= strlen(array); i++, count++) {
        if (array[count] >= 'a' && array[count] <= 'z') {
            b[i] = array[count];
        }
        else {
            b[i] = '\0';
            break;
        }
    }
}

void print_symbol(char a[], char b[], FILE *pfile) {
    struct sym symbol = {0, 0, 0};

    for (int i = 0; i < strlen(a); i++) {
        for (int k = 0; k < strlen(b); k++) {
            if (a[i] == b[k] && a[i] != symbol.s) {
                symbol.s = a[i];
                symbol.array_s[symbol.s_count++] = a[i];
                symbol.array_s[symbol.s_count++] = ' ';
            }
            else if (a[i] == b[k] && a[i] == symbol.s) {
                for (int j = 0; j < strlen(symbol.array_s); j++) {
                    if (symbol.array_s[j] == a[i]) {
                        symbol.array_s[j] = 0;
                        symbol.s_count -= 2;
                    }
                }
            }
        }
    }

    fprintf(pfile, "%s", symbol.array_s);
    fclose(pfile);
}