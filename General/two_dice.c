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
        int s = rand() % 6 + 1;
        int t = rand() % 6 + 1;
        int sum = s + t; 

        if (sum % 2 == 0){
            countA ++;
        }
        else{
            countB ++;
        }
    }

    double pA = (double) countA / tosses;
    double pB = (double) countB / tosses;

    printf("P(A): %lf\n", pA);
    printf("P(B): %lf\n", pB);

    if (pA >= pB){
        printf("Valid\n");
    }
    else{
        printf("Invalid!\n");
    }

    return 0;
}