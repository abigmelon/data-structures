//
// Created by 63092 on 2026/3/18.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int n;
int *pl, *used;

void qpl(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", pl[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
        return;
    }
    for (int num = 1; num <= n; num++) {
        if (!used[num]) {
            used[num] = 1;
            pl[pos] = num;
            qpl(pos + 1);
            used[num] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    pl = (int *)malloc(n * sizeof(int));
    used = (int *)calloc(n + 1,sizeof(int));
    qpl(0);
    free(pl);
    free(used);
    return 0;
}