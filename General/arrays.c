#include<stdio.h>
int main(){
    int myNum[] = {25, 50, 75, 100};
    printf("%d\n", myNum[0]);

    // changing the values of the array
    myNum[0] = 20;
    printf("%d\n", myNum[0]);

    // Loop through an array
    int i;
    for (i=0; i<4; i++){
        printf("%d\n", myNum[i]);
    }

    // You can also declare an array with the size of it and add values later
    int myArr[5];

    myArr[0] = 12;
    myArr[1] = 21;
    myArr[2] = 24;
    myArr[3] = 45;
    myArr[4] = 11; // My Array

    int x;
    
    printf("The array is: [");
    for(x=0; x<5; x++){
        if (x != 0){
            printf(", ");
        }
        printf("%d", myArr[x]);
    }
    printf("]\n");

    // Geting the size of the array
    // use lu and sizeof

    printf("The size of the array myArr is: %lu\n", sizeof(myArr));

    // Getting the length of the array

    int length = sizeof(myArr)/sizeof(myArr[0]);
    printf("The number of items in the array myArr is: %d\n", length);

    // Making better for loops with the length of the array
    
    int z;
    printf("The array myArr contain the following items: [");

    for(z=0; z<length; z++){
        if(z != 0){
            printf(", ");
        }
        printf("%d", myArr[z]);
    }
    printf("]\n");

    // Real world examples
    // finding the avg age
    // 1. An array of ages
    // 2. decalare avg and sum and set their value to 0
    // 3. declare a variable d and loop throught the array using this variable
    // 4. after each loop add the value of the array to sum
    // 5. avg = sum/length of array
    // 6. print the value
    
    int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};
    float avg, sum = 0;
    int d;

    int len = sizeof(ages)/sizeof(ages[0]);

    for (d=0; d<len; d++){
        sum += ages[d];
    }
    avg = sum/len;
    printf("The average age is: %.2f\n", avg);

    // finding the lowest age
    // 

    int agess[] = {20, 22, 18, 35, 48, 26, 87, 70};
    int lenn = sizeof(agess)/sizeof(agess[0]);

    int lowestage = agess[0];
    int f;

    for(f=0; f < lenn; f++){
        if (lowestage>agess[f]){
            lowestage = agess[f];
        }
    }
    printf("The lowest age is: %d\n", lowestage);


    // Multidimensional arrays in C
    // Declare the name with the number of rows and columns

    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%d\n", matrix[1][2]);

    // changing elements is the same as in one d arrays
    matrix[0][0] = 0;
    printf("%d\n", matrix[0][0]);

    // Looping through a 2D array
    int i, j;
    for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
        printf("%d\n", matrix[i][j]);
        }
    }

    return 0;
}