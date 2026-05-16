#include <stdio.h>

int main() {
    int set[3]; 
    int i, j;

    // Input: Take 3 elements of the set from the user
    printf("Enter 3 elements of the set:\n");
    for (i = 0; i < 3; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &set[i]);
    }

    // Output: Generate and print the power set
    printf("\nThe power set is:\n");

    // Loop through all possible subsets (2^3 = 8 subsets)
    for (i = 0; i < 8; i++) { 
        printf("{ ");
        for (j = 0; j < 3; j++) {
            if (i & (1 << j)) {
                printf("%d ", set[j]);
            }
        }
        printf("}\n");
    }

    return 0;
}