//
// Created by 63092 on 2026/3/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int pd(char * file, char * target, int p) {
    int len = strlen(target);
    if (len + p > strlen(file)) return 0;
    for (int i = 0; i < len; i++) {
        if (tolower(file[p + i]) != tolower(target[i])) return 0;
    }
    return 1;
}

int main() {
    char a[100], b[100];
    char file[10000];
    FILE *fin, *fout;
    fgets(a, 100, stdin);
    fgets(b, 100, stdin);
    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';
    fin = fopen("filein.txt", "r");
    int len = 0;
    char c;
    while ((c = fgetc(fin)) != EOF && len < sizeof(file) - 1) {
        file[len++] = c;
    }
    file[len] = '\0';
    fclose(fin);
    fout = fopen("fileout.txt", "w");
    int l = strlen(a), i = 0;
    while (i < len) {
        if (pd(file, a, i)) {
            fputs(b, fout);
            i += l;
        } else {
            fputc(file[i], fout);
            i++;
        }
    }
    fclose(fout);
    return 0;
}