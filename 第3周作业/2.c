//
// Created by 63092 on 2026/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

struct node{
    int xishu;
    int zhishu;
    struct node *next;
};

typedef struct node * Node;

void initList(Node node) {
    node->next = NULL;
}

Node addNode(int xishu, int zhishu) {
    Node head = (Node)malloc(sizeof(struct node));
    head->xishu = xishu;
    head->zhishu = zhishu;
    head->next = NULL;
    return head;
}

Node initNode() {
    Node head = addNode(0,0);
    Node tail = head;
    int xishu, zhishu;
    while (1) {
        int p = scanf("%d %d", &xishu, &zhishu);
        if (p != 2) break;
        tail->next = addNode(xishu, zhishu);
        tail = tail->next;
        char c = getchar();
        if (c == '\n') break;
        if (c != EOF) ungetc(c, stdin);
    }
    return head;
}

Node multiply(Node head1, Node head2){
    Node new_head = addNode(0, 0);
    Node p1 = head1->next;
    Node p2 = NULL;
    while (p1 != NULL) {
        p2 = head2->next;
        while (p2 != NULL) {
            int new_xishu = p1->xishu * p2->xishu;
            int new_zhishu = p1->zhishu + p2->zhishu;
            Node current = new_head;
            _Bool find = 0;
            while (current->next != NULL) {
            if (current->next->zhishu == new_zhishu) {
                current->next->xishu += new_xishu;
                find = 1;
                break;
            }
            current = current->next;
            }
            if (!find) {
            Node new_node = addNode(new_xishu, new_zhishu);
            current->next = new_node;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return new_head;
}

void removeZero(Node head) {
    Node current = head;
    while (current->next != NULL) {
        if (current->next->xishu == 0) {
            Node temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void sortList(Node head) {
    Node p, q;
    int temp_xishu = 0, temp_zhishu = 0;
    for (p = head->next; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->zhishu < q->zhishu) {
                temp_xishu = p->xishu;
                temp_zhishu = p->zhishu;
                p->xishu = q->xishu;
                p->zhishu = q->zhishu;
                q->xishu = temp_xishu;
                q->zhishu = temp_zhishu;
            }
        }
    }
}

void printList(Node head) {
    Node p = head->next;
    while (p != NULL) {
        printf("%d %d ", p->xishu, p->zhishu);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node head1 = initNode();
    Node head2 = initNode();
    Node head3 = multiply(head1, head2);
    removeZero(head3);
    sortList(head3);
    printList(head3);
    return 0;
}