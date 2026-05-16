# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(){
    int n, position = 0;

    printf("Please enter the number of steps: ");
    scanf("%d", &n);

    srand(time(0));

    for(int i = 0; i < n; i++){
        int prob = rand() % 4;
        if (prob == 0){
            position--;
        }
        else{
            position++;
        }
    }

    if (position < 0){
        printf("The walker moved backward by %d steps!", abs(position));
    }
    if(position == 0){
        printf("The walker return to the original position!");
    }
    else{
        printf("The user moved forward by %d steps!", position);
    }

    return 0;
}