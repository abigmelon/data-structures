//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

#ifdef PI
#define M 3.14159
#else
#define M 2.71828
#endif

int main () {
    printf("%lf", M);
    return 0;
}