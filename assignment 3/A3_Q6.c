//library management system
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE 100
typedef struct lib
{
  int accessionNumber;
    char title[SIZE];  
    char authorName[SIZE];
    float price;
    int isIssued;

}library;

void printBookInfo(library book) {
    printf("Accession Number: %d\n", book.accessionNumber);
    printf("Title: %s\n", book.title);
    printf("Author Name: %s\n", book.authorName);
    printf("Price: %.2f\n", book.price);
    printf("Issued: %s\n", (book.isIssued == 1) ? "Yes" : "No");
}



int main(void)
{
  char choice;
  library L1[1000];
  FILE* fptr = fopen("library.txt","r");
 
    char buffer[SIZE];
    int bookCount=0;
    while(fgets(buffer, SIZE, fptr)) {
        char* token = strtok(buffer,"|");
        int j=0;
        int sum = 0;
        while(token!=NULL){
            if(j==0){
                L1[bookCount].accessionNumber = atoi(token);
            }
            else if(j==1){
                strcpy(L1[bookCount].title,token);
            }
            else if(j==2){
                strcpy(L1[bookCount].authorName,token);
            }
            else if(j==3){
                L1[bookCount].price = atof(token);
                
            }
            else if(j==4){
                L1[bookCount].isIssued = atoi(token);
            }
            
            //printf("%s \n",token);
            token = strtok(NULL,"|");
            j++;
        }
        
        bookCount++;
}

    do {
        printf("\nMenu\n");
        printf("a) Add book information\n");
        printf("b) Display book information\n");
        printf("c) List all books of given author\n");
        printf("d) List the title of specified book\n");
        printf("e) List the count of books in the library\n");
        printf("f) List the books in the order of accession number\n");
        printf("g) Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter Accession Number: ");
                scanf("%d", &L1[bookCount].accessionNumber);

                printf("Enter Title: ");
                scanf(" %[^\n]s", L1[bookCount].title);

                printf("Enter Author Name: ");
                scanf(" %[^\n]s", L1[bookCount].authorName);

                printf("Enter Price: ");
                scanf("%f", &L1[bookCount].price);

                printf("Is the book issued? (1 for Yes, 0 for No): ");
                scanf("%d", &L1[bookCount].isIssued);
                bookCount++;
                break;

            case 'b':
                int num,req=-1;
                printf("enter accession number to search : ");
                scanf("%d",&num);
                for (int i = 0; i < bookCount; i++)
                {
                  if(L1[i].accessionNumber==num){
                    req = i;
                  }
                }
                if(req<0)
                  printf("\nbook not found!");
                else
                  printBookInfo(L1[req]);

                break;

            case 'c':
                char auth[SIZE];
                printf("\n enter the author to search : ");
                scanf(" %[^\n]s",auth);
                for (int i = 0; i < bookCount; i++)
                {
                  if(!strcmp(L1[i].authorName,auth)){
                    printBookInfo(L1[i]);
                  }
                }
                break;

            case 'd':
                int num2,req2=-1;
                printf("enter accession number to search : ");
                scanf("%d",&num2);
                for (int i = 0; i < bookCount; i++)
                {
                  if(L1[i].accessionNumber==num2){
                    req2 = i;
                  }
                }
                if(req2<0)
                  printf("\nbook not found!");
                else
                  printf("Title of the specified book is : %s\n",L1[req2].title);
                break;

            case 'e':
                printf("\n number of books in the library : %d",bookCount);
                break;

            case 'f':
                for (int i = 0; i < bookCount; i++) {     
                  for (int j = i+1; j < bookCount; j++) {     
                    if(L1[i].accessionNumber < L1[j].accessionNumber) {    
                        library temp = L1[i];    
                        L1[i] = L1[j];    
                        L1[j] = temp;    
                    }     
                  }  
                }
                printf("books in the order of accession number are : \n");
                for (int i = 0; i < bookCount; i++)
                {
                  printf("%d|%s\n",L1[i].accessionNumber,L1[i].title);
                }
                break;

            case 'g':
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 'g');

    fclose(fptr);

    //write back to the text files with all the changes

    FILE *file = fopen("library.txt","w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    for (int j = 0; j < bookCount; ++j)
    {
        fprintf(file, "%d|%s|%s|%.2f|%d\n", L1[j].accessionNumber, L1[j].title, L1[j].authorName,L1[j].price,L1[j].isIssued);
    }

    // Close the file
    fclose(file);

  return 0;
}
