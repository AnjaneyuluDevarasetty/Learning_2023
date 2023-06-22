#include <stdio.h>

struct Person {
    char name[50];
    int age;
    char Profession[50];
    
};

void swapFields(struct Person* person1, struct Person* person2) {
    // Swap the name fields
    char tempName[50];
    strcpy(tempName, person1->name);
    strcpy(person1->name, person2->name);
    strcpy(person2->name, tempName);

    // Swap the age fields
    int tempAge = person1->age;
    person1->age = person2->age;
    person2->age = tempAge;
    
    char tempProfe[50];
    strcpy(tempProfe, person1->Profession);
    strcpy(person1->Profession, person2->Profession);
    strcpy(person2->Profession, tempProfe);
}

int main() {
    struct Person person1, person2;

    // Input for person1
    printf("Enter name for person1: ");
    scanf("%s", person1.name);
    printf("Enter age for person1: ");
    scanf("%d", &person1.age);
    printf("Enter profession for person1: ");
    scanf("%s", &person1.Profession);

    // Input for person2
    printf("Enter name for person2: ");
    scanf("%s", person2.name);
    printf("Enter age for person2: ");
    scanf("%d", &person2.age);
    printf("Enter profession for person2: ");
    scanf("%s", &person2.Profession);

    // Display the original data
    printf("\nOriginal Data:\n");
    printf("Person1: %s, %d years old, %s\n", person1.name, person1.age, person1.Profession);
    printf("Person2: %s, %d years old, %s \n", person2.name, person2.age, person2.Profession);

    // Swap the fields using pointers
    swapFields(&person1, &person2);

    // Display the updated data
    printf("\nSwapped Data:\n");
    printf("Person1: %s, %d years old, %s\n", person1.name, person1.age, person1.Profession);
    printf("Person2: %s, %d years old, %s\n", person2.name, person2.age, person2.Profession);

    return 0;
}
