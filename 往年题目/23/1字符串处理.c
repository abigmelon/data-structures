//
// Created by 63092 on 2026/4/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char input[101] = {0};
int mark[101] = {0};
int process[101] = {0};

int main() {
    char c;
    int i = 0;
    while (scanf("%c", &c) != EOF && c != '\n') {
        input[i++] = c;
    }
    for (int j = 0; j < strlen(input); j++) {
        mark[j] = input[j] - j;
    }
    for (int j = 0; j < strlen(input); j++) {
        if (j + 2 < strlen(input) && mark[j] == mark[j+1] && mark[j+1] == mark[j+2]) {
            process[j] = 1;
            process[j+1] = 1;
            process[j+2] = 1;
        }
    }
    _Bool mode = 0;
    for (int j = 0; j < strlen(input); j++) {
        if (mode == 0 && process[j] == 0) {
            printf("%c", input[j]);
        } else if (mode == 0 && process[j] == 1) {
            mode = 1;
            printf("%c", input[j]);
        } else if (mode == 1 && process[j] == 1) {
            continue;
        } else if (mode == 1 && process[j] == 0) {
            printf("-%c%c", input[j - 1], input[j]);
            mode = 0;
        }
    }
    if (mode == 1) {
        printf("-%c", input[strlen(input) - 1]);
    }
    return 0;
}