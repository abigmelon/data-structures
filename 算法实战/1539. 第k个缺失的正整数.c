//
// Created by 63092 on 2026/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int findKthPositive(int* arr, int arrSize, int k) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= k) {
            k++;
        } else break;
    }
    return k;
}