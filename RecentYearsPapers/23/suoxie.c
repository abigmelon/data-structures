#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char input[105] = {0};
char output[105] = {0};

int main(){
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    input[len - 1] = '\0';
    len--;
    int start = 0;
    int j = 0;
    for(int i = 0; i < len; i++){
        if(i + 2 < len && input[i + 1] - input[i] == 1 && input[i + 2] - input[i + 1] == 1 && start == 0){
            start = 1;
            output[j++] = input[i];
            continue;
        }
        if(i + 1 < len && input[i + 1] - input[i] == 1 && start == 1){
            continue;
        }
        if(i + 1 < len && input[i + 1] - input[i] != 1 && start == 1){
            start = 0;
            output[j++] = '-';
            output[j++] = input[i];
            continue;
        }
        if(start == 0){
            output[j++] = input[i];
        }
    }
    if(start == 1){
        output[j++] = '-';
        output[j++] = input[len - 1];
    }   //注意边界
    output[j] = '\0';
    printf("%s", output);
    return 0;
}