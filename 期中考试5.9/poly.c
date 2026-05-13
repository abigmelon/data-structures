//
// Created by 63092 on 2026/5/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct ListNode {
    int xishu;
    int zhishu;
    struct ListNode *next;
};

typedef struct ListNode* Node;

void initList(Node node) {
    node->next = NULL;
}

void headInsert(Node head, int xishu, int zhishu) {
    Node tmp = malloc(sizeof(struct ListNode));
    tmp->xishu = xishu;
    tmp->zhishu = zhishu;
    tmp->next = head->next;
    head->next = tmp;
}

int cmpList(Node head) {
    if (head->next == NULL) return 0;
    if (head->next->next == NULL) return 0;
    int count = 0;
    while (head->next && head->next->next) {
        if (head->next->zhishu == head->next->next->zhishu) {
            count++;
            Node tmp = head->next;
            head->next = tmp->next;
            head->next->xishu += tmp->xishu;
            if (head->next->xishu == 0) head->next = head->next->next;
            free(tmp);
            break;
        } else if (head->next->zhishu > head->next->next->zhishu) {
            count++;
            break;
        } else if (head->next->zhishu < head->next->next->zhishu) {
            int xishu = head->next->xishu;
            int zhishu = head->next->zhishu;
            head->next->xishu = head->next->next->xishu;
            head->next->zhishu = head->next->next->zhishu;
            head->next->next->zhishu = zhishu;
            head->next->next->xishu = xishu;
            count++;
        }
        head = head->next;
    }
    return count;
}

void printList(Node head) {
    if (head == NULL) return;
    while (head->next != NULL) {
        printf("%d %d\n", head->next->xishu, head->next->zhishu);
        head = head->next;
    }
}

int main() {
    struct ListNode head;
    initList(&head);
    int xishu, zhishu;
    int op = 0;
    int count = 0;
    while (scanf("%d %d", &xishu, &zhishu) != EOF) {
        if (xishu == 0 && zhishu == -1) break;
        headInsert(&head, xishu, zhishu);
        op++;
        if (op > 1) {
            count += cmpList(&head);
        }
    }
    printList(&head);
    printf("%d", count);
}