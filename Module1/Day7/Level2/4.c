#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateStudents(struct Student* students, int size, int K) {
    struct Student* temp = malloc(K * sizeof(struct Student));

    // Store the first K elements in the temporary array
    for (int i = 0; i < K; i++) {
        temp[i] = students[i];
    }

    // Shift the remaining elements by K positions
    for (int i = 0; i < size - K; i++) {
        students[i] = students[i + K];
    }

    // Copy the temporary array back to the original array at the end
    for (int i = 0; i < K; i++) {
        students[size - K + i] = temp[i];
    }

    free(temp);
}

int main() {
    struct Student* students = NULL;
    int size = 0;

    printf("Enter the number of students: ");
    scanf("%d", &size);

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
    int K;
    printf("\nEnter the number of positions to rotate: ");
    scanf("%d", &K);

    if (K > 0 && K < size) {
        rotateStudents(students, size, K);
        printf("\nRotation successful.\n");

        printf("\nAll Students:\n");
        for (int i = 0; i < size; i++) {
            printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
        }
    } else {
        printf("\nInvalid number of positions. Unable to rotate.\n");
    }

    free(students);

    return 0;
}
