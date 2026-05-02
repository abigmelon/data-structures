//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
    FILE * file = fopen("hello2.txt","w");
    if (file != NULL) {
        for (int i = 0; i < 10; i++) {
            putc('A' + i, file);
        }
        fclose(file);
    } else {
        printf("失败\n");
    }
    return 0;
}