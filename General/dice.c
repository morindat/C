# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(){
    int tosses;
    int freq[6] = {0};

    printf("Please enter the number of rolls: ");
    scanf("%d", &tosses);

    srand(time(0));

    for(int i = 0; i < tosses; i++){
        int toss = rand() % 6 + 1;
        freq[toss - 1]++;
    }

    printf("\nOutcome\tFrequency\tProbability\n");
    for(int i = 0; i < 6; i++){
        double prob = (double)freq[i]/tosses;
        printf("%d\t%d\t\t%.6lf\n", i + 1, freq[i], prob);
    }
    int even_count = freq[1] + freq[3] + freq[5];
    double even_prob = (double) even_count / tosses;
    double lef = (double)(freq[0] + freq[1] + freq[2] + freq[3]) / tosses;
    int odd_count = freq[0] + freq[2] + freq[4];
    double prob_odd = (double)odd_count / tosses;
    int total_union = even_count + odd_count; 
    double prob_union = (double)total_union / tosses;

    printf("Even probability: %lf\n", even_prob);
    printf("The probability of getting a no. <= to 4 is: %lf\n", lef);
    printf("\nP(A) - Probability of even outcomes (2, 4, 6): %.6f\n", even_prob);
    printf("P(C) - Probability of odd outcomes (1, 3, 5): %.6f\n", prob_odd);
    printf("P(A union C): %.6f\n", prob_union);

// Verifying disjoint
    if (prob_union == even_prob + prob_odd) {
        printf("Events A and C are mutually disjoint (no overlap).\n");
    } else {
        printf("A and C are not disjoint (there's some overlap).\n");
    }

    return 0;
}