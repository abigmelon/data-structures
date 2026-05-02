//
// Created by 63092 on 2026/3/15.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void rmsp(char * str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int js(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int main () {
    char s[100];
    char c[100];
    int n[100];
    char o[100];
    fgets(s, 100, stdin);
    strcpy(c, s);
    rmsp(c);
    char * eq = strchr(c, '=');
    if (eq != NULL) {
        *eq = '\0';
    }
    int len = strlen(c);
    int numcnt = 0;
    int opcnt = 0;

    for (int i = 0; i < len; i++) {
        int num = 0;
        while (i < len && isdigit(c[i])) {
            num = num * 10 + c[i] - '0';
            i++;
        }
        n[numcnt++] = num;
        if (i < len) {
            o[opcnt++] = c[i];
        }
    }

    int j = 0, k = 0;
    while (k < opcnt) {
        if (o[k] == '*' || o[k] == '/') {
            n[k] = js(n[k], n[k+1], o[k]);
            for (j = k; j < opcnt - 1; j++) {
            o[j] = o[j+1];
            n[j+1] = n[j+2];
            }
        opcnt--;
        numcnt--;
        } else {
            k++;
        }
    }
    int ans = n[0];
    for (int i = 0; i < opcnt; i++) {
        ans = js(ans, n[i+1], o[i]);
    }
    printf("%d\n", ans);
    return 0;
}