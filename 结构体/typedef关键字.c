//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct stu {
    int id;
    int age;
    char name[20];
}student;//直接使用别名

int main() {
    student st = {1, 18, "xiaoming"};
}