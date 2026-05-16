// First program
#include <stdio.h>

int main(){
    printf("Hello, World!\n");

// %f for floats

    int a = 10, b = 45, c = 50, d = 2;
    int ans = a * b / c + d;
    printf("The answer is %d.\n", ans);

// Arrays
// Using a for loop to populate the array coz am a cool kid
// for(initialization, condition, increment){} This is the structure of a for loop
    int numbers [10];
    int i;
    for(i = 0; i <= 9; i++){
        numbers[i]= i + 1;
    }
    printf("The Array is:\n");
    for (i = 0; i <= 9; i++){
        printf("%d", numbers[i]);
    }
    printf("\n");
    
// Good code but the problem with this is that, the array elements are outputed as a string. We can go a bit further and make this interesting by adding [] and , after each element

    printf("The array is: [");
    for (i = 0; i <= 9; i++){
        if (i != 0){
            printf(", ");
        }
        printf("%d", numbers[i]);
    }
    printf("]\n");

    return 0;

}

// Variables and data types
// Since C does not have boolean data type it is normally defined as

# define BOOL char
# define FALSE 0
# define TRUE 1