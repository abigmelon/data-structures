#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char format[100] = {0};
char text[100] = {0};

void print(char *text, int m, int n, int op) {
    int len = strlen(text);
    int take = m < len ? m : len;

    if (n <= take) {
        printf("%.*s\n", take, text);
    } else {
        int pad = n - take;
        if (op == 0) {
            for (int i = 0; i < pad; i++) putchar('#');
            printf("%.*s\n", take, text);
        } else {
            printf("%.*s", take, text);
            for (int i = 0; i < pad; i++) putchar('#');
            putchar('\n');
        }
    }
}

int main() {
    getchar();
    fgets(format, 100, stdin);
    fgets(text, 100, stdin);

    int lenf = strlen(format);
    int lent = strlen(text);
    format[lenf - 1] = '\0';
    text[lent - 1] = '\0';

    int op;
    if (format[0] == '-') {
        op = 0;
    } else {
        op = 1;
    }
    int m, n;
    sscanf(format + 1 - op, "%d:%d", &m, &n);
    print(text, m, n, op);
    return 0;
}