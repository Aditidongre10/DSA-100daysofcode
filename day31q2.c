#include <stdio.h>
#include <string.h>

#define MAX 10000

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    if (top == -1) return '#';
    return stack[top--];
}

// Check valid parentheses
int isValid(char *s) {
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // Closing brackets
        else {
            if (top == -1) return 0;

            char t = pop();

            if ((ch == ')' && t != '(') ||
                (ch == '}' && t != '{') ||
                (ch == ']' && t != '[')) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[MAX];
    scanf("%s", s);

    if (isValid(s))
        printf("true");
    else
        printf("false");

    return 0;
}