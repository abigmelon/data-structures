//
// Created by 63092 on 2026/3/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *current = head;
    struct ListNode *pre = NULL;
    while (current != NULL) {
        struct ListNode *next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    return pre;
}