#include <stdio.h>
int main(){
    printf("Hello World!\n");
    printf("Have a good day!\n");

    int mynum = 15;
    printf("%d\n", mynum);

    char myletter = 'D';
    printf("%c\n", myletter);

    float myfloat = 4.99;
    printf("%.2f\n", myfloat);

    int studentID = 1020241748;
    int studentAge = 21;
    float studentfee = 4.99;
    char studentGrade = 'A';

    int height = 12;
    int base = 6;
    int area = 0.5 * height * base;

    printf("The area of the triangle is %d.\n", area);
    printf("%lu\n", sizeof(area));

    printf("The student ID is %d and his grade is %c.\n", studentID, studentGrade);

    int max = 500;
    int score = 493;

    float marks = (float) score/max *100;
    printf("Your score in this test is %.2f\n", marks);

    int x = 21;
    int y = 21;
    if (x>y){
        printf("X is greater than Y.\n");
    }
    else if(x==y){
            printf("X is equal to Y.\n");
        } else{
            printf("X is not greater than Y.\n");
        }

    int i = 0;
    while(i<5){
        printf("%d\n", i);
        i++;
    }

    int z = 0;
    do {
        printf("%d\n", z);
        z++;
    }
    while(z<5);

    int b;
    for (b=0; b<5; b++){
        printf("%d\n", b);
    }

    return 0;
}