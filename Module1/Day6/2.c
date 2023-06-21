#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

Complex readComplex() {
    Complex num;
    printf("Enter the real part: ");
    scanf("%f", &num.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &num.imaginary);
    return num;
}

void writeComplex(Complex num) {
    printf("The complex number is: %.2f + %.2fi\n", num.real, num.imaginary);
}

Complex addComplex(Complex num1, Complex num2) {
    Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

Complex multiplyComplex(Complex num1, Complex num2) {
    Complex product;
    product.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    product.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return product;
}

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    num1 = readComplex();

    printf("Enter the second complex number:\n");
    num2 = readComplex();

    printf("\nPerforming operations:\n");

    writeComplex(num1);
    writeComplex(num2);

    sum = addComplex(num1, num2);
    printf("\nAddition:\n");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("\nMultiplication:\n");
    writeComplex(product);

    return 0;
}
