# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(){
    int n, x = 0, y = 0;

    printf("Enter the number of steps: ");
    scanf("%d", &n);

    srand(time(0));

    for(int i = 0; i < n; i++){
        int move = rand() % 2;
        if(move == 0){
            x++;
        }
        else{
            y++;
        }
    }

    printf("The final position after %d steps is: (%d, %d).", n, x, y);


    return 0;
}