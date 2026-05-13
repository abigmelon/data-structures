//
// Created by 63092 on 2026/5/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char input[205] = {0};
int op[205] = {0};

void turnPrint(char* txt, int start, int stop) {
    char tmp;
    int a = start;
    int b = stop;
    while (start < stop) {
        tmp = txt[start];
        txt[start] = txt[stop];
        txt[stop] = tmp;
        start++;
        stop--;
    }
    for (int i = a; i <= b; i++) {
        printf("%c", txt[i]);
    }
}

int main() {
    fgets(input, 205, stdin);
    int len = strlen(input);
    input[len - 1] = '\0';
    int start = 0;
    int stop = 0;
    for (int i = 0; i < len; i++) {
        if (!isalnum(input[i])) {
            op[i] = 0;
        }else if (isalpha(input[i])) {
            op[i] = 1;
        }else if (isdigit(input[i])) {
            op[i] = 2;
        }
    }
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (op[i] == 1) {
            if (flag == 0) {
                start = i;
                stop = i;
                flag = 1;
            }else if (flag == 1) {
                stop++;
            }else if (flag == 2) {
                turnPrint(input, start, stop);
                start = i;
                stop = i;
                flag = 1;
            }
        }
        if (op[i] == 2) {
            if (flag == 0) {
                start = i;
                stop = i;
                flag = 2;
            }else if (flag == 2) {
                stop++;
            }else if (flag == 1) {
                turnPrint(input, start, stop);
                start = i;
                stop = i;
                flag = 2;
            }
        }
        if (op[i] == 0) {
            if (flag == 0) {
                printf("%c", input[i]);
                start = stop = 0;
            }
            if (flag == 1) {
                turnPrint(input, start, stop);
                printf("%c", input[i]);
                flag = 0;
                start = stop = 0;
            }
            if (flag == 2) {
                turnPrint(input, start, stop);
                printf("%c", input[i]);
                flag = 0;
                start = stop = 0;
            }
        }
    }
    return 0;
}