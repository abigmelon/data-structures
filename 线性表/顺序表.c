//
// Created by 63092 on 2026/3/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef int E;

struct list {
    E * array;//指向顺序表的底层数组
    int capacity;//数组的容量
    int size;//表中的元素数量
};

typedef struct list * Arraylist;

_Bool initlist(Arraylist list) {
    list->array = malloc(sizeof(E) * 10);
    if (list->array == NULL) return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}//初始化

_Bool insertlist(Arraylist list, E element, int index) {
    if (index < 1 || index > list->size + 1) return 0;//检查插入的位置是否合理

    if (list->size == list->capacity) {
        int new_capacity = list->capacity * 2;
        E * newarray = realloc(list->array, sizeof(E) * new_capacity);
        if (newarray == NULL) return 0;
        list->array = newarray;
        list->capacity = new_capacity;
    }//扩容

    for (int i = list->size; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;
    return 1;
}//插入元素

_Bool deletelist(Arraylist list, int index) {
    if (index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return 1;
}//删除元素

int size(Arraylist list) {
    return list->size;
}//获取大小

E * getlist(Arraylist list, int index) {
    if (index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}//获取元素

int findlist(Arraylist list, E element) {
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) return i + 1;
    }
    return -1;
}//查找元素

void printlist(Arraylist list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}//打印list

int main() {
    struct list list;
    if (initlist(&list)) {
        for (int i = 0; i < 30; ++i) {
            insertlist(&list, i*10, i+1);
        }
        deletelist(&list, 10);
        deletelist(&list, 10);
        printlist(&list);
        printf("%d ", *getlist(&list, 3));
        printf("%d ", list.capacity);
        printf("%d ", findlist(&list, 30));
    } else {
        printf("失败");
    }
    return 0;
}