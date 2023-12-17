#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    float marks;
    char dob[12];
};

void addRecord(FILE *file) {
    struct Student newStudent;
    printf("Enter name: ");
    scanf("%s", newStudent.name);
    printf("Enter roll number: ");
    scanf("%d", &newStudent.roll);
    printf("Enter marks: ");
    scanf("%f", &newStudent.marks);
    printf("Enter date of birth (YYYY-MM-DD): ");
    scanf("%s", newStudent.dob);
    fwrite(&newStudent, sizeof(struct Student), 1, file);
    printf("Record added successfully!\n");
}

void deleteRecord(FILE *file, int rollToDelete) {
    FILE *tempFile = fopen("tempfile.dat", "wb");
    struct Student currentStudent;
    while (fread(&currentStudent, sizeof(struct Student), 1, file) == 1) {
        if (currentStudent.roll != rollToDelete) {
            fwrite(&currentStudent, sizeof(struct Student), 1, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove("studentinfo.dat");
    rename("tempfile.dat", "studentinfo.dat");
    printf("Record with roll number %d deleted successfully!\n", rollToDelete);
}

void modifyMarks(FILE *file) {
    FILE *tempFile = fopen("tempfile.dat", "wb");
    struct Student currentStudent;
    while (fread(&currentStudent, sizeof(struct Student), 1, file) == 1) {
        if (currentStudent.marks > 40 && currentStudent.marks < 50) {
            currentStudent.marks += 10;
        }
        fwrite(&currentStudent, sizeof(struct Student), 1, tempFile);
    }
    fclose(file);
    fclose(tempFile);
    remove("studentinfo.dat");
    rename("tempfile.dat", "studentinfo.dat");
    printf("Marks modified successfully!\n");
}

void readFileContents(const char *fileName) {
    FILE *file = fopen(fileName, "rb");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Student currentStudent;

    printf("\nStudent Information:\n");

    while (fread(&currentStudent, sizeof(struct Student), 1, file) == 1) {
        printf("Name: %s\n", currentStudent.name);
        printf("Roll Number: %d\n", currentStudent.roll);
        printf("Marks: %.2f\n", currentStudent.marks);
        printf("Date of Birth: %s\n\n", currentStudent.dob);
    }

    fclose(file);
}


int main() {
    FILE *file;
    char choice;
    int rollToDelete;
     int exitFlag = 0;

    while (!exitFlag) {
        printf("Menu:\n");
        printf("a) Create/open the file\n");
        printf("b) Add a new record\n");
        printf("c) Delete a record specified by the roll number\n");
        printf("d) Modify the marks of each student by adding grace marks\n");
        printf("f) display all the students\n");
        printf("e) exit\n");

        printf("Enter your choice (a/b/c/d): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                file = fopen("studentinfo.dat", "ab+");
                if (file == NULL) {
                    perror("Error creating/opening file");
                    return 1;
                }
                printf("File created successfully!\n");
                fclose(file);
                break;
            case 'b':
                file = fopen("studentinfo.dat", "ab+");
                if (file == NULL) {
                    perror("Error opening file");
                    return 1;
                }
                addRecord(file);
                fclose(file);
                break;
            case 'c':
                file = fopen("studentinfo.dat", "rb");
                if (file == NULL) {
                    perror("Error opening file");
                    return 1;
                }
                printf("Enter the roll number to delete: ");
                scanf("%d", &rollToDelete);
                deleteRecord(file, rollToDelete);
                break;
            case 'd':
                file = fopen("studentinfo.dat", "rb+");
                if (file == NULL) {
                    perror("Error opening file");
                    return 1;
                }
                modifyMarks(file);
                
                break;
            case 'f':
                    
                    readFileContents("studentinfo.dat");
                    break;
            case 'e':
                    exitFlag = 1;
                    printf("Exiting the program.\n");
                    break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
