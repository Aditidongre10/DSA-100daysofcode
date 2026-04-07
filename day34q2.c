#include <stdio.h>
#include <ctype.h>

int calculate(char* s) {
    long num = 0;
    long result = 0;
    long last = 0;
    char op = '+'; // previous operator

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        // Build number
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        // If operator OR end of string
        if ((!isdigit(ch) && ch != ' ') || s[i + 1] == '\0') {

            if (op == '+') {
                result += last;
                last = num;
            }
            else if (op == '-') {
                result += last;
                last = -num;
            }
            else if (op == '*') {
                last = last * num;
            }
            else if (op == '/') {
                last = last / num; // truncates toward 0
            }

            op = ch;
            num = 0;
        }
    }

    result += last;
    return result;
}

int main() {
    char s[300000];
    fgets(s, sizeof(s), stdin);

    printf("%d", calculate(s));
    return 0;
}