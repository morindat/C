# include <stdio.h>
int main(){
    int i;

    for (i=0; i <= 5; i++){
        printf("%d\n", i);
    }

    for (int x = 0; x < 5; x++){
        printf("Yesss!\n");
    }

    // Nested loops
    int y, z;
    for (y = 1; y<=2; y++){
        printf("Outer: %d\n", y);
        for (z = 1; z<=3; z++){
            printf("Inner: %d\n", z);
        }
    }

    // multiplication table in c
    // 1. Enter a number, ask a user to input a number
    // 2. Declare index i, that will be multiplied with the number

    int num = 2;
    int b;

    for(b=1; b<=12; b++){
        printf("%d * %d = %d\n", num, b, num*b);
    }

    // break 
    // Used to jump off a loop. 
    // say you have a loop from 0 to 100, if you want the loop to stop at 50 you can say when x == 50; break

    int a;
    for(a=0; a<15; a++){
        if (a == 10){
            break;
        }
        printf("%d\n", a);
    }

    // continue
    // Loop from the start to the limiting condition and skips it and continue

    int w = 0;
    while(w<=10){
        if(w == 4){
            w++;
            continue;
        }
        printf("%d\n", w);
        w++;
    }

    return 0;
}