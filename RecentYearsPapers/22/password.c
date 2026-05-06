#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char input[55] = {0};
int exist[26] = {0};
char output[55] = {0};

int main(){
    fgets(input, 55, stdin);
    int len = strlen(input);
    input[len - 1] = '\0';
    len--;
    int j = 0;
    for(int i = 0; i < len; i++){
        if (isalpha(input[i]) && exist[tolower(input[i]) - 'a'] == 0){
            exist[tolower(input[i]) - 'a'] = 1;
            output[j++] = input[i];
        } else if (isalpha(input[i]) && exist[tolower(input[i]) - 'a'] == 1){
            continue;
        }
    }
    output[j] = '\0';
    for(int i = 0; i < 26; i++){
        printf("%c", 'a' + i);
    }
    printf("\n");
    printf("%s", output);
    for(int i = 25; i >= 0; i--){
        if(exist[i] == 0){
            printf("%c", 'a' + i);
        }
    }
    return 0;
}