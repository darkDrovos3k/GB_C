#include <string.h>
#include "dz2.h"


static int ret_position(char *str) {
    int position;
    for (position = 0; position < strlen(str); position++) {
        if (str[position] == ' ') {
            continue;
        }
        else {
            break;
        }
    }

    return position;
}

void del_space(char *str, char *tmp) {
    int position = ret_position(str);
    int j;

    for (j = 0; position< strlen(str); position++) {
        if (str[position] == ' ' && str[position + 1] != ' ') {
            tmp[j++] = str[position];
        }
        else if (str[position] == ' ' && str[position + 1] == ' ') {
            continue;
        } else {
            tmp[j++] = str[position];
        }
    }
    tmp[j] = '\0';
}