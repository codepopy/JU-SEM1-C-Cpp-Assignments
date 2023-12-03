#include <stdio.h>

double power(double base, int exponent) {
    double result = 1.0;

    // If the exponent is negative, invert base and make the exponent positive
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }

    while (exponent > 0) {
        result *= base;
        exponent--;
    }

    return result;
}

int main() {
    double base;
    int exponent;

    // Input the base and exponent
    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    // Calculate and print the result
    double result = power(base, exponent);
    printf("Result: %.6lf\n", result);

    return 0;
}

