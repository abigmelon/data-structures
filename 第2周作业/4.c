//
// Created by 63092 on 2026/3/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct list {
    char name[20];
    char name1[20];
    char phone[20];
};

int cmp(const void *a, const void *b) {
    const struct list *p1 = (const struct list *)a;
    const struct list *p2 = (const struct list *)b;
    return strcmp(p1->name1, p2->name1);
}

int main() {
    struct list s[100];
    struct list temp[100];
    int n = 0;
    int bl[100] = {0};
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        char name[20], phone[20];
        scanf("%s %s",name,phone);
        strcpy(s[i].name,name);
        strcpy(s[i].name1,name);
        strcpy(s[i].phone,phone);
        int cf = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(s[j].name, name)==0 && strcmp(s[j].phone, phone)==0 && bl[j]) {
                cf = 1;
                break;
            }
        }
        bl[i] = !cf;
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (bl[i]) {
            temp[m++] = s[i];
        }
    }
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(temp[j].name, temp[i].name) == 0) {
                count++;
            }
        }
        if (count == 0) {
            strcpy(temp[i].name1,temp[i].name);
        }else {
            sprintf(temp[i].name1, "%s_%d", temp[i].name, count);
        }
    }
    qsort(temp,m,sizeof(struct list),cmp);
    for (int i = 0; i < m; i++) {
        printf("%s %s\n",temp[i].name1, temp[i].phone);
    }
    return 0;
}