// Program to reverse 1-D an array.

#include <stdio.h>

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Swap elements at start and end.
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Moving the pointers towards the center.
        start++;
        end--;
    }
}

int main() {
    int arr[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before reversing: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, size);

    printf("\nReversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}