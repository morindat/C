# include <stdio.h>
# include <math.h>

int main(){
    // Checking if a number is a palindrome
    
    int num, rev_num = 0, og_num;

    printf("Please enter a number so check if it's a palindrome: ");
    scanf("%d", &num);

    og_num = num;

    while (num % 10 != 0){
        rev_num = rev_num * 10 + num % 10;
        num /= 10;
    }
    if (og_num == rev_num){
        printf("The number %d is a palindrome!\n", og_num);
    }
    else{
        printf("The number %d is not a palindrome!\n", og_num);
    }

    int i;
    long long number, fact = 1;
    
    printf("Please enter a number to find its factorial: ");
    scanf("%lld", &number);


    if (number < 0){
        printf("Please enter a positive number");
    }
    else if (number <= 1){
        printf("The factorial of %lld is %lld\n", number, number);
    }
    else{
        for (i = 1; i <= number; i++){
            fact *= i;
        }
        printf("The factorial of %d is %lld\n", number, fact);
    }

    int a, is_prime = 1;
    double num2;

    printf("Please enter a number to check if it is a prime: ");
    scanf("%lf", &num2);

    if (num2 <= 0){
        printf("Please enter a positive number!");
    }
    else if (num2 == 1){
        printf("1 is prime");
    }
    else if (num2 == 2){
        printf("2 is prime");
    }
    else {
        for (a = 2; a <= sqrt(num2); a ++){
            if (fmod(num2, a) == 0){
                is_prime = 0;
                break;
            }
        }
        if (is_prime){
            printf("%.0lf is prime", num2);
        }
        else{
            printf("%.0lf is not prime", num2);
        }
    }

    return 0;
}