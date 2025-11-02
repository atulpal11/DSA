/* 8. ​Write a program to perform the following Stack (of size=10) operations: push(): 
20, 15, 61, 36, pop(), peek(), pop(), push(): 12, 53, 14, 30, pop(), pop(), peek(), 
isEmpty(), isFull().  */

#include <stdio.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

int isFull(void) { return top == SIZE - 1; }
int isEmpty(void) { return top == -1; }

int push(int value) {
    if (isFull()) return 0;
    stack[++top] = value;
    return 1;
}

int pop(int *out) {
    if (isEmpty()) return 0;
    *out = stack[top--];
    return 1;
}

int peek(int *out) {
    if (isEmpty()) return 0;
    *out = stack[top];
    return 1;
}

void printStack(void) {
    printf("Stack (bottom -> top): ");
    if (isEmpty()) { printf("empty\n"); return; }
    for (int i = 0; i <= top; ++i) printf("%d ", stack[i]);
    printf("\n");
}

int main(void) {
    int val;

    // push: 20, 15, 61, 36
    push(20); printf("push(20)\n"); printStack();
    push(15); printf("push(15)\n"); printStack();
    push(61); printf("push(61)\n"); printStack();
    push(36); printf("push(36)\n"); printStack();

    // pop()
    if (pop(&val)) printf("pop() -> %d\n", val); else printf("pop() -> underflow\n");
    printStack();

    // peek()
    if (peek(&val)) printf("peek() -> %d\n", val); else printf("peek() -> empty\n");
    printStack();

    // pop()
    if (pop(&val)) printf("pop() -> %d\n", val); else printf("pop() -> underflow\n");
    printStack();

    // push: 12, 53, 14, 30
    push(12); printf("push(12)\n"); printStack();
    push(53); printf("push(53)\n"); printStack();
    push(14); printf("push(14)\n"); printStack();
    push(30); printf("push(30)\n"); printStack();

    // pop(), pop()
    if (pop(&val)) printf("pop() -> %d\n", val); else printf("pop() -> underflow\n");
    printStack();
    if (pop(&val)) printf("pop() -> %d\n", val); else printf("pop() -> underflow\n");
    printStack();

    // peek()
    if (peek(&val)) printf("peek() -> %d\n", val); else printf("peek() -> empty\n");
    printStack();

    // isEmpty(), isFull()
    printf("isEmpty() -> %s\n", isEmpty() ? "true" : "false");
    printf("isFull()  -> %s\n", isFull() ? "true" : "false");

    return 0;
}