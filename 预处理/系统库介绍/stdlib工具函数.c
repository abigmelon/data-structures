//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int cmp(const void* a, const void* b) {
    int *x = (int*)a;//转换为可以使用的int
    int *y = (int*)b;
    return *x - *y;//a比b大返回正数，从小到大
}

int cmp2(const void* a, const void* b) {
    int *x = (int*)a;//转换为可以使用的int
    int *y = (int*)b;
    return *y - *x;//a比b小返回正数，从大到小
}

int main() {
    int arr[] = {5, 6, 8, 3, 2, 1, 4, 9, 7, 0};
    //参数：待排序数组，待排序数量，元素大小，排序规则（提供函数实现）
    qsort(arr, 10, sizeof(int), cmp);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    qsort(arr, 10, sizeof(int), cmp2);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}