# include <stdio.h>
# include <string.h>

#define STATES 4
#define SYMBOLS 2

int transition[STATES][SYMBOLS] = {
    {0, 1}, // q0
    {2, 1}, // q1
    {0, 3}, // q2
    {3, 3} // q3 (dead state)
};

int accept[STATES] = {1, 1, 1, 0};

int main() {
    char str[100];
    int state = 0;

    printf("Enter binary string: ");
    scanf("%s",str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            printf ("Invalid Input\n");
        }

        int symbol = str[i] - '0';
        state = transition[state][symbol]; 
    }

    if (accept[state]) {
        printf("String Accepted\n");
    } else {
        printf("Not Accepted\n");
    }

    return 0;
} 