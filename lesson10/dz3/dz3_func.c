#include <string.h>
#include <stdlib.h>
#include "dz3.h"


void replace_exp(char str[], char tmp[], FILE *pfile) {
    unsigned long size = strlen(str) - 1;

    for (int i = 0; 0 < size; size--) {
        if (str[size] == '.') {
            tmp[0] = '\0';
            break;
        }

        if (str[size] != '/') {
            tmp[i++] = str[size];
        } else if (str[size] == '/') {
            size += 1;
            tmp[i] = '\0';
            break;
        }
    }

    char *res = malloc((size + 5) * sizeof(char));
    memcpy(res, str, size);

    for (int i = 0; i < strlen(tmp); i++) {
        *(res + size++) = tmp[i];
    }

    strcat(res, ".html");
    fprintf(pfile, "%s", res);

    free(res);
    fclose(pfile);
}