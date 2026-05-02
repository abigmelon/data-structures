//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <string.h>

int main() {
    char * a = "aaa", * b = "bbb";
    int value = strcmp(a,b);//比较两个字符串并返回结果 逐字符比较，返回不匹配的两个字母的ASCII码之差
    printf("value is %d\n", value);
    return 0;
}