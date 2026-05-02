//
// Created by 63092 on 2026/3/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


struct object {
    int a;
    short b;
    char c;
};
int main() {
    printf("%llu", sizeof(struct  object));
}