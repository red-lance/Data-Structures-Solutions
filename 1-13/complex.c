// 2 Write a C/C++ program to implement addition and subtraction of complex numbers using Abstract Data Type(ADT)
#include <stdio.h>
typedef struct {
    float real;
    float imag;
} Complex;

Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex subtract(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

void printComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

int main() {
    Complex c1, c2, sum, difference;
    printf("Enter real and imaginary part of the first complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);
    printf("Enter real and imaginary part of the second complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);
    printf("first complex number entered: ");
    printComplex(c1);
    printf("Second complex number entered: ");
    printComplex(c2);
    sum = add(c1, c2);
    difference = subtract(c1, c2);

    printf("Sum of above complex numbers : ");
    printComplex(sum);
    printf("Difference of above complex numbers : ");
    printComplex(difference);
    return 0;
}
