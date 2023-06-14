#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function to swap two values of any type
void swap(void *a, void *b, size_t size) {
    // Allocate temporary memory for swapping
    char *temp = (char *)malloc(size);
    
    // Copy the content of 'a' to temporary memory
    memcpy(temp, a, size);
    
    // Copy the content of 'b' to 'a'
    memcpy(a, b, size);
    
    // Copy the content of temporary memory to 'b'
    memcpy(b, temp, size);
    
    // Free the temporary memory
    free(temp);
}

int main() {
    int num1, num2;
    printf("enter number1:");
    scanf("%d", &num1);
    printf("enter number2:");
    scanf("%d", &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    // Swapping integers
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    double decimal1, decimal2;
    printf("enter decimal1:");
    scanf("%f", &decimal1);
    printf("enter decimal2:");
    scanf("%lf", &decimal2);
    printf("Before swapping: decimal1 = %lf, decimal2 = %lf\n", decimal1, decimal2);
    
    // Swapping doubles
    swap(&decimal1, &decimal2, sizeof(double));
    printf("After swapping: decimal1 = %lf, decimal2 = %lf\n", decimal1, decimal2);
    
    char char1 = 'A', char2 = 'B';
    printf("Before swapping: char1 = %c, char2 = %c\n", char1, char2);
    
    // Swapping characters
    swap(&char1, &char2, sizeof(char));
    printf("After swapping: char1 = %c, char2 = %c\n", char1, char2);
    
    return 0;
}
\