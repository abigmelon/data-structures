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

int ascii[127] = {0};
char removed[127];
char list[127];

struct ListNode {
    char c;
    struct ListNode *next;
};

typedef struct ListNode * Node;

void initList(Node node) {
    node->next = NULL;
}

_Bool insertList(Node head, char c, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->c = c;
    node->next = head->next;
    head->next = node;
    return 1;
}

Node getPre(Node head, Node aim) {
    Node temp = aim->next;
    while (temp->next != aim) {
        temp = temp->next;
    }
    return temp;
}

void deleteNode(Node head, Node del) {
    Node pre = getPre(head, del);
    pre->next = del->next;
    free(del);
}

int main() {
    struct ListNode head;
    initList(&head);
    int c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        if (ascii[(int)c] == 0) {
            removed[i] = c;
            i++;
            ascii[(int)c] = 1;
        }
    }
    for (int j = 32; j <= 126; j++) {
        if (ascii[j] == 0) {
            removed[i] = j;
            i++;
        } else continue;
    }
    for (int k = 0; k < i; k++) {
        insertList(&head, removed[k], k + 1);
    }
    Node tail = &head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head.next;
    Node cur = head.next;
    char start = cur->c;
    for (int l = 95; l >= 1; l--) {
        if (l == 1) {
            list[(int)cur->c] = start;
            break;
        }
        char src = cur->c;
        Node nextNode = cur->next;
        deleteNode(&head, cur);
        cur = nextNode;
        int step = (int)src;
        for (int s = 0; s < step - 1; s++) {
            cur = cur->next;
        }
        list[(int)src] = cur->c;
    }
    FILE *fin = fopen("in.txt", "r");
    FILE *fout = fopen("in_crpyt.txt", "w");
    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        if (ch >= 32 && ch <= 126) {
            fputc(list[(int)ch], fout);
        } else {
            fputc(ch, fout);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}