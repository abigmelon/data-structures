//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "hello", * str2 = "world!";
    strcat(str1, str2);//拼接，改的是前面的字符串，需要前面的字符串有足够的长度
    printf("%s\n", str1);
    return 0;
}