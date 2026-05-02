//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>
int main () {
    FILE *file = fopen("file3.txt", "r");
    if (file == NULL) printf("Error  opening file3.txt");
    else {
        fseek(file, 0, SEEK_SET);//SET从头CUR当前END末尾
        printf("&d", ftell(file));//当前读取到哪个位置
        putchar(getc(file));
        fclose(file);
    }
}   