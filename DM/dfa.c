#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define STATES 2
#define SYMBOLS 2

int transition[STATES][SYMBOLS] = {
    {0, 1},  // q0: non-digit → q0, digit → q1
    {1, 1}   // q1 (accepting): stay regardless
};

int accept[STATES] = {0, 1};  // only q1 accepts

int getSymbol(char c) {
    if (isdigit(c))
        return 1;   // digit
    else
        return 0;   // non-digit (but must be allowed char!)
}

bool isValidChar(char c) {
    // Check if character is in the allowed alphabet
    return (isalnum(c) || c == '$' || c == '*' || c == '#');
}

int main() {
    char str[100];
    int state = 0;

    printf("Enter string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        
        // Check if character is allowed
        if (!isValidChar(c)) {
            printf("Invalid character '%c' at position %d\n", c, i);
            return 0;
        }
        
        // Get symbol category and transition
        int symbol = getSymbol(c);
        state = transition[state][symbol];
    }

    if (accept[state]) {
        printf("Accepted\n");
    } else {
        printf("Not accepted (no digit found)\n");
    }

    return 0;
}