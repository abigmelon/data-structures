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

_Bool insertList(Node head, int weight) {
    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0;
    node->weight = weight;
    while(head->next){
        head = head->next;
    }
    head->next = node;
    node->next = NULL;
    return 1;
}

void upSortList(Node head) {
    Node end = NULL;
    while(head->next != end){
        Node tmp = head->next;
        while(tmp->next != end){
            if(tmp->weight > tmp->next->weight){
                int weight = tmp->weight;
                tmp->weight = tmp->next->weight;
                tmp->next->weight = weight;
            }
            tmp = tmp->next;
        }
        end = tmp;
    }
}

void deleteList(Node head) {
    if(head->next == NULL) return;
    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
}

void combineList(Node head) {
    Node prev = head;
    Node tmp = head->next;
    int sum = 0;
    while(tmp){
        if(tmp->weight < 10){
            sum += tmp->weight;
            prev->next = tmp->next;
            free(tmp);
            tmp = prev->next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    if(sum > 0){
        insertList(head, sum);
    }
}

int sumList(Node head) {
    int sum = 0;
    while(head->next){
        sum += head->next->weight;
        head = head->next;
    }
    return sum;
}

void printList(Node head) {
    while(head->next){
        printf("%d ", head->next->weight);
        head = head->next;
    }
}

int main(){
    Node head = malloc(sizeof(struct ListNode));
    initList(head);
    int op;
    while(scanf("%d", &op) != EOF) {
        if(op == 999999) break;
        if(op > 0){
            insertList(head, op);
            upSortList(head);
        }
        if(op == 0){
            combineList(head);
            upSortList(head);
        }
        if(op < 0){
            int sum = sumList(head);
            int require = -op;
            if(sum < require){
                continue;
            }
            if(sum == require){
                while(head->next){
                    deleteList(head);
                }
                continue;
            }
            if(sum > require){
                while(require >= head->next->weight && require > 0){
                    require -= head->next->weight;
                    deleteList(head);
                }
                if(require == 0){
                    continue;
                }
                if(head->next && require < head->next->weight){
                    head->next->weight -= require;
                }
            }
        }
    }
    printList(head);
    return 0;
}