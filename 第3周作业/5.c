//
// Created by 63092 on 2026/3/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    char word[100];
    int count;
} word_count;

int cmp(const void *a, const void *b) {
    return strcmp(((word_count *)a)->word, ((word_count *)b)->word);
}

int main() {
    FILE * file = fopen("article.txt", "r");
    if (file == NULL) return 0;
    word_count words[1000];
    int words_count = 0;
    char ch;
    char temp[100];
    int index = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            temp[index++] = tolower(ch);
            temp[index] = '\0';
        } else {
            if (index > 0) {
                _Bool found = false;
                for (int i = 0; i < words_count; i++) {
                    if (strcmp(temp, words[i].word) == 0) {
                        words[i].count++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    strcpy(words[words_count].word, temp);
                    words[words_count].count = 1;
                    words_count++;
                }
                index = 0;
            }
        }
    }
    if (index > 0) {
        _Bool found = false;
        for (int i = 0; i < words_count; i++) {
            if (strcmp(words[i].word, temp) == 0) {
                words[i].count++;
                found = true;
                break;
            }
        }
        if (!found) {
        strcpy(words[words_count].word, temp);
        words[words_count].count = 1;
        words_count++;
        }
    }
    qsort(words, words_count, sizeof(word_count), cmp);
    for (int i = 0; i < words_count; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }
    fclose(file);
    return 0;
}