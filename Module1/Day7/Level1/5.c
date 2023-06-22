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
    struct Student students[] = {
        {1001, "John", 85.5},
        {1002, "Alice", 92.3},
        {1003, "Bob", 78.9},
        {1004, "Sarah", 95.2}
    };
    int size = sizeof(students) / sizeof(students[0]);

    char searchName[20];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    int index = searchByName(students, size, searchName);

    if (index != -1) {
        printf("Student found at index %d:\n", index);
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[index].rollno, students[index].name, students[index].marks);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}
