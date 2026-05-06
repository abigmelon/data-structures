#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct listNode {
    int element;
    int count;
    struct listNode *next;
};

typedef struct listNode * Node;

void initList(Node node) {
    node->next = NULL;
}

int allTimes = 0;

Node findPrevList(Node head, int newElement) {
    if (head == NULL) return NULL;
    Node prev = head;
    while (prev->next) {
        allTimes++;
        if (prev->next->element == newElement) return prev;
        prev = prev->next;
    }
    return prev;
}

void deleteNextList(Node prev) {
    if (prev == NULL) return;
    Node tmp = prev->next;
    if (tmp) {
        prev->next = tmp->next;
        free(tmp);
    }
}

void insertList(Node head, int element) {
    Node prev = findPrevList(head, element);
    Node p = prev->next;
    if (p != NULL) {
        p->count++;
        prev->next = p->next;
        p->next = head->next;
        head->next = p;
    } else {
        while(head->next){
            head = head->next;
        }
        Node node = malloc(sizeof(struct listNode));
        node->element = element;
        node->count = 1;
        node->next = NULL;
        head->next = node;
    }
}

void print5List(Node head) {
    if (head == NULL) return;
    Node p = head->next;
    int i = 0;
    while (p && i < 5) {
        printf("%d %d\n", p->element, p->count);
        p = p->next;
        i++;
    }
}

int main(){
    Node head = malloc(sizeof(struct listNode));
    initList(head);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf("%d", &element);
        insertList(head, element);
    }
    printf("%d\n", allTimes);
    print5List(head);
    return 0;
}