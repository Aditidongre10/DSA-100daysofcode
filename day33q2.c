#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

// Check if operator
int isOperator(char* s) {
    return (strcmp(s, "+") == 0 ||
            strcmp(s, "-") == 0 ||
            strcmp(s, "*") == 0 ||
            strcmp(s, "/") == 0);
}

// Evaluate RPN
int evalRPN(char* tokens[], int n) {
    for (int i = 0; i < n; i++) {
        if (!isOperator(tokens[i])) {
            // Convert string to int and push
            push(atoi(tokens[i]));
        } else {
            int b = pop();
            int a = pop();

            if (strcmp(tokens[i], "+") == 0)
                push(a + b);
            else if (strcmp(tokens[i], "-") == 0)
                push(a - b);
            else if (strcmp(tokens[i], "*") == 0)
                push(a * b);
            else if (strcmp(tokens[i], "/") == 0)
                push(a / b); // truncates toward 0
        }
    }
    return pop();
}