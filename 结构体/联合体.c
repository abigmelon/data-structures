//
// Created by 63092 on 2026/3/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

union Object {
    int a;
    char b;
    float c;
};

int main() {
    union Object o;
    o.a = 1;
    printf("%d\n", o.b);
    printf("%llu\n", sizeof(union Object));
    return 0;
}