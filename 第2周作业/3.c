//
// Created by 63092 on 2026/3/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    int alpha[26] = {0};
    char word[100] = {0};
    char password[26] = {0};
    fgets(word, 100, stdin);
    size_t len = strlen(word);
    if (len > 0 && (word[len-1] == '\n' || word[len-1] == '\r')) {
        word[len-1] = '\0';
    }
    len = strlen(word);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!islower(word[i])) continue;
        int idx = word[i] - 'a';
        if (alpha[idx] == 0) {
            password[j++] = word[i];
            alpha[idx] = 1;
        }
    }
    for (int i = 25; i >= 0; i--) {
        if (alpha[i] == 0) {
            password[j++] = 'a' + i;
        }
    }
    password[j] = '\0';
    FILE *in = fopen("encrypt.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int c;
    while ((c = fgetc(in)) != EOF) {
        fputc(islower(c) ? password[c - 'a'] : c , out);
    }
    fclose(in);
    fclose(out);
    return 0;
}