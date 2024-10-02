// 3 Write a C/C++ program to implement multiplication and equality check of rational numbers using Abstract Data Type(ADT).
#include <stdio.h>
typedef struct {
    int numerator;
    int denominator;
} Rational;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void simplify(Rational *r) {
    int divisor = gcd(r->numerator, r->denominator);
    r->numerator /= divisor;
    r->denominator /= divisor;
    // Ensure the denominator is always positive
    if (r->denominator < 0) {
        r->numerator = -r->numerator;
        r->denominator = -r->denominator;
    }
}

Rational multiply(Rational r1, Rational r2) {
    Rational result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    simplify(&result);
    return result;
}
int isEqual(Rational r1, Rational r2) {
    simplify(&r1);
    simplify(&r2);
    return (r1.numerator == r2.numerator) && (r1.denominator == r2.denominator);
}
void printRational(Rational r) {
    printf("%d/%d\n", r.numerator, r.denominator);
}

int main() {
    Rational r1, r2;
    printf("Enter numerator and denominator for the first rational number: ");
    scanf("%d %d", &r1.numerator, &r1.denominator);
    printf("Enter numerator and denominator for the second rational number: ");
    scanf("%d %d", &r2.numerator, &r2.denominator);


    Rational product = multiply(r1, r2);
    printf("Product: ");
    printRational(product);

    if (isEqual(r1, r2)) {
        printf("The two rational numbers are equal.\n");
    } else {
        printf("The two rational numbers are not equal.\n");
    }

    return 0;
}
