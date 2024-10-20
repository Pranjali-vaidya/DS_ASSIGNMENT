#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50


struct Student {
    int roll_no;
    char name[NAME_LENGTH];
    float marks;
};

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}


void sortStudentsByMarks(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].marks > students[j + 1].marks) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

// Function to print the list of students
void printStudents(struct Student students[], int n) {
    printf("Roll No\tName\t\tMarks\n");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

int main() {
    struct Student students[MAX_STUDENTS] = {
        {1, "Pranjali", 96.5},
        {2, "Saumya", 76.0},
        {3, "Pritambara", 90.0},
        {4, "Harshali", 60.5},
        {5, "Gayatri", 70.0},
        {6, "Ashutosh", 88.0},
        {7, "Shankar", 95.5},
        {8, "Rahul", 82.0},
        {9, "Rudra", 72.0},
        {10, "Harish", 68.5}
    };

    printf("Students before sorting:\n");
    printStudents(students, MAX_STUDENTS);

    
    sortStudentsByMarks(students, MAX_STUDENTS);

    printf("\nStudents after sorting by marks:\n");
    printStudents(students, MAX_STUDENTS);

    return 0;
}
