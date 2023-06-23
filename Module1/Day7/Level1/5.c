#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchByName(const struct Student* students, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  
}

int main() {
    struct Student students[100];  // Assuming a maximum of 100 students
    int size = 0;  // Variable to track the number of students entered

    printf("Enter the number of students: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i+1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollno);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    char searchName[20];
    printf("\nEnter the name to search: ");
    scanf("%s", searchName);

    int index = searchByName(students, size, searchName);

    if (index != -1) {
        printf("\nStudent found at index %d:\n", index);
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[index].rollno, students[index].name, students[index].marks);
    } else {
        printf("\nStudent not found.\n");
    }

    return 0;
}
