# include <ctype.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

#define STATES 2
#define SYMBOLS 2

int transitions[STATES][SYMBOLS] = {
    {0, 1},
    {1, 1} // accepting state
};

bool validate(char c){
    return (isalnum(c) || c == '#' || c == '$' || c == '*');
}

int getSymbol(char c) {
    if (isdigit(c)) {
        return 1;
    } else {
        return 0;
    }
}

int accept[STATES] = {0, 1};

int main() {
    int state = 0;
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (!validate(c)) {
            printf("Incorrect character\n");
            return 0;
        }

        int symbol = getSymbol(c);
        state = transitions[state][symbol];
    }

    if (accept[state]) {
        printf("Accepted\n");
    } else {
        printf("Not accepted (no digit found)\n");
    }

    return 0;
}