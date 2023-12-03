#include <stdio.h>

// Function to compute GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Function to compute LCM of an array of integers
int findLCM(int arr[], int n) {
    int result = arr[0];
    
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }

    return result;
}

int main() {
    int n;

    // Input the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];

    // Input the integers
    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Calculate and print the LCM
    int result = findLCM(arr, n);
    printf("LCM: %d\n", result);

    return 0;
}

