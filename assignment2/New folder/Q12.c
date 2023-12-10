#include <stdio.h>

void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int n) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input the order of the square matrices
    printf("Enter the order of the square matrices: ");
    scanf("%d", &n);

    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];

    // Input elements for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Multiply the matrices
    multiplyMatrices(firstMatrix, secondMatrix, result, n);

    // Display the matrices
    printf("\nFirst Matrix:\n");
    displayMatrix(firstMatrix, n);

    printf("\nSecond Matrix:\n");
    displayMatrix(secondMatrix, n);

    printf("\nResultant Matrix (Multiplication):\n");
    displayMatrix(result, n);

    return 0;
}

