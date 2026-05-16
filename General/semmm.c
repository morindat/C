#include <stdio.h>
#include <stdbool.h>

bool premise1(bool p, bool q, bool r) {
    return (p || (q && !r));
}

bool premise2(bool p, bool q, bool r) {
    return (!r || (!q || p));
}

bool conclusion(bool p, bool q) {
    return (q && !p);
}

int main() {
    bool p, q, r;

    printf("Checking the premises...\n");
    for (p = false; p <= true; p++) {
        for (q = false; q <= true; q++) {
            for (r = false; r <= true; r++) {
                if (premise1(p, q, r) && premise2(p, q, r) && !conclusion(p, q)) {
                    printf("The formula does not hold for:\n");
                    printf("p = %s, q = %s, r = %s\n", p ? "true" : "false", q ? "true" : "false", r ? "true" : "false");
                    return 0;
                }
            }
        }
    }
    printf("The formula holds!\n");

    return 0;
}