//
// Created by 63092 on 2026/4/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char temp[201] = {0};
char mark[51][51] = {0};

int main() {
    fgets(temp, 201, stdin);
    char *p = temp;
    int count = 0;
    while (*p != '\0' && *p != ';') {
        while (*p != ';' && *p != '\0' && !isalpha(*p) && *p != '_') {
            p++;
        }
        if (*p == ';' && *p == '\0') break;
        char temp2[51] = {0};
        int len = 0;
        while (*p != ';' && *p != '\0' && *p != ' ' && len < 50) {
            if (isalpha(*p) || isdigit(*p) || *p == '_') {
                temp2[len++] = *p++;
            } else break;
        }
        temp2[len] = '\0';
        int exist = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(mark[i], temp2) == 0) {
                exist = 1;
                break;
            }
        }
        if (!exist) {
            strcpy(mark[count++], temp2);
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (strcmp(mark[j], mark[j+1]) > 0) {
                char str[100] = {0};
                strcpy(str, mark[j]);
                strcpy(mark[j], mark[j+1]);
                strcpy(mark[j+1], str);
            }
        }
    }
    for (int m = 0; m < count; m++) {
        printf("%s ", mark[m]);
    }
    return 0;
}