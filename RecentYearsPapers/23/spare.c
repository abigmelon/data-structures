#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct blockList {
    int pos;
    int size;
    struct blockList *next;
};

typedef struct blockList * Node;

void initList(Node node) {
    node->next = NULL;
}

_Bool insertList(Node head, int pos, int size) {
    Node node = malloc(sizeof(struct blockList));
    if (node == NULL) return 0;
    while(head->next){
        head = head->next;
    }
    node->pos = pos;
    node->size = size;
    node->next = head->next;
    head->next = node;

    return 1;
}

Node deleteList(Node head) {
    if (head == NULL) return 0;
    if (head->next == NULL) return 0;
    Node tmp = head->next;
    head->next = tmp->next;
    return tmp;
}

Node findList(Node head, Node current, int require) {
    if (current == NULL) return NULL;
    Node p = current;
    do {
        if (p->size >= require) return p;
        p = p->next;
    } while (p != current);
    return NULL;
}

Node findTailList(Node head){
    while(head->next){
        head = head->next;
    }
    Node tmp = head;
    return tmp;
}

void printList(Node current) {
    if (current == NULL) return;
    Node p = current;
    do {
        printf("%d %d\n", p->pos, p->size);
        p = p->next;
    } while (p != current);
}

int main(){
    struct blockList head;
    initList(&head);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int pos, size;
        scanf("%d%d", &pos, &size);
        insertList(&head, pos, size);
    }
    Node first = head.next;     //注意一个点，head是空节点，不在环里面
    Node tail = findTailList(&head);
    tail->next = first;
    Node current = first;
    int require;
    while(scanf("%d", &require) != EOF){
        if(require == -1) break;
        Node found = NULL;
        Node p = current;
        if(p != NULL){
            do{
                if(p->size >= require){
                    found = p;
                    break;
                }
                p = p->next;
            } while (p != current);
        }
        if (found == NULL) continue;
        if(found->size == require){
            Node tmp = current;
            while(tmp->next != found){
                tmp = tmp->next;
            }
            current = (found == found->next) ? NULL : found->next;
            tmp->next = found->next;
            free(found);
        } else {
            found->size -= require;
            current = found;
        }
    }
    printList(current);
    return 0;
}