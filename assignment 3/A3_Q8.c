#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    char character;

    inputFile = fopen("lowercase.text", "r");
    outputFile = fopen("uppercase.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    while ((character = fgetc(inputFile)) != EOF) {
        fputc(toupper(character), outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}