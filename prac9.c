/* 9. ​Write a program to convert Infix expression A + ( B * C ) / D to Postfix 
expression. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(const char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;
    while (infix[i]) {
        char c = infix[i];

        if (isspace((unsigned char)c)) {
            i++; continue;
        }

        if (isalnum((unsigned char)c)) {
            postfix[j++] = c; // operand (letters/digits)
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') top--; // pop '('
        } else if (isOperator(c)) {
            // handle operator precedence; '^' is right-associative
            while (top >= 0 && isOperator(stack[top]) &&
                  ((precedence(stack[top]) > precedence(c)) ||
                   (precedence(stack[top]) == precedence(c) && c != '^'))) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
        i++;
    }

    while (top >= 0) {
        if (stack[top] != '(' && stack[top] != ')')
            postfix[j++] = stack[top];
        top--;
    }

    postfix[j] = '\0';
}

int main(void) {
    const char *expr = "A + ( B * C ) / D";
    char infix[MAX];
    char postfix[MAX];

    // normalize input: remove spaces so both "A+(B*C)/D" and spaced form work
    int k = 0;
    for (int i = 0; expr[i] && k < MAX-1; ++i)
        if (!isspace((unsigned char)expr[i])) infix[k++] = expr[i];
    infix[k] = '\0';

    infixToPostfix(infix, postfix);
    printf("Infix:    %s\n", expr);
    printf("Postfix:  %s\n", postfix); // expected: ABC*D/+

    return 0;
}