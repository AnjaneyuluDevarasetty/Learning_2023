#include <stdio.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int rollNumber;
    float marks;
} Student;

void readStudents(Student students[], int n) {
    printf("Enter details of students:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void writeStudents(Student students[], int n) {
    printf("Details of students:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

float computeAverageMarks(Student students[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += students[i].marks;
    }
    return sum / n;
}

void studentsAboveAndBelowAverage(Student students[], int n) {
    float averageMarks = computeAverageMarks(students, n);
    
    printf("Students scoring above average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > averageMarks) {
            printf("%s (Roll Number: %d, Marks: %.2f)\n", students[i].name, students[i].rollNumber, students[i].marks);
        }
    }
    
    printf("Students scoring below average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < averageMarks) {
            printf("%s (Roll Number: %d, Marks: %.2f)\n", students[i].name, students[i].rollNumber, students[i].marks);
        }
    }
}

int main() {
    int numStudents;
    Student students[MAX_STUDENTS];
    
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students exceeded.\n");
        return 1;
    }
    
    readStudents(students, numStudents);
    
    printf("\n");
    
    writeStudents(students, numStudents);
    
    printf("\n");
    
    float averageMarks = computeAverageMarks(students, numStudents);
    printf("Average marks: %.2f\n", averageMarks);
    
    printf("\n");
    
    studentsAboveAndBelowAverage(students, numStudents);
    
    return 0;
}
