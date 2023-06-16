#include <stdio.h>

void printBits(unsigned int num);

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Binary representation: ");
    printBits(num);

    int setBits = 0;
    int notSetBits = 0;
    unsigned int mask = 1 << 31;

    for (int i = 0; i < 32; i++) {
        if (num & mask) {
            setBits++;
        } else {
            notSetBits++;
        }

        mask >>= 1;
    }

    printf("Number of set bits: %d\n", setBits);
    printf("Number of not-set bits: %d\n", notSetBits);

    return 0;
}

void printBits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31;

    for (i = 0; i < 32; i++) {
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }

        mask >>= 1;
    }

    printf("\n");
}