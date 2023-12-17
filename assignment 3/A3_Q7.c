#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int **matrix;
    int rows = 0, cols = 0;

    
    inputFile = fopen("matrix.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening the input file");
        return 1;
    }

    // Determine matrix dimensions
    int currentChar;
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == '0' || currentChar == '1') {
            
            if (rows == 0) {
                cols++;
            }
        }else if (currentChar == '\n') {
            rows++;
        }
    }
    printf("no of rows is : %d",rows);
    // read from the beginning
    rewind(inputFile);

    
    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(inputFile, "%1d", &matrix[i][j]);
        }
        // Consume the newline character
        fgetc(inputFile);
    }

    
    fclose(inputFile);

    
    outputFile = fopen("matrix_output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening the output file");
        return 1;
    }

    
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        fprintf(outputFile, "Row %d: %d\n", i + 1, rowSum);
    }

    
    fclose(outputFile);

    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
