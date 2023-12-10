#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on a 1D array
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to perform bubble sort on a 2D array
void sort2DArray(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bubbleSort(arr[i], cols);
    }
}

// Function to print a 2D array
void print2DArray(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Input the number of rows and columns for the 2D arrays
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int array1[rows][cols], array2[rows][cols], sumArray[rows][cols];

    // Input the elements of the first array
    printf("Enter elements for the first array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array1[i][j]);
        }
    }

    // Input the elements of the second array
    printf("Enter elements for the second array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array2[i][j]);
        }
    }

    // Sort the two arrays
    sort2DArray(array1, rows, cols);
    sort2DArray(array2, rows, cols);

    // Sum the two arrays and store the result in sumArray
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sumArray[i][j] = array1[i][j] + array2[i][j];
        }
    }

    // Sort the sumArray
    sort2DArray(sumArray, rows, cols);

    // Print the sorted arrays
    printf("Sorted first array:\n");
    print2DArray(array1, rows, cols);

    printf("Sorted second array:\n");
    print2DArray(array2, rows, cols);

    printf("Sorted sum array:\n");
    print2DArray(sumArray, rows, cols);

    return 0;
}

