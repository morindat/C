# include <stdio.h>

void myfun (){
    int x = 5;
    int y = 10;
    int sum = x + y;
    printf("%d + %d = %d\n", x, y, sum);
}

void greetings(char name[], int age){
    printf("Hello, %s you are %d years old.\n", name, age);
}

void sum(int x, int y){
    int sumo = x + y;
    printf("%d + %d = %d\n", x, y, sumo);
}

int main(){
    myfun();
    greetings("Liam", 12);
    greetings("John", 18);
    greetings("Justin", 21);
    sum(4, 5);
    sum(90, 1200);

    return 0;
}