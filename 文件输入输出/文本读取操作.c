//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
    FILE * file = fopen("hello.txt","r");
    if (file != NULL) {
        int c;
        while ((c = getc(file)) != EOF) {
            putchar(c);
        }
        fclose(file);
    } else {
        printf("失败\n");
    }
    return 0;
}