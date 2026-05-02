#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// 运算符栈
char opStack[500];
int opTop = -1;

void opPush(char c) {
    opStack[++opTop] = c;
}

char opPop() {
    return opStack[opTop--];
}

char opPeek() {
    return opStack[opTop];
}

_Bool opEmpty() {
    return opTop == -1;
}

// 数值栈
double numStack[500];
int numTop = -1;

void numPush(double n) {
    numStack[++numTop] = n;
}

double numPop() {
    return numStack[numTop--];
}

_Bool numEmpty() {
    return numTop == -1;
}

// 运算符优先级
int pri(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double cal(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char s[1000];
    fgets(s, 1000, stdin);
    s[strcspn(s, "\n")] = '\0';

    // 中缀转后缀表达式
    char rpnOps[500];       // 后缀表达式中的运算符
    double rpnNums[500];    // 后缀表达式中的操作数
    int rpnTypes[500];      // 0:操作数, 1:运算符
    int rpnCnt = 0;

    // 词法分析并转RPN
    int i = 0;
    while (s[i] != '\0' && s[i] != '=') {
        if (s[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(s[i])) {
            double num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            rpnTypes[rpnCnt] = 0;
            rpnNums[rpnCnt] = num;
            rpnCnt++;
        } else if (s[i] == '(') {
            opPush('(');
            i++;
        } else if (s[i] == ')') {
            while (!opEmpty() && opPeek() != '(') {
                rpnTypes[rpnCnt] = 1;
                rpnOps[rpnCnt] = opPop();
                rpnCnt++;
            }
            if (!opEmpty()) opPop(); // 弹出 '('
            i++;
        } else {
            // + - * /
            while (!opEmpty() && opPeek() != '(' && pri(opPeek()) >= pri(s[i])) {
                rpnTypes[rpnCnt] = 1;
                rpnOps[rpnCnt] = opPop();
                rpnCnt++;
            }
            opPush(s[i]);
            i++;
        }
    }

    while (!opEmpty()) {
        rpnTypes[rpnCnt] = 1;
        rpnOps[rpnCnt] = opPop();
        rpnCnt++;
    }

    // 计算后缀表达式
    for (int j = 0; j < rpnCnt; j++) {
        if (rpnTypes[j] == 0) {
            numPush(rpnNums[j]);
        } else {
            double b = numPop();
            double a = numPop();
            numPush(cal(a, b, rpnOps[j]));
        }
    }

    printf("%.2f\n", numPop());
    return 0;
}
