#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
    char name[100];
    int roll;
    int marks1;
    int marks2;
    int marks3;
    int marks4;
    int marks5;
    float avg;
    int total;

};

int main(void){
    FILE* fptr = fopen("A3_Q1Data.txt","r");
    struct student students[1000];
    int bufferSize = 100;
    char buffer[bufferSize];
    int i=0;
    while(fgets(buffer, bufferSize, fptr)) {
        char* token = strtok(buffer,"|");
        int j=0;
        int sum = 0;
        while(token!=NULL){
            if(j==0){
                strcpy(students[i].name,token);
            }
            else if(j==1){
                students[i].roll = atoi(token);
            }
            else if(j==2){
                students[i].marks1 = atoi(token);
                sum+=students[i].marks1;
            }
            else if(j==3){
                students[i].marks2 = atoi(token);
                sum+=students[i].marks2;
            }
            else if(j==4){
                students[i].marks3 = atoi(token);
                sum+=students[i].marks3;
            }
            else if(j==5){
                students[i].marks4 = atoi(token);
                sum+=students[i].marks4;
            }
            else if(j==6){
                students[i].marks5 = atoi(token);
                sum+=students[i].marks5;
            }
            //printf("%s \n",token);
            token = strtok(NULL,"|");
            j++;
        }
        students[i].avg = sum/5;
        students[i].total = sum;
        i++;
}

int rows = i;


 for (int i = 0; i < rows; i++) {     
        for (int j = i+1; j < rows; j++) {     
           if(students[i].total < students[j].total) {    
               struct student temp = students[i];    
               students[i] = students[j];    
               students[j] = temp;    
           }     
        }  
 }

 for(int i=0;i<rows;i++){
    printf("name : %s\n roll : %d"
         "\n marks : %d\n marks : %d\n marks : %d\n marks : %d\n marks : %d\n"
         ,students[i].name,students[i].roll,students[i].marks1,students[i].marks2,
         students[i].marks3,students[i].marks4,students[i].marks5);

    printf("avg of this student is : %f\n and total is : %d\n",students[i].avg,students[i].total);
}   


fclose(fptr);
return 0;
}
