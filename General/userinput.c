# include<stdio.h>

int main(){
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);

    // Double and Char
    double myNum;
    char vowel;

    printf("Please enter your number: ");
    scanf("%lf", &myNum);

    printf("Please enter your fave vowel: ");
    scanf("\n%c", &vowel);

    printf("Your number is: %.2lf\n", myNum);
    printf("Your favorite vowel is: %c\n", vowel);

    // You can also do it this way
    int num;
    char vow;
    printf("Please enter a number then followed by a vowel: ");
    scanf("%d %c", &num, &vow);

    printf("Your number is: %d\n", num);
    printf("The vowel is: %c\n", vow);

    // taking string inputs
    char firstname[30];
    char lastname[30];
    printf("Please enter your firstname and your lastname: ");
    scanf("%s %s", firstname, lastname);
    printf("Hello %s \n", lastname);

    char tname[30];
    printf("Please enter your team's name: ");
    scanf("%s", tname);
    printf("Your team is %s", tname);


    return 0;
}