#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringToStruct(const char* inputString, struct Student* students, int size) {
    const char* delimiter = " ";
    char* inputCopy = strdup(inputString);
    char* token = strtok(inputCopy, delimiter);

    for (int i = 0; i < size; ++i) {
        if (token == NULL)
            break;

        students[i].rollno = atoi(token);
        token = strtok(NULL, delimiter);

        if (token == NULL)
            break;

        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        token = strtok(NULL, delimiter);

        if (token == NULL)
            break;

        students[i].marks = atof(token);
        token = strtok(NULL, delimiter);
    }

    free(inputCopy); 
}

void displayStructArray(const struct Student* students, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    const char* inputString = "1001 Aron 100.00";
    int size = 1; 

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    parseStringToStruct(inputString, students, size);

    displayStructArray(students, size);

    free(students);
    return 0;
}
