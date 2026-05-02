//
// Created by 63092 on 2026/3/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct student {
    int id;
    int age;
    char * name;
};//也可以在局部存在

int main() {
    struct student stu1 = {1, 18, "xiaoming"};
    int a = stu1.age;
    stu1.age = 17;
    printf("stu1.age = %d\n", a);
    return 0;
}