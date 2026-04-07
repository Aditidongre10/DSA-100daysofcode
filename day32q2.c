#include <stdio.h>

#define MAX 10000

// Main stack
int stack[MAX];
int top1 = -1;

// Min stack
int minStack[MAX];
int top2 = -1;

// Push
void push(int val) {
    stack[++top1] = val;

    if (top2 == -1 || val <= minStack[top2]) {
        minStack[++top2] = val;
    } else {
        minStack[++top2] = minStack[top2]; // repeat min
    }
}

// Pop
void pop() {
    if (top1 == -1) return;

    top1--;
    top2--;
}

// Top element
int top() {
    return stack[top1];
}

// Get minimum
int getMin() {
    return minStack[top2];
}