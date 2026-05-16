# include <stdio.h>
# include <math.h>


int main (){
    int og_num, num, i;
    
    printf("Please enter a number: ");
    scanf("%d", &num);

    og_num = num;

    if (num <= 0){
        printf("Please enter a positive integer\n");
    }
    else if (num == 1){
        printf("The factor of %d is: %d\n", num, num);
    }
    else{
        printf ("The factors of %d are: [", og_num);
        for (i = 1; i <= num; i ++){
            if (num % i == 0){
                printf("%d", i);
                if (i != num){
                    printf(", ");
                }
            }
        }
        printf("]");
        printf("\n");
    }


    int number, numberr, rev_number = 0, sum = 0, count = 0;

    printf("Please enter a number: ");
    scanf("%d", &number);

    numberr = number;

    while (number != 0){
        sum += number % 10;
        rev_number = rev_number * 10 + number % 10;
        count += 1;
        number /= 10;
    }
    printf("The sum of the integers in %d is: %d\n", numberr, sum);
    printf("There are %d digits in the number %d\n", count, numberr);
    printf("The reverse of the number %d is: %d\n", numberr, rev_number);

    int numb, og_numb, counter = 0, numbb = 0;

    printf("Please enter a number: ");
    scanf("%d", &numb);

    og_numb = numb;
    
    while(numb != 0){
        counter += 1;
        numb /= 10;
    }
    numb = og_numb;

    while (numb != 0){
        numbb += pow(numb % 10, counter);
        numb /= 10;
    }
    if (numbb == og_numb){
        printf("The number %d is an Armstrong number!", og_numb);
    }
    else{
        printf("The number %d is not an Armstrong number!", og_numb);
    }

    return 0;
}