# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(){
    int countA = 0, countB = 0;
    int tosses;

    printf("Please enter the number of tosses: ");
    scanf("%d", &tosses);

    srand(time(NULL));

    for(int i = 0; i < tosses; i++){
        int s = rand() % 4 + 1;
        int t = rand() % 4 + 5;

        if ( abs(s - t) <= 3){
            countA ++;
        }
        if((s + t) % 2 == 1){
            countB ++;
        }
    }

    double pA = (double)countA / tosses;
    double pB = (double)countB / tosses;

    printf("\nP(A): |s - t| <= 3: %.6f\n", pA);
    printf("P(B): s + t = 1 mod 2: %.6f\n", pB);

    return 0;
}