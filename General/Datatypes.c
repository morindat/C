// The char
# include <stdio.h>
int main(){
    char myLetter = 'A';
    printf("%c\n", myLetter);

    // You can also use ASCII table to print characters

    char a = 65, b = 66, c = 67;
    printf("%c %c %c \n", a, b, c);

    // If you enter more than 1 char then it only prints the last char

    char word = 'Hello'; // Prints o
    printf("%c", word);
    printf("\n");

    // To print all characters we use strings which we will learn later in this topic!!
    
    char greeting[] = "GOODMORNING"; // since this is a string it has to have double " " for char use single ''
    printf("%s\n", greeting);

    // Decimal precision: we can choose how many decimal we want to see in our calculations

    float mynum = 3.5;
    printf("%f\n%.1f\n%.2f\n", mynum, mynum, mynum);

    // Memory size

    int myInt;
    float myNum;
    char myChar;
    double myD;

    printf("%lu\n%lu\n%lu\n%lu\n", sizeof(myInt), sizeof(myNum), sizeof(myChar), sizeof(myD));

    // type convertion
    int num1 = 5;
    int num2 = 2;
    float ans = (float) num1/num2; // without this it will print just 2 coz the two nums are of type int
    printf("%.2f\n", ans);

    // real life example
    // Calculating percentage

    int maxscore = 500;
    int userscore = 473;
    char scorechar = '%';

    float score = ((float) userscore/maxscore) * 100;
    printf("Your score is: %.2f%c\n", score, scorechar);

    // constants
    const MY_BIRTHDAY = 2003;
    printf("%d\n", MY_BIRTHDAY); // Useful practice to name contants by cap letters

    // c operators
    // Logical operators &&-AND ||-OR !-NOT
    // Comparison operators are the normal ones ==, !=, >,<, >=, <= etc
    // Assignement operators +=, -=, *=, /=, %=, ^=: xor, >>= RS, <<= LS, |= OR, &=AND
    int num11 = 120;
    int num22 = 230;
    int sum = num11 + num22;
    int sum2 = sum + 2003;

    printf("The sum of the two numbers: %d\nThe sum of the sum1 and the value: %d\n", sum, sum2);

    return 0;
}