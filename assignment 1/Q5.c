#include <stdio.h>

double power(double base, int exponent) {
    double result = 1.0;

    
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

 
    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);
    printf("Result: %.6lf\n", result);

    return 0;
}

