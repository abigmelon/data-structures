//
// Created by 63092 on 2026/3/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[50];
    char author[20];
    char publisher[30];
    char date[10];
}Book;

Book *list = NULL;
int book_num = 0;

int cmp(const void *a, const void *b) {
    return strcmp(((Book *)a)->name,((Book *)b)->name);
}

void initBook() {
    list = (Book *)malloc(sizeof(Book) * 500);
    FILE *fp = fopen("books.txt", "r");
    while (fscanf(fp, "%s %s %s %s", list[book_num].name, list[book_num].author, list[book_num].publisher, list[book_num].date) == 4) {
        book_num++;
        if (book_num >= 500) break;
    }
    fclose(fp);
    qsort(list, book_num, sizeof(Book), cmp);
}

void addbook() {
    Book newbook;
    scanf("%s %s %s %s", newbook.name, newbook.author, newbook.publisher, newbook.date);
    int pos = 0;
    for (;pos < book_num; pos++) {
        if (strcmp(newbook.name,list[pos].name) < 0) break;
    }
    for (int i = book_num; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = newbook;
    book_num++;
}

void findbook() {
    char keyword[60];
    scanf("%s", keyword);
    Book *found = (Book *)malloc(500 * sizeof(Book));
    int found_num = 0;
    for (int i = 0; i < book_num; i++) {
        if (strstr(list[i].name, keyword) != NULL) {
            found[found_num++] = list[i];
        }
    }
    qsort(found, found_num, sizeof(Book), cmp);
    for (int i = 0; i < found_num; i++) {
        printf("%-50s%-20s%-30s%-10s\n", found[i].name, found[i].author, found[i].publisher, found[i].date);
    }
    free(found);
}

void deletebook() {
    char keyword[60];
    scanf("%s", keyword);
    int cnt = 0;
    for (int i = 0; i < book_num; i++) {
        if (strstr(list[i].name, keyword) == NULL) {
            list[cnt++] = list[i];
        }
    }
    book_num = cnt;
    qsort(list, book_num, sizeof(Book), cmp);
}

void savebook() {
    FILE *fp = fopen("ordered.txt", "w");
    for (int i = 0; i < book_num; i++) {
        fprintf(fp, "%-50s%-20s%-30s%-10s\n", list[i].name, list[i].author, list[i].publisher, list[i].date);
    }
    fclose(fp);
}

int main() {
    initBook();
    int op;
    while (1) {
        scanf("%d", &op);
        switch (op) {
        case 0:
            savebook();
                free(list);
                return 0;
        case 1:
            addbook();
            break;
        case 2:
            findbook();
            break;
        case 3:
            deletebook();
            break;
        }
    }
}