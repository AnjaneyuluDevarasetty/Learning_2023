#include <stdio.h>

int main() {
    double x = 0.7;
    
    // Extracting the exponent using bitwise operations
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long bits = *ptr;
    unsigned long long exponent = (bits >> 52) & 0x7FF;

    // Printing the exponent in hexadecimal and binary format
    printf("Exponent (Hex): 0x%llx\n", exponent);
    printf("Exponent (Binary): 0b");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");

    return 0;
}
