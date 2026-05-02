//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("file2.txt", "a+");
    if (file == NULL) printf("Error opening file2.txt");
    else {
        fprintf(file, "This is a test file");
        fclose(file);
    }
    return 0;
}