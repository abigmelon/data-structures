#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int element;
    struct listNode *next;
};

typedef struct listNode * Node;

void initList(Node node) {
    node->next = NULL;
}

_Bool insertList(Node head, int element) {
    Node node = malloc(sizeof(struct listNode));
    if (node == NULL) return 0;
    while (head->next)
        head = head->next;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

Node findTailList(Node head) {
    while (head->next)
        head = head->next;
    return head;
}

int main() {
    struct listNode head;
    initList(&head);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        insertList(&head, num);
    }

    // 构成循环链表（哑结点不参与环）
    Node first = head.next;
    Node tail = findTailList(&head);
    tail->next = first;

    Node current = first;

    for (int round = 0; round < n; round++) {
        // 只剩一个节点，直接输出并删除
        if (current->next == current) {
            printf("%d \n", current->element);
            free(current);
            break;
        }

        // 找到 current 的前驱（环中最后一个节点）
        Node tail_prev = current;
        while (tail_prev->next != current)
            tail_prev = tail_prev->next;

        // 第一遍遍历：找最小值和它的前驱
        Node min_node = current;
        Node min_prev = tail_prev;
        int min_val = current->element;

        Node p = current->next;
        Node prev = current;
        do {
            if (p->element < min_val) {
                min_val = p->element;
                min_node = p;
                min_prev = prev;
            }
            prev = p;
            p = p->next;
        } while (p != current);

        // 第二遍遍历：从 current 打印到 min_node（包含）
        p = current;
        do {
            printf("%d ", p->element);
            if (p == min_node) break;
            p = p->next;
        } while (1);
        printf("\n");

        // 删除 min_node，当前位置移到 min_node 的下一个
        current = min_node->next;
        min_prev->next = min_node->next;
        free(min_node);
    }

    return 0;
}