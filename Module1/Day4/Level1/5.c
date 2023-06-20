// Program to find difference between even and odd indexed elements.

#include<stdio.h>

int main()
{
    int arr[]= { 64, 84, 21, 36, 17, 90, 77, 10, 48, 55 };
    int size= sizeof(arr) / sizeof(arr[0]);
    int evenSum=0;
    int oddSum= 0;
    int diff;

    for(int i= 0; i< size; i++)
    {
        if(0 == i % 2)
        {
            evenSum+= arr[i];
        }
        else{
            oddSum+= arr[i];
        }
    }

    if(evenSum > oddSum)
    {
        diff = evenSum - oddSum;
        printf("Difference between even and odd elements is: %d", diff);
    }
    else
    {
        diff = oddSum - evenSum;
        printf("Difference between even and odd elements is: %d", diff);
    }
    return 0;

}