//
// Created by 63092 on 2026/4/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char str[55] = {0};
char ans[55] = {0};
int exist[25] = {0};

int main() {
    char c;
    int i = 0;
    while (scanf("%c", &c) != EOF) {
        str[i++] = c;
        if (c == '\n') break;
    }
    int count = 0;
    for (int j = 0; j < strlen(str); j++) {
        if (str[j] >= 'a' && str[j] <= 'z' && exist[str[j] - 'a'] == 0) {
            ans[count++] = str[j];
            exist[str[j] - 'a'] = 1;
        } else if (str[j] >= 'A' && str[j] <= 'Z' && exist[str[j] - 'A'] == 0) {
            ans[count++] = str[j] - 'A' + 'a';
            exist[str[j] - 'A'] = 1;
        }
    }
    printf("abcdefghijklmnopqrstuvwxyz\n");
    for (int j = 0; j < count; j++) {
        printf("%c", ans[j]);
    }
    for (int j = 25; j >= 0; j++) {
        if (exist[j] == 0) {
            printf("%c", 'a' + j);
        }
    }
    return 0;
}