//
// Created by 63092 on 2026/3/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

struct Block {
    int pos;
    int size;
    struct Block *next;
};

typedef struct Block *block;

block current;

void initList(block node) {
    node->next = NULL;
}

_Bool insertList(block head, int pos, int size, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    block node = malloc(sizeof(struct Block));
    if (node == NULL) return 0;
    node->pos = pos;
    node->size = size;
    node->next = head->next;
    head->next = node;

    return 1;
}

block getPre(block head, block aim) {
    block temp = aim;
    while (temp->next != aim) {
        temp = temp->next;
    }
    return temp;
}

void deleteList(block head, block del) {
    int isLast = (del->next == del);
    block pre = getPre(head, del);
    pre->next = del->next;
    if (isLast) {
        current = NULL;
    } else {
        current = del->next;
    }
    free(del);
}

block findList(block head, int size) {
    if (current == NULL) return NULL;
    block p = current;
    block best = NULL;
    int min = INT_MAX;
    do {
        if (p->size >= size) {
            int delta = p->size - size;
            if (delta < min) {
            min = delta;
            best = p;
            }
        }
        p = p->next;
    } while (p != current);
    return best;
}

void printList(block head) {
    if (current == NULL) return;
    block p = current;
    do {
        printf("%d %d\n", p->pos, p->size);
        p = p->next;
    } while (p != current);
}

int main() {
    int n;
    scanf("%d", &n);
    struct Block head;
    initList(&head);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        insertList(&head, a, b, i);
    }
    block tail = &head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head.next;
    current = head.next;
    int request;
    while (1) {
        scanf("%d", &request);
        if (request == -1) break;
        block best = findList(&head, request);
        if (best == NULL) continue;
        if (best->size == request) {
            deleteList(&head, best);
        } else {
            best->size -= request;
            current = best;
        }
    }
    printList(&head);
    return 0;
}