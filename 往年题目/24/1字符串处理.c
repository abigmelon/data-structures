//
// Created by 63092 on 2026/4/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char book[101][40] = {0};
char ans[101][40] = {0};

int check(char *s) {
    for (int i = 0; ans[i][0]; i++) {
        if (strcmp(ans[i], s) == 0) return 1;
    }
    return 0;
}

int main() {
    int copy = 0;
    int num = 0;
    char ch;
    while (scanf("%c", &ch) != EOF) {
        if (ch == '\n') break;

        if (ch == '(') {
            copy = 1;
        }
        else if (ch == ')') {
            copy = 0;
            num++;
        }
        else if (copy && ch != ',') {
            strncat(book[num], &ch, 1);
        }
    }

    int i, cnt = 0;
    for (i = 0; i < num; i++) {
        if (check(book[i]) == 0) {
            strcpy(ans[cnt++], book[i]);
        }
    }

    for (i = 0; i < cnt; i++) {
        printf("%s\n", ans[i]);
    }
    return 0;
}