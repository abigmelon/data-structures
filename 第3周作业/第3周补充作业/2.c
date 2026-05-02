//
// Created by 63092 on 2026/4/21.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int num;
    int count;
    struct ListNode *next;
};

typedef struct ListNode * Node;

_Bool findNum(Node head, int num) {
    if (head->next == NULL) return 0;
    while (head->next != NULL) {
        if (head->num == num) return 1;
        head = head->next;
    }
    return 0;
}

_Bool insertList(Node head, int num) {
    if (head->next == NULL) return 0;
    while (head->next) {
        head = head->next;
    }
    Node node = malloc(sizeof(struct ListNode));
    node->num = num;
    node->next = NULL;
    head->next = node;
    return 1;
}

Node moveList(Node head, int num) {

}

int main() {
    Node head = malloc(sizeof(struct ListNode));
    int n;
    scanf("%d", &n);
}

