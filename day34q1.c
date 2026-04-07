#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(struct Node** top) {
    if (*top == NULL) {
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Check operator
int isOperator(char* token) {
    return (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0);
}

// Evaluate postfix
int evaluate(char* expr) {
    struct Node* stack = NULL;

    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (!isOperator(token)) {
            push(&stack, atoi(token));
        } else {
            int b = pop(&stack);
            int a = pop(&stack);

            if (strcmp(token, "+") == 0)
                push(&stack, a + b);
            else if (strcmp(token, "-") == 0)
                push(&stack, a - b);
            else if (strcmp(token, "*") == 0)
                push(&stack, a * b);
            else if (strcmp(token, "/") == 0)
                push(&stack, a / b);
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expr[1000];

    // Read full line input
    fgets(expr, sizeof(expr), stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluate(expr);

    printf("%d", result);

    return 0;
}