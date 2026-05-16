/*int - stores integers (whole numbers), without decimals, such as 123 or -123
float - stores floating point numbers, with decimals, such as 19.99 or -19.99
char - stores single characters, such as 'a' or 'B'. Characters are surrounded by single quotes*/
#include <stdio.h>
/*int main(){
    int myNum = 15;
    printf(myNum); // This prints nothing. Why?? Coz you need to pass a format specifier
}*/

int main(){
    int myNum;
    myNum = 15;
    printf("%d\n", myNum);

    /*formart specifier for other data types
    1. char--> %c and %f for floats*/

    float myNums = 12.50;
    char myLetter = 'P';
    printf("%f\n", myNums);
    printf("%c\n", myLetter);
    printf("My fav number is %d and letter is %c.\n", myNum, myLetter);

    // Change value of a variable

    char myChar = 'P';
    myChar = 'J';
    printf("Now my char is: %c\n", myChar);

    int x = 3, y = 4, z = 10, sum;
    sum = (x + y + z);
    printf("The sum of the values is: %d\n", sum);

    return 0;
}