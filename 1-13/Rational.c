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

Rational add(Rational r1, Rational r2) {
    Rational result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    simplify(&result);
    return result;
}

Rational subtract(Rational r1, Rational r2) {
    Rational result;
    result.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    simplify(&result);
    return result;
}

void printRational(Rational r) {
    printf("%d/%d\n", r.numerator, r.denominator);
}

int main() {
    Rational r1 = {1, 2};  // 1/2
    Rational r2 = {3, 4};  // 3/4
    printRational(r1);
    printRational(r2);
    
    Rational sum = add(r1, r2);            // Perform addition
    Rational difference = subtract(r1, r2); // Perform subtraction

    printf("Addition: ");
    printRational(sum);
    printf("Subtraction: ");
    printRational(difference);

    return 0;
}
