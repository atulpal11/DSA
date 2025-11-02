/* 10. Write a program to check the well form-ness of ( ), [ ], { } parenthesis :- whether 
a given expression is balanced or unbalanced.  */

// ...existing code...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EXPR 1024

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(const char *expr) {
    char stack[MAX_EXPR];
    int top = -1;
    for (size_t i = 0; expr[i] != '\0'; ++i) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            if (top == MAX_EXPR - 1) return false; // overflow (very long input)
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) return false; // no matching opening
            char open = stack[top--];
            if (!matches(open, c)) return false;
        }
    }
    return top == -1;
}

int main(void) {
    char expr[MAX_EXPR];

    printf("Enter expression to check for balanced parentheses:\n");
    if (fgets(expr, sizeof(expr), stdin) == NULL) return 0;

    // remove trailing newline if any
    size_t len = strlen(expr);
    if (len > 0 && expr[len-1] == '\n') expr[len-1] = '\0';

    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not balanced\n");

    return 0;
}
// ...existing code...