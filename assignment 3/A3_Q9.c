#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char character;

    
    sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

   
    destinationFile = fopen("destination.txt", "a");
    if (destinationFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    
    while ((character = fgetc(sourceFile)) != EOF) {
        fputc(character, destinationFile);
    }

    
    fclose(sourceFile);
    fclose(destinationFile);

    printf("Contents added successfully!\n");

    return 0;
}
