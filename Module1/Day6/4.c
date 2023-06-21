#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display the stored data
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    return 0;
}
