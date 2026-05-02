//
// Created by 63092 on 2026/3/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct Student {
    int id;
    int age;
    char *name;
};

int main() {
    struct Student arr[] = {{1,18,"xiaoming"},{2, 17, "xiaohong"}, {3, 18, "xiaogang"}};
    struct Student student = {1, 18, "xiaoming"};
    struct Student *p = &student;
    printf("%s", (*p).name);
    printf("%s", p->name);//推荐传递指针而不是值传递
    return 0;
}