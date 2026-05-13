#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char func[100][25] = {0};
int funcCount = 0;

char used[100][10][25];
int usedCount[100] = {0};

char stack[200][25] = {0};
int top = -1;

int findFunc(char* name){
    for(int i = 0; i < funcCount; i++){
        if(strcmp(func[i], name) == 0) return i;
    }
    return -1;
}

_Bool called(int index, char* name){
    for(int i = 0; i < usedCount[index]; i++){
        if(strcmp(used[index][i], name) == 0) return 1;
    }
    return 0;
}

int main(){
    int op;
    while(scanf("%d", &op) != EOF){
        if(op == 8){
            char name[25];
            scanf("%s", name);
            if(top != -1){
                int index = findFunc(stack[top]);
                if(index >= 0 && called(index, name) == 0){
                    strcpy(used[index][usedCount[index]], name);
                    usedCount[index]++;
                }
            }
            if(findFunc(name) == -1){
                strcpy(func[funcCount], name);
                funcCount++;
            }
            top++;
            strcpy(stack[top], name);
        }
        else if(op == 0){
            if(top >= 0) top--;
            if(top < 0) break;
        }
    }
    for (int i = 0; i < funcCount; i++) {
        if (usedCount[i] > 0) {
            printf("%s:", func[i]);
            for (int j = 0; j < usedCount[i]; j++) {
                printf("%s", used[i][j]);
                if (j < usedCount[i] - 1)
                    printf(",");
            }
            printf("\n");
        }
    }
    return 0;
}

