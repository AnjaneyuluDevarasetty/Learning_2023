#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseStringToStruct(const char* inputString, struct Student* student) {
    const char* delimiter = " ";
    char* inputCopy = strdup(inputString); 
    char* token = strtok(inputCopy, delimiter);

    if (token == NULL) {
        free(inputCopy);  
        return;
    }

    student->rollno = atoi(token);
    token = strtok(NULL, delimiter);

    if (token == NULL) {
        free(inputCopy);
        return;
    }

    strncpy(student->name, token, sizeof(student->name) - 1);
    student->name[sizeof(student->name) - 1] = '\0';
    token = strtok(NULL, delimiter);

    if (token == NULL) {
        free(inputCopy);
        return;
    }

    student->marks = atof(token);
    free(inputCopy);  
}

void initializeStruct(struct Student* student) {
    student->rollno = 0;
    strcpy(student->name, "");
    student->marks = 0.0;
}

int main() {
    const char* inputString = "1001 Aron 100.00";

    struct Student* student = (struct Student*)malloc(sizeof(struct Student));

    if (student == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    initializeStruct(student);
    parseStringToStruct(inputString, student);

    printf("Roll No: %d\n", student->rollno);
    printf("Name: %s\n", student->name);
    printf("Marks: %.2f\n", student->marks);

    free(student);
    return 0;
}
