//
// Created by 63092 on 2026/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct node {
    int x1, y1, x2, y2;
}Line;

int main() {
    int n;
    scanf("%d", &n);
    struct node lines[110];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
    }
    int max_count = 0;
    int x_start = 0, y_start = 0;
    for (int i = 0; i < n; i++) {
        int current_x2 = lines[i].x2;
        int current_y2 = lines[i].y2;
        int count = 1;
        _Bool find;
        while (1) {
            find = 0;
            for (int j = 0; j < n; j++) {
            if (lines[j].x1 == current_x2 && lines[j].y1 == current_y2) {
                current_x2 = lines[j].x2;
                current_y2 = lines[j].y2;
                count++;
                find = 1;
                break;
            }
            }
            if (!find) break;
        }
        if (count > max_count) {
            max_count = count;
            x_start = lines[i].x1;
            y_start = lines[i].y1;
        }
    }
    printf("%d %d %d\n", max_count, x_start, y_start);
    return 0;
}
