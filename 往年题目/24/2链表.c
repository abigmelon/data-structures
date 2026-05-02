//
// Created by 63092 on 2026/4/7.
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

_Bool insertList(Node head, int element, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }

    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->weight = element;
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

    Node temp = head->next;
    head->next = head->next->next;
    free(temp);
    return 1;
}

int findList(Node head, int require) {
    head = head->next;
    int i = 1;
    while (head) {
        if (head->weight == require) return i;
        head = head->next;
        i++;
    }
    return -1;
}

int sizeList(Node head) {
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
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
    while (p != NULL) {
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
            Node temp = p->next;
            p->next = p->next->next;
            free(temp);
        } else {
            p = p->next;
        }
    }
    return sum;
}

void upsort(Node head, int weight) {
    Node p = head;
    while (p->next != NULL && p->next->weight < weight) {
        p = p->next;
    }
    Node newNode = (Node)malloc(sizeof(struct ListNode));
    newNode->weight = weight;
    newNode->next = p->next;
    p->next = newNode;
}

int main() {
    Node head = malloc(sizeof(struct ListNode));
    initList(head);
    int op;
    int index = 1;
    while (1) {
        scanf("%d", &op);
        if (op == 999999) break;
        if (op > 0) {
            upsort(head, op);
        } else if (op < 0) {
            int need = -op;
            int sum = getSum(head);
            if (sum < need) continue;
            else if (sum == need) {
                head->next = NULL;
            } else {
                int current = 0;
                Node p = head;
                while (p->next != NULL && current + p->next->weight <= need) {
                    current += p->next->weight;
                    Node temp = p->next;
                    p->next = p->next->next;
                    free(temp);
                }
                if (current < need && p->next != NULL) {
                    int delta = need - current;
                    p->next->weight -= delta;
                    if (p->next->weight == 0) {
                        Node temp = p->next;
                        p->next = p->next->next;
                        free(temp);
                    }
                }
            }
        } else if (op == 0) {
            int leftsum = combineList(head);
            if (leftsum > 0) {
                upsort(head, leftsum);
            }
        }
    }
    printList(head);
    return 0;
}