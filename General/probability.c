#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int heads = 0, tails = 0;
    int tosses;
    double probability_heads, probability_tails;

    printf("Please enter the number of tosses you want for the experiment: ");
    scanf("%d", &tosses);

    // Seed the random number generator
    srand(time(0)); 

    // Simulate the coin toss experiment
    for (int i = 1; i <= tosses; i++) {
        int toss = rand() % 2; // Generate 0 or 1 randomly
        if (toss == 0) {
            heads++;
        } else {
            tails++;
        }
    }

    // Calculate probabilities
    probability_heads = (double)heads / tosses;
    probability_tails = (double)tails / tosses;

    // Display results
    printf("Number of trials: %d\n", tosses);
    printf("Heads count: %d\n", heads);
    printf("Tails count: %d\n", tails);
    printf("Probability of Heads: %.6f\n", probability_heads);
    printf("Probability of Tails: %.6f\n", probability_tails);

    // Verify uniform probability distribution
    if (probability_heads > 0.49 && probability_heads < 0.51 &&
        probability_tails > 0.49 && probability_tails < 0.51) {
        printf("The coin is unbiased and follows a uniform probability distribution.\n");
    } else {
        printf("The coin may not be unbiased.\n");
    }

    return 0;
}