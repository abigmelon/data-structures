//
// Created by 63092 on 2026/4/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct ListNode {
    int weight;
    struct ListNode *next;
};

typedef struct ListNode * Node;

void initList(Node node) {
    node->next = NULL;
}

_Bool deleteList(Node head, int index) {
    if (index < 1) return 0;
    while (index--) {
        head = head->next;
        if (head == NULL) return 0;
    }
    if (head->next == NULL) return 0;

    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return 1;
}

void printList(Node head) {
    while (head->next) {
        head = head->next;
        printf("%d ", head->weight);
    }
}

int getSum(Node head) {
    int sum = 0;
    Node p = head->next;
    while (p) {
        sum += p->weight;
        p = p->next;
    }
    return sum;
}

int combineList(Node head) {
    int sum = 0;
    Node p = head;
    while (p->next != NULL) {
        if (p->next->weight < 10) {
            sum += p->next->weight;
            Node tmp = p->next;
            p->next = p->next->next;
            free(tmp);
        } else {
            p = p->next;
        }
    }
    return sum;
}

void upSort(Node head, int weight) {
    Node p = head;
    while (p->next != NULL && p->next->weight < weight) {
        p = p->next;
    }
    Node q = malloc(sizeof(struct ListNode));
    q->weight = weight;
    q->next = p->next;
    p->next = q;
}

int main() {
    Node head = malloc(sizeof(struct ListNode));
    initList(head);
    int op = 0;
    while (scanf("%d", &op) != EOF) {
        if (op == 999999) break;
        if (op > 0) {
            upSort(head, op);
        } else if (op < 0) {
            int require = -op;
            int sum = getSum(head);
            if (sum < require) continue;
            if (sum == require) {
                head->next = NULL;
            }
            if (sum > require) {
                int cur = 0;
                Node p = head;
                while (p->next != NULL && cur + p->next->weight <= require) {
                    cur += p->next->weight;
                    Node tmp = p->next;
                    p->next = p->next->next;
                    free(tmp);
                }
                if (cur < require && p->next != NULL) {
                    int delta = require - cur;
                    p->next->weight -= delta;
                    if (p->next->weight == 0) {
                        Node tmp = p->next;
                        p->next = p->next->next;
                        free(tmp);
                    }
                }
            }
        } else if (op == 0) {
            int combined = combineList(head);
            if (combined > 0) upSort(head, combined);
        }
    }
    printList(head);
    return 0;
}