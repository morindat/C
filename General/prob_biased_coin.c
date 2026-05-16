# include <stdlib.h>
# include <time.h>
# include <stdio.h>

int main(){
    int tosses;
    int heads = 0, tails = 0;
    double prob_head, prob_tail;

    printf("Please enter the number of tosses preferably: ");
    scanf("%d", &tosses);

    srand(time(NULL));

    for(int i = 1; i <= tosses; i++){
        int toss = rand() % 3;
        
        if(toss == 0){
            tails ++;
        }
        else{
            heads ++;
        }
    }

    prob_head = (double)heads/tosses;
    prob_tail = (double)tails/tosses;

    printf("PROBABILITY OF HEADS: %.6lf\n", prob_head);
    printf("THE PROBABILITY OF TAILS: %.6lf\n", prob_tail);

    return 0;
}