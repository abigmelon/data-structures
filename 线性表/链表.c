//
// Created by 63092 on 2026/3/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode *next;
};

typedef struct ListNode * Node;

void initList(Node node) {
    node->next = NULL;
}

_Bool insertList(Node head, E element, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;//头节点往前移
        if (head == NULL) return 0;
    }//限定左边界和右边界

    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;

    return 1;
}

_Bool deleteList(Node head, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    if (head->next == NULL) return 0;

    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return 1;
}

E *getList(Node head, int index) {
    if (index < 1) return NULL;
    do {
        head = head->next;
        if (head == NULL) return NULL;
    } while (--index);
    return &head->element;
}//查找元素是否存在

int findList(Node head, E require) {
    head = head->next;
    int i = 1;
    while (head) {
        if (head->element == require) return i;
        head = head->next;
        i++;
    }
    return -1;
}//查找元素

int sizeList(Node head) {
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}//链表大小

void printList(Node head) {
    while (head->next) {
        head = head->next;
        printf("%d ", head->element);//头节点不存放数据，所以从第二个开始打印
    }
}

int main() {
    struct ListNode head;
    initList(&head);
    for (int i = 1; i <= 3; i++) {
        insertList(&head, i*100, i);
    }
    deleteList(&head, 2);
    printList(&head);
    printf("%d", *getList(&head, 1));
    return 0;
}