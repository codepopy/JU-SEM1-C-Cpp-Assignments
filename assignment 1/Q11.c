#include <stdio.h>
#include <math.h>


double calculateFibonacci(int n) {
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;

    return (1 / sqrt(5)) * (pow(phi, n) - pow(psi, n));
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    double result = calculateFibonacci(n);
    printf("The %d-th Fibonacci number is %.0lf\n", n, result);

    return 0;
}

