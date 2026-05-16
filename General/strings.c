// C does not have string data type thus we use the char datatype to declare strings and double quotes

#include <stdio.h>
#include<string.h>

int main(){
    char greetings[] = "Hello World!";
    printf("%s\n", greetings);
// You can access the letters in a string like accessing an element from an array
    printf("%c\n", greetings[0]);

// Modifying strings is also the same way
    greetings[0] = 'C';
    printf("%s\n", greetings);

// Looping through a string
    char carName[] = "Volvo";
    int length = sizeof(carName)/sizeof(carName[0]);
    int i;
    for (i=0; i<length; i++){
        printf("%c\n", carName[i]);
    }
// Example
    char name[] = "Justin";
    char message[] = "Good to see you";
    printf("%s, %s!\n", message, name);

// special characters
    char intro[] = "We are the so called \"vikings\" from the north.";
    char say[] = "It\'s a cat!";
    printf("%s\n", intro);
    printf("%s\n", say);

// string functions # include<string.h>
    char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%d\n", strlen(Alphabet)); // Prints the length of the string

    char word1[20] = "Hello ";
    char word2[] = "World!";
    
    strcat(word1, word2);
    printf("%s\n", word1);
    printf("%d\n", sizeof(word1));

    char str1[20] = "King Kunta!";
    char str2[20];

// Copy str1 to str2
    strcpy(str2, str1);
    printf("%s\n", str2);

    char str3[] = "Hello";
    char str4[] = "Hello";
    char str5[] = "Hi";

// Compare str1 and str2, and print the result
    printf("%d\n", strcmp(str3, str4));
    printf("%d\n", strcmp(str3, str5));
    return 0;
}