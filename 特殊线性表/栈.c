//
// Created by 63092 on 2026/3/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef int E;

struct Stack {
    E * array;//数组
    int capacity;//最大元素数量
    int top;//top表示当前栈顶位置，存的是栈顶元素的下标
};

typedef struct Stack * ArrayStack;//起个别名

_Bool initStack(ArrayStack stack) {
    stack->array = malloc(sizeof(E) * 10);
    if (stack->array == NULL) {
        return 0;
    }
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}

_Bool pushStack(ArrayStack stack, E element){
    if(stack->top + 1 == stack->capacity) {  //栈顶+1如果等于容量的话，那么说明已经塞满了
        int newCapacity = stack->capacity + (stack->capacity >> 1);   //大体操作和顺序表一致
        E * newArray = realloc(stack->array, newCapacity * sizeof(E));
        if(newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->top++;
    stack->array[stack->top] = element;
    return 1;
}//push进pop出


void printStack(ArrayStack stack){
    printf("| ");
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}

_Bool isEmpty(ArrayStack stack) {
    return stack->top == -1;
}

E popStack(ArrayStack stack) {
    return stack->array[stack->top--];
}

int main(){
    struct Stack stack;
    initStack(&stack);
    for (int i = 0; i < 3; ++i) {
        pushStack(&stack, i*100);
    }
    printStack(&stack);
    while (!isEmpty(&stack)) {
        printf("%d ", popStack(&stack));   //将栈中所有元素依次出栈
    }
}

