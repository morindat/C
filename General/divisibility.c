# include <stdio.h>

int main() {
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num % 5 == 0 && num % 13 == 0){
        printf("The number %d is divisible by both 5 and 13", num);
    }
    else if (num % 5 == 0){
        printf("The number %d is divisible by 5", num);
    }
    else if (num % 13 == 0){
        printf("The number %d is divisible by 13", num);
    }
    else{
        printf("The number %d is not divisible by 5 or 13", num);
    }

    return 0;
}