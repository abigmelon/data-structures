//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str[10], *c = "hello";
    strcpy(str, c);//把后面的字符串拷贝到前面的字符串数组中（前面要装的下）
    printf("%s\n", str);
    return 0;
}