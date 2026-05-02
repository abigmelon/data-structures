//
// Created by 63092 on 2026/4/14.
//
// 改进版：修复容量不一致问题，添加动态扩容机制

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef int E;

struct Stack {
    E *array;      // 数组
    int capacity;  // 当前容量
    int top;       // top表示当前栈顶位置，存的是栈顶元素的下标
};

typedef struct Stack * ArrayStack; // 起个别名

#define INIT_CAPACITY 10

_Bool initStack(ArrayStack stack) {
    stack->array = malloc(sizeof(E) * INIT_CAPACITY);
    if (stack->array == NULL) {
        return 0;
    }
    stack->capacity = INIT_CAPACITY;
    stack->top = -1;
    return 1;
}

_Bool pushStack(ArrayStack stack, E element) {
    // 检查栈是否已满，若已满则动态扩容为原来的2倍
    if (stack->top + 1 >= stack->capacity) {
        int newCapacity = stack->capacity * 2;
        E *newArray = realloc(stack->array, sizeof(E) * newCapacity);
        if (newArray == NULL) {
            return 0; // 扩容失败
        }
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->top++;
    stack->array[stack->top] = element;
    return 1;
}

_Bool isEmpty(ArrayStack stack) {
    return stack->top == -1;
}

E popStack(ArrayStack stack) {
    return stack->array[stack->top--];
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); // 设置控制台为UTF-8编码，防止中文路径乱码
#endif
    struct Stack stack;
    if (!initStack(&stack)) {
        printf("init failed!\n");
        return 1;
    }
    int op, num;
    while (scanf("%d", &op) != EOF) {
        if (op == -1) break;
        switch (op) {
            case 1: // 入栈
                scanf("%d", &num);
                if (!pushStack(&stack, num)) {
                    printf("push failed ");
                }
                break;
            case 0: // 出栈
                if (isEmpty(&stack)) {
                    printf("error ");
                } else {
                    printf("%d ", popStack(&stack));
                }
                break;
            default:
                printf("invalid ");
        }
    }
    // 释放动态分配的内存
    free(stack.array);
    return 0;
}
