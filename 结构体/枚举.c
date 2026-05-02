//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

enum status {low = 1, middle = 2, high = 3};//如果不给初始值的话，默认为0 1 2 ……

int main() {
    enum status status = middle;
    printf("%d", status);
    return 0;
}