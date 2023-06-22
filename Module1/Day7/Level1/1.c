#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseAndInitializeStructures(char* input, int size, struct Student* students) {
    char* token;
    int i = 0;
    token = strtok(input, " ");
    
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");
        if (token != NULL) {
            strncpy(students[i].name, token, sizeof(students[i].name) - 1);
            token = strtok(NULL, " ");
            if (token != NULL) {
                students[i].marks = atof(token);
                token = strtok(NULL, " ");
            }
        }
        
        i++;
    }
}

int main() {
    int size;
    char input[100];
    
    printf("Enter the number of structures to create: ");
    scanf("%d", &size);
    while (getchar() != '\n');
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    struct Student* students = malloc(size * sizeof(struct Student));
    parseAndInitializeStructures(input, size, students);
    for (int i = 0; i < size; i++) {
        printf("Structure %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
    free(students);
    
    return 0;
}
