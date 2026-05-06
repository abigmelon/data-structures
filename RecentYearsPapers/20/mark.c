#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char input[205] = {0};
char output[55][40] = {0};
char ans[55][40] = {0};

int main(){
    fgets(input, 205, stdin);
    int copy = 0;
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }
    int cnt = 0;
    int index = 0;
    for(int i = 0; i < len; i++){
        if(isalpha(input[i]) || input[i] == '_' ){
            if(copy == 0){
                copy = 1;
                output[cnt][index++] = input[i];
            }
            else if(copy == 1){
                output[cnt][index++] = input[i];
            }
        } else if (isdigit(input[i])) {
            if (copy == 0) continue;
            else if (copy == 1) {
                output[cnt][index++] = input[i];
            }
        } else {
            if (copy == 1) {
                output[cnt][index] = '\0';
                cnt++;
                index = 0;
            }
            copy = 0;
        }
    }
    if (copy == 1) {
        output[cnt][index] = '\0';
        cnt++;
    }
    int n = 0;
    for(int i = 0; i < cnt; i++){
        int appear = 0;
        for(int j = 0; j < i; j++){
            if(strcmp(output[i], output[j]) == 0){
                appear = 1;
                break;
            }
        }
        if(appear == 0){
            strcpy(ans[n++], output[i]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(strcmp(ans[j], ans[j + 1]) > 0){
                char tmp[40] = {0};
                strcpy(tmp, ans[j]);
                strcpy(ans[j], ans[j + 1]);
                strcpy(ans[j + 1], tmp);
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s ", ans[i]);
    }
    return 0;
}