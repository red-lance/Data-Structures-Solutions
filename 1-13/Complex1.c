#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex multiply(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int isEqual(Complex c1, Complex c2) {
    return (c1.real == c2.real) && (c1.imag == c2.imag);
}

void printComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

int main() {
    Complex c1, c2;
    printf("Enter real and imaginary part of the first complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);
    printf("Enter real and imaginary part of the second complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);

    Complex product = multiply(c1, c2);
    printf("Product: ");
    printComplex(product);

    if (isEqual(c1, c2)) {
        printf("The two complex numbers are equal.\n");
    } else {
        printf("The two complex numbers are not equal.\n");
    }

    return 0;
}
