#include <stdio.h>

#define MAX 100

// Stack 1 (input)
int s1[MAX], top1 = -1;

// Stack 2 (output)
int s2[MAX], top2 = -1;

// Push to stack
void pushStack(int stack[], int *top, int x) {
    stack[++(*top)] = x;
}

// Pop from stack
int popStack(int stack[], int *top) {
    return stack[(*top)--];
}

// Check empty
int isEmpty(int top) {
    return top == -1;
}

// Move s1 → s2
void transfer() {
    while (!isEmpty(top1)) {
        pushStack(s2, &top2, popStack(s1, &top1));
    }
}

// Queue push
void push(int x) {
    pushStack(s1, &top1, x);
}

// Queue pop
int pop() {
    if (isEmpty(top2)) {
        transfer();
    }
    return popStack(s2, &top2);
}

// Queue peek
int peek() {
    if (isEmpty(top2)) {
        transfer();
    }
    return s2[top2];
}

// Queue empty
int empty() {
    return isEmpty(top1) && isEmpty(top2);
}