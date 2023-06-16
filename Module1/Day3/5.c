#include <stdio.h>
#include <stdarg.h>

void findSmallestAndLargestDigits(int num, int index);

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    // Read the numbers from the user
    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Process each number individually
    for (int i = 0; i < n; i++) {
        findSmallestAndLargestDigits(numbers[i], i + 1);
    }

    return 0;
}

void findSmallestAndLargestDigits(int num, int index) {
    int smallestDigit = 9; // Initialize with largest digit value
    int largestDigit = 0;  // Initialize with smallest digit value

    // Calculate the smallest and largest digits
    int temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        if (digit < smallestDigit) {
            smallestDigit = digit;
        }
        if (digit > largestDigit) {
            largestDigit = digit;
        }
        temp /= 10;
    }
    printf("------------------------\n");
    // Print the result for each number
    if (num < 10) {
        printf("Number %d: Not Valid\n", index);
    } else {
        printf("Number %d: %d\n", index, num);
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
        printf("\n");
    }
}