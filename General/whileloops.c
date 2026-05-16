// while (condition){code}
# include <stdio.h>

int main(){
    int i = 0;
    while(i <= 5){
        printf("%d\n", i);
        i++;
    }

    // do...while
    int x = 0;
    do{
        printf("%d\n", x);
        x = x + 1;
    }
    while(x<5);

    // NewYear Countdown

    int count_down = 3;
    while (count_down > 0){
        printf("%d\n", count_down);
        count_down--;
    }
    printf("Happy New Year!!");

    return 0;
}