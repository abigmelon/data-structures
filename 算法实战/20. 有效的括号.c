//
// Created by 63092 on 2026/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

bool isValid(char* s) {
    int top = 0;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(') {
            s[top++] = ')';
        } else if (c == '[') {
            s[top++] = ']';
        } else if (c == '{') {
            s[top++] = '}';
        } else if (top == 0 || s[--top] != c) {
            return false;
        }
    }
    return top == 0;
}