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

void deleteStudent(struct Student** students, int* size) {
    if (*size <= 0) {
        printf("Array is empty. No member to delete.\n");
        return;
    }

    // Reduce the size of the array
    int newSize = (*size) - 1;
    struct Student* newStudents = malloc(newSize * sizeof(struct Student));

    // Copy existing elements (excluding the first member) to the new array
    memcpy(newStudents, (*students) + 1, newSize * sizeof(struct Student));

    // Deallocate memory occupied by the original array
    free(*students);

    // Update the original array pointer and size
    *students = newStudents;
    *size = newSize;
}

int main() {
    struct Student* students = NULL;
    int size = 0;  // Variable to track the number of students entered

    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Allocate memory for the initial array
    students = malloc(size * sizeof(struct Student));

    for (int i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollno);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    char searchName[20];
    printf("\nEnter the name to delete: ");
    scanf("%s", searchName);

    int index = searchByName(students, size, searchName);

    deleteStudent(&students, &size);

    // Print all students after deletion
    printf("\nAll Students:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    // Deallocate memory
    free(students);

    return 0;
}
