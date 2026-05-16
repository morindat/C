# include <stdio.h>
# include <stdlib.h>

typedef struct Student {
	char name[30];
	int age;
	int ID;
	char grade;
} Student;


int main() {
    Student s1 = { "Justin", 20, 102024, 'A' };

    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("ID: %d\n", s1.ID);
    printf("Grade: %c\n", s1.grade);

    return 0;
}
