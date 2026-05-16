#include <stdio.h>

int main() {
    int A, B;
    int notB, A_and_notB, A_and_B, not_A_and_B, B_or_not_A_and_B, expression;

    printf("A B | !B | A ^ !B | A ^ B | !(A ^ B) | B || !(A ^ B) | (A ^ !B) -> (B || !(A ^ B))\n");
    printf("----------------------------------------------------------------------------\n");

    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            notB = !B;
            A_and_notB = A && notB;
            A_and_B = A && B;
            not_A_and_B = !A_and_B;
            B_or_not_A_and_B = B || not_A_and_B;
            expression = !A_and_notB || B_or_not_A_and_B;

            printf("%d %d |  %d  |    %d    |   %d    | %d   |     %d    |            %d\n",
                   A, B, notB, A_and_notB, A_and_B, not_A_and_B, B_or_not_A_and_B, expression);
        }
    }

    return 0;
}
