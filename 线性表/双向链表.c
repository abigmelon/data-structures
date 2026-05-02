//
// Created by 63092 on 2026/3/18.
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
    struct ListNode *prev;
};//一前一后

typedef struct ListNode * Node;

void initList(Node head) {
    head->next = NULL;
    head->prev = NULL;
}

_Bool insertList(Node head, E element, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->element = element;

    if (head->next != NULL) {
        node->next = head->next;
        head->next->prev = node;
    } else {
        node->next = NULL;
    }

    head->next = node;
    node->prev = head;

    return 1;
}

_Bool deleteList(Node head, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    if (head->next == NULL) return 0;

    Node tmp = head->next;//待删除节点

    if (head->next->next) {
        head->next->next->prev = head;
        head->next = head->next->next;
    } else {
        head->next = NULL;
    }
    free(tmp);
    return 1;
}

int main() {
    struct ListNode head;
    initList(&head);
    for (int i = 1; i <= 5; ++i)  //插5个元素吧
        insertList(&head, i * 100, i);

    deleteList(&head, 3);

    Node node = &head;   //先来正向遍历一次
    do {
        node = node->next;
        printf("%d -> ", node->element);
    } while (node->next != NULL);

    printf("\n");   //再来反向遍历一次
    do {
        printf("%d -> ", node->element);
        node = node->prev;
    } while (node->prev != NULL);
    return 0;
}