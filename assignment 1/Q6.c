#include <stdio.h>

// Function to compute GCD using Euclidean Algorithm
int gcdEuclidean(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute GCD using Factorization Method
int gcdFactorization(int a, int b) {
    int smaller = (a < b) ? a : b;
    int gcd = 1;

    for (int i = 1; i <= smaller; ++i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int main() {
    int num1, num2;


    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

 
    int gcdEuclid = gcdEuclidean(num1, num2);
    printf("GCD using Euclidean Algorithm: %d\n", gcdEuclid);

 
    int gcdFactor = gcdFactorization(num1, num2);
    printf("GCD using Factorization Method: %d\n", gcdFactor);

    return 0;
}

