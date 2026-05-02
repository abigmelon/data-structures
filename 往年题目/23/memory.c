
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct ListNode {
    int pos;
    int size;
    struct ListNode *next;
};

typedef struct ListNode * Node;

void initList(Node node) {
    node->next = NULL;
}

_Bool insertList(Node head, int pos, int size, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }

    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->pos = pos;
    node->size = size;
    node->next = head->next;
    head->next = node;

    return 1;
}

Node cur_pos = NULL;

int findList(Node head, int require) {
    if (head->next == NULL) return -1;
    if (cur_pos == NULL) cur_pos = head->next;
    Node start = cur_pos;
    Node p = cur_pos;
    Node pre = head;
    while (pre->next != p) pre = pre->next;
    while (1) {
        if (p->size >= require) {
            if (p->size == require) {
                pre->next = p->next;
                if (p->next != NULL) cur_pos = p->next;
                else cur_pos = head->next;
                free(p);
            } else {
                p->size -= require;
                cur_pos = p;
            }
            return 1;
        }
        pre = p;
        if (p->next != NULL) p = p->next;
        else p = head->next;
        if (p == start) break;
    }
    return -1;
}

void printList(Node head) {
    if (cur_pos == NULL) return;
    Node p = cur_pos;
    while (1) {
        printf("%d %d\n", p->pos, p->size);
        if (p->next != NULL) p = p->next;
        else p = head->next;
        if (p == cur_pos) break;
    }
}

int main() {
    Node head = malloc(sizeof(struct ListNode));
    initList(head);
    int n;
    scanf("%d", &n);
    int pos, size;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos, &size);
        insertList(head, pos, size, i);
    }
    int require = 0;
    while (scanf("%d", &require) != EOF) {
        if (require == -1) {
            break;
        }
        int cur = findList(head, require);
        if (cur == -1) continue;
    }
    printList(head);
    return 0;
}