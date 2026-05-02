#include <stdio.h>
#include <stdlib.h>
struct node {
    int n;
    struct node *link;
};

int main()
{
    int n;
    struct node *list=NULL, *tail, *q;

    scanf("%d",&n);
    while(n!=-1){
        q = (struct node *)malloc(sizeof(struct node));
        q->n = n;
        q->link = NULL;

        if(list == NULL)
            list = q;
        else
            tail->link = q;
        tail=q;

        scanf("%d",&n);
    }

    struct node *p = list;
    int first = 1;
    while (p != NULL) {
        char str[20];
        sprintf(str, "%d", p->n);
        int len = 0;
        while (str[len] != '\0') len++;
        if (!first) printf(" ");
        first = 0;
        for (int i = 0; i < len; i++) {
            printf("%c", str[i]);
            if ((len - i - 1) % 3 == 0 && i != len - 1) {
                printf(",");
            }
        }
        struct node *temp = p;
        p = p->link;
        free(temp);
    }

    return 0;
}