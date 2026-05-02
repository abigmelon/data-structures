//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int * p = (int *) malloc(sizeof(int));//申请一段空间
    *p = 128;
    printf("%d", *p);
    free(p);
    p = NULL;
}