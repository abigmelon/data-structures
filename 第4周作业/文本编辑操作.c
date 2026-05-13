#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Stack{
    int op;
    int pos;
    char str[600];
};

char ans[600] = {0};
struct Stack stack[400];
int top = -1;
int len = 0;

void insert(int pos, char* s){
    int sl = strlen(s);
    for(int i = len - 1; i >= pos; i--){
        ans[i + sl] = ans[i];
    }
    for(int i = 0; i < sl; i++){
        ans[pos + i] = s[i];
    }
    len += sl;
    ans[len] = '\0';
}

void delete(int pos, int n, char* del){
    if(pos + n > len) n = len - pos;
    for(int i = 0; i < n; i++){
        del[i] = ans[pos + i];
    }
    del[n] = '\0';
    for(int i = pos; i < len - n; i++){
        ans[i] = ans[i + n];
    }
    len -= n;
    ans[len] = '\0';
}

int main(){
    fgets(ans, 600, stdin);
    len = strlen(ans);
    if(ans[len - 1] == '\n'){
        ans[len - 1] = '\0';
        len--;
    }
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int op, pos;
        char str[600];
        memset(str, 0, 600);
        scanf("%d %d %s", &op, &pos, str);
        top++;
        stack[top].op = op;
        stack[top].pos = pos;
        strcpy(stack[top].str, str);
    }
    int op, pos;
    char str[600];
    while(scanf("%d", &op) != EOF){
        if(op == -1) break;
        memset(str, 0, 600);
        if(op == 1){
            scanf("%d %s", &pos, str);
            insert(pos, str);
            top++;
            stack[top].op = 1;
            stack[top].pos = pos;
            strcpy(stack[top].str, str);
        }
        if(op == 2){
            int cnt;
            scanf("%d %d", &pos, &cnt);
            char del[600];
            memset(del, 0, 600);
            delete(pos, cnt, del);
            top++;
            stack[top].op = 2;
            stack[top].pos = pos;
            strcpy(stack[top].str, del);
        }
        if(op == 3){
            if(top < 0) continue;
            if(stack[top].op == 1){
                char dummy[600];
                delete(stack[top].pos, strlen(stack[top].str), dummy);
            }
            if(stack[top].op == 2){
                insert(stack[top].pos, stack[top].str);
            }
            top--;
        }
    }
    printf("%s", ans);
    return 0;
}