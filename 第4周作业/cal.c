#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct CharStack {
    char * array;
    int capacity;
    int top;
};

struct CharStack * initCharStack() {
    struct CharStack * stack = malloc(sizeof(struct CharStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->array = malloc(sizeof(char) * 10);
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    stack->capacity = 10;
    stack->top = -1;
    return stack;
}

_Bool pushCharStack(struct CharStack * stack, char element){
    if(stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        char * newArray = realloc(stack->array, newCapacity * sizeof(char));
        if(newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->top++;
    stack->array[stack->top] = element;
    return 1;
}

char popCharStack(struct CharStack * stack) {
    return stack->array[stack->top--];
}

_Bool isEmptyCharStack(struct CharStack * stack) {
    return stack->top == -1;
}

char peekCharStack(struct CharStack * stack) {
    return stack->array[stack->top];
}

// zifu

struct DoubleStack {
    double * array;
    int capacity;
    int top;
};

struct DoubleStack * initDoubleStack() {
    struct DoubleStack * stack = malloc(sizeof(struct DoubleStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->array = malloc(sizeof(double) * 10);
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    stack->capacity = 10;
    stack->top = -1;
    return stack;
}

_Bool pushDoubleStack(struct DoubleStack * stack, double element){
    if(stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        double * newArray = realloc(stack->array, newCapacity * sizeof(double));
        if(newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->top++;
    stack->array[stack->top] = element;
    return 1;
}

double popDoubleStack(struct DoubleStack * stack) {
    return stack->array[stack->top--];
}

_Bool isEmptyDoubleStack(struct DoubleStack * stack) {
    return stack->top == -1;
}

double peekDoubleStack(struct DoubleStack * stack) {
    return stack->array[stack->top];
}

// zhengshu

typedef enum { TOKEN_NUM, TOKEN_OP } TokenType;

typedef struct {
    TokenType type;
    double num;
    char op;
} Token;

Token postfix[500];
int postfixCount = 0;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// youxianji

void infixToPostfix(const char *expr) {
    struct CharStack *opStack = initCharStack();
    int i = 0;

    while (expr[i] != '\0' && expr[i] != '=') {
        if (isspace(expr[i])) {
            i++;
            continue;
        }
        else if (isdigit(expr[i])){
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            postfix[postfixCount].type = TOKEN_NUM;
            postfix[postfixCount].num = num;
            postfixCount++;
        }
        else if (expr[i] == '(') {
            pushCharStack(opStack, expr[i]);
            i++;
        }
        else if (expr[i] == ')') {
            while (!isEmptyCharStack(opStack) && peekCharStack(opStack) != '(') {
                postfix[postfixCount].type = TOKEN_OP;
                postfix[postfixCount].op = popCharStack(opStack);
                postfixCount++;
            }
            if (!isEmptyCharStack(opStack)) {
                popCharStack(opStack);
            }
            i++;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (!isEmptyCharStack(opStack) &&
                    peekCharStack(opStack) != '(' &&
                    priority(peekCharStack(opStack)) >= priority(expr[i])) {
                postfix[postfixCount].type = TOKEN_OP;
                postfix[postfixCount].op = popCharStack(opStack);
                postfixCount++;
                }
                pushCharStack(opStack, expr[i]);
                i++;
        }
    }

    while (!isEmptyCharStack(opStack)) {
        postfix[postfixCount].type = TOKEN_OP;
        postfix[postfixCount].op = popCharStack(opStack);
        postfixCount++;
    }

    free(opStack->array);
    free(opStack);
}

double evaluatePostfix() {
    struct DoubleStack *valStack = initDoubleStack();

    for (int i = 0; i < postfixCount; i++) {
        if (postfix[i].type == TOKEN_NUM) {
            pushDoubleStack(valStack, postfix[i].num);
        } else {
            double b = popDoubleStack(valStack);
            double a = popDoubleStack(valStack);
            double result;
            switch (postfix[i].op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            pushDoubleStack(valStack, result);
        }
    }

    double finalResult = popDoubleStack(valStack);
    free(valStack->array);
    free(valStack);
    return finalResult;
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);
    infixToPostfix(expr);
    double result = evaluatePostfix();
    printf("%.2f\n", result);
    return 0;
}
