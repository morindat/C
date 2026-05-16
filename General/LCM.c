# include <stdio.h>
# include <stdlib.h>

int main (){

    int a, b, c, LCM, GCD, og_a, og_b;
    
    printf("Please enter the first number you need LCM for: ");
    scanf("%d", &a);

    printf("Please enter the second number you need LCM for: ");
    scanf("%d", &b);

    og_a = a;
    og_b = b;

    if (a == 0){
        printf("The LCM is 0");
        return 0;
    }
    else if (b == 0){
        printf("The LCM is 0");
        return 0;
    }
    else {
        while (b != 0){
            c = a % b; 
            a = b;
            b = c;
        }
        GCD = abs(a);
        LCM = abs(og_a * og_b)/ GCD;
        printf("The LCM of (%d, %d) is: %d", og_a, og_b, LCM);
        printf("\n");
    }

    int num, i, multiple;

    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num == 0 || num == 1){
        printf("Please enter a number greater or equal to 2");
        return 0;
    }
    else{
        printf("The multiples of %d are: [", num);
        for (i = num; i + num <= 200; i += num){
            multiple = num + i;
            printf("%d", multiple);
            if (multiple + num < 200){
                printf(", ");
            }
        }
        printf("]");
    }
    printf("\n");

    int number, x = 0, y = 1, z, v;

    printf("Please enter a number: ");
    scanf("%d", &number);

    if (number == 0){
        printf("The fib of 0 is %d", number);
        return 0;
    }
    else if (number == 1){
        printf("The fib of 1 is %d", number);
    }
    else{
        printf("The fibonnaci series up to %d is: [0, 1", number);
        
        for (v = 2; v <= number; v ++){
            z = x + y;
            x = y;
            y = z;
            printf(", %d", z);
        }
        printf("]\n");
    }

    return 0;
}