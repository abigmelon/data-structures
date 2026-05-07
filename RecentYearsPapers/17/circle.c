#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int element;
    struct listNode *next;
};

typedef struct listNode *Node;

int main(void) {
    Node head = malloc(sizeof(struct listNode));
    if (head == NULL) return 1;
    head->next = NULL;

    int n;
    scanf("%d", &n);

    Node tail = head;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        Node node = malloc(sizeof(struct listNode));
        if (node == NULL) return 1;
        node->element = val;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }

    if (n == 0) {
        free(head);
        return 0;
    }
    tail->next = head->next;
    Node current = head->next;
    for (int round = 0; round < n; round++) {
        if (current->next == current) {
            printf("%d \n", current->element);
            free(current);
            break;
        }
        Node prev_current = current;
        while (prev_current->next != current)
            prev_current = prev_current->next;

        int min_val = current->element;
        Node min_node = current;
        Node min_prev = prev_current;

        Node p = current->next;
        Node p_prev = current;
        do {
            if (p->element < min_val) {
                min_val = p->element;
                min_node = p;
                min_prev = p_prev;
            }
            p_prev = p;
            p = p->next;
        } while (p != current);

        p = current;
        do {
            printf("%d ", p->element);
            if (p == min_node) break;
            p = p->next;
        } while (1);
        printf("\n");
        min_prev->next = min_node->next;
        current = min_node->next;
        free(min_node);
    }

    free(head);
    return 0;
}