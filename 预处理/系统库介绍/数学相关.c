//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
    double d = sqrt(3);
    printf("%f\n", d);
    double e = pow(3,2);
    printf("%f\n", e);
    printf("%f\n", tan(M_PI));
    double f = 3.14;
    printf("%f\n", ceil(f));//不小于f的最小整数
    printf("%f\n", floor(f));//不大于f的最大整数
    double g = -3.14;
    printf("%f\n", fabs(g));
    return 0;
}