#include <stdio.h>

void printDecreasing(int n);
void printSpaces(int n);
void printIncreasing(int n);

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    for (int i = n; i >= 1; i--)
    {
        printIncreasing(i);
        printSpaces((n - i) * 2);
        printDecreasing(i);
        printf("\n");
    }
    
    return 0;
}

void printDecreasing(int n)
{
    for (int i = n; i >= 1; i--)
    {
        printf("%d", i);
    }
}

void printSpaces(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf(" ");
    }
}

void printIncreasing(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", i);
    }
}