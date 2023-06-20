

#include<stdio.h>

// program to find minimum and maximum values of 1-D array.

int main()
{
    int arr[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
    int len = sizeof(arr) / sizeof(arr[0]);
    int min, max= arr[0];

    for(int i= 0; i<len; i++)
    {
        if(arr[i] < min)
        {
            min =arr[i];
        }
        if(arr[i]> max)
        {
            max= arr[i];
        }
    }
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d", max);
    
}