// If else statements in C
// if (condition){print statement}
# include <stdio.h>
int main(){
    int x = 10;
    int y = 20;
    if (x > y){
        printf("You won\n");
    }
    else{
        printf("I win\n");
    }

    // Adding an else if condition
    int a = 10;
    int b = 7;

    if(a > b){
        printf("You win\n");
        fflush(stdout);
    }else if(a == b){
        printf("We both win\n");
        fflush(stdout);
    }else{
        printf("I win\n");
        fflush(stdout);
    }

    // short hand if else statement
    // vaiable = (condition)? true: false

    int vote_age = 18;
    (vote_age < 18) ? printf("You are too young to vote") : printf("You can vote!");
    printf("\n");

    return 0;
    }