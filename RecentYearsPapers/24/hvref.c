#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char input[10001] = {0};
char text[101][101] = {0};
char output[101][101] = {0};

int main(){
    fgets(input, 10001, stdin);
    int len = strlen(input);
    int copy = 0;
    int index = -1;
    int j = 0;
    for(int i = 0; i < len; i++){
        if(input[i] == ',') continue;
        if(input[i] == '('){
            copy = 1;
            index++;
            continue;
        }
        if(input[i] == ')'){
            copy = 0;
            text[index][j] = '\0';
            j = 0;
            continue;
        }
        if(copy == 1){
            text[index][j++] = input[i];
        }
    }
    int output_index = 0;
    for(int i = 0; i <= index; i++){
        int remove = 0;
        for(int j = 0; j < i; j++){
            if(strcmp(text[i], text[j]) == 0){
                remove = 1;
                break;
            }
        }
        if(remove == 0){
            strcpy(output[output_index++], text[i]);
        }
    }
    for(int i = 0; i < output_index; i++){
        printf("%s\n", output[i]);
    }
    return 0;
}