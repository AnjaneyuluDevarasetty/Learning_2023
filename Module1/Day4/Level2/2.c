// Program  to convert binary/octal/hex to decimal.

#include <stdio.h>
#include <math.h>
#include <string.h>

int binaryToDecimal(char *binary) {
    int length = strlen(binary);
    int decimal = 0;
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

int octalToDecimal(char *octal) {
    int length = strlen(octal);
    int decimal = 0;
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * base;
        base *= 8;
    }

    return decimal;
}

int hexadecimalToDecimal(char *hexadecimal) {
    int length = strlen(hexadecimal);
    int decimal = 0;
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - '0') * base;
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}

int main() {
    char number[100];
    int decimal;

    printf("Enter a number: ");
    scanf("%s", number);

    // Determine the base of the input number
    int base = 10;
    if (number[0] == '0' && (number[1] == 'b' || number[1] == 'B')) {
        base = 2;
        memmove(number, number + 2, strlen(number));
    } else if (number[0] == '0') {
        base = 8;
        memmove(number, number + 1, strlen(number));
    } else if ((number[0] == '0' && (number[1] == 'x' || number[1] == 'X'))) {
        base = 16;
        memmove(number, number + 2, strlen(number));
    }

    switch (base) {
        case 2:
            decimal = binaryToDecimal(number);
            break;
        case 8:
            decimal = octalToDecimal(number);
            break;
        case 16:
            decimal = hexadecimalToDecimal(number);
            break;
        default:
            decimal = atoi(number);
            break;
    }

    printf("Decimal: %d\n", decimal);

    return 0;
}