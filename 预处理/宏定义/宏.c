//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>

#define PI 3.14159//纯文本替换
#define MUL(x) x * x
//#undef  PI//取消定义

int main () {
    printf("%.5f\n", PI);
    printf("%d\n", MUL(10));
    printf("%s\n", __TIME__);//当前时间
    return 0;
}