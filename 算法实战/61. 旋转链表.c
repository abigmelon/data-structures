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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0 || head == NULL || head->next == NULL) {
        return head;
    }
    int size = 1;
    struct ListNode *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        size++;
    }
    int move = size - k % size;
    if (move == 0) return head;
    tail->next = head;
    while (move--) {
        tail = tail->next;
    }
    struct ListNode *newHead = tail->next;
    tail->next = NULL;
    return newHead;
};