#include <stdio.h>
#include <stdbool.h>

// Function to evaluate the first premise: r -> (~p || q)
bool premise1(bool p, bool q, bool r) {
    return !r || (!p || q); // Equivalent to r -> (~p || q)
}

// Function to evaluate the second premise: p && ~r
bool premise2(bool p, bool r) {
    return p && !r;
}

// Function to evaluate the conclusion: ~(~r || q)
bool conclusion(bool r, bool q) {
    return !(!r || q); // Equivalent to ~(~r || q)
}

int main() {
    bool p, q, r;

    printf("Checking for invalidity of the argument...\n");

    // Iterate through all possible truth assignments for p, q, and r
    for (p = false; p <= true; p++) {
        for (q = false; q <= true; q++) {
            for (r = false; r <= true; r++) {
                // Check if both premises are true and the conclusion is false
                if (premise1(p, q, r) && premise2(p, r) && !conclusion(r, q)) {
                    printf("Invalid argument found with the following truth assignment:\n");
                    printf("p = %s, q = %s, r = %s\n", p ? "true" : "false", q ? "true" : "false", r ? "true" : "false");
                    return 0; // Exit as soon as we find an invalid case
                }
            }
        }
    }

    printf("The argument is valid.\n");
    return 0;
}