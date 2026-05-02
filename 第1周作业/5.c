//
// Created by 63092 on 2026/3/15.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int removezero(char *num) {
    int len = strlen(num);
    int start = 0;
    while (start < len && num[start] == '0') {
        start++;
    }
    if (start == len) {
        num[0] = '0';
        num[1] = '\0';
        return 1;
    }
    memmove(num, num + start, len - start + 1);
    return strlen(num);
}

int compare(char *a, char *b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    if (lena > lenb) return 1;
    if (lena < lenb) return -1;
    for (int i = 0; i < lena; i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void cal(char *big, char *small, char *ans) {
    int len = strlen(big);
    int jw = 0;
    for (int i = 0; i < len; i++) {
        int num1 = big[i] - '0' - jw;
        int num2 = small[i] - '0';
        jw = 0;
        if (num1 < num2) {
        num1 += 10;
        jw = 1;
        }
        ans[i] = num1 - num2 + '0';
    }
    ans[len] = '\0';
}

int main () {
    char a[100], b[100];
    char big[100], small[100];
    char ans[100];
    int x = 0;
    scanf("%s", a);
    scanf("%s", b);
    int lena = removezero(a);
    int lenb = removezero(b);
    int cmp = compare(a, b);
    if (cmp == 0) {
        printf("0\n");
        return 0;
    }else if (cmp < 0) {
        strcpy(big, b);
        strcpy(small, a);
        x = -1;
    }else {
        strcpy(big, a);
        strcpy(small, b);
    }
    reverse(big);
    reverse(small);
    int len1 = strlen(big);
    int len2 = strlen(small);
    for (int i = len2; i < len1; i++) {
        small[i] = '0';
    }
    small[len1] = '\0';
    cal(big, small, ans);
    reverse(ans);
    int answer = removezero(ans);
    if (x == -1) printf("-");
    printf("%s\n", ans);
    return 0;
}