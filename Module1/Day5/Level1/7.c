// program to convert a string to integer.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "5278";
    int i = 0;
    int value = 0;

    while (str[i]) {
        if (isdigit(str[i])) {
            value = value * 10 + (str[i] - '0');
        }
        i++;
    }

    printf("String: %s\n", str);
    printf("Integer: %d\n", value);

    return 0;
}