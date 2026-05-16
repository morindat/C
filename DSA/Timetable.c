#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COURSES 10
#define MAX_NAME_LEN 100
#define TOTAL_SEMESTERS 8

typedef struct {
    int semester_number;
    char season[10]; // "Monsoon" or "Spring"
    char courses[MAX_COURSES][MAX_NAME_LEN];
    int course_count;
} Semester;

Semester timetable[TOTAL_SEMESTERS]; // Global timetable


void initialize_timetable() {
    for (int i = 0; i < TOTAL_SEMESTERS; i++) {
        timetable[i].semester_number = i + 1;
        strcpy(timetable[i].season, (i % 2 == 0) ? "Monsoon" : "Spring");
        timetable[i].course_count = 0;
    }
}


void add_course() {
    int sem;
    char course[MAX_NAME_LEN];

    printf("Enter semester number (1-8): ");
    scanf("%d", &sem);
    getchar(); // clear newline

    if (sem < 1 || sem > 8) {
        printf("Invalid semester number.\n");
        return;
    }

    Semester *s = &timetable[sem - 1];

    if (s->course_count >= MAX_COURSES) {
        printf("Semester is full. Cannot add more courses.\n");
        return;
    }

    printf("Enter course name: ");
    fgets(course, MAX_NAME_LEN, stdin);
    course[strcspn(course, "\n")] = 0; // Remove trailing newline

    strcpy(s->courses[s->course_count++], course);
    printf("Course added to Semester %d (%s).\n", sem, s->season);
}


void display_timetable() {
    for (int i = 0; i < TOTAL_SEMESTERS; i++) {
        Semester s = timetable[i];
        printf("\nSemester %d (%s):\n", s.semester_number, s.season);
        if (s.course_count == 0) {
            printf("  (No courses added yet)\n");
        } else {
            for (int j = 0; j < s.course_count; j++) {
                printf("  - %s\n", s.courses[j]);
            }
        }
    }

    printf("\n** Don't forget to include a Physics and Biology course,\n"
           "   plus 12 credits of CS electives across 4 years. **\n");
}


void menu() {
    int choice;
    do {
        printf("\n--- Course Timetable Menu ---\n");
        printf("1. Add Course\n");
        printf("2. View Timetable\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                add_course();
                break;
            case 2:
                display_timetable();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
}


int main() {
    initialize_timetable();
    menu();
    return 0;
}