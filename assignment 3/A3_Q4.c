#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 100
#define MAX_ACC 1000

typedef struct accounts
{
    int account_number;
    char name[SIZE];
    double balance;
}acnt;

int find_account(acnt[], int, int );//linear search to find the required account
void print_lowBal(acnt[],int);//print the customers with balance lower than 1000

int main(void)
{
    acnt bnk[MAX_ACC];
    
    FILE *fp = fopen("accounts.txt","r");
     if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    int bufferSize = 100;
    char buffer[bufferSize];
    int i=0;
    while(fgets(buffer, bufferSize, fp)) {
        char* token = strtok(buffer,"|");
        int j=0;
        
        while(token!=NULL){
            if(j==0){
               bnk[i].account_number = atoi(token);
            }
            else if(j==1){
                strcpy(bnk[i].name,token);
            }
            else if(j==2){
                bnk[i].balance = atoi(token);
            }
            
            token = strtok(NULL,"|");
            j++;
        }
        i++;
    }
    int choice=10;
    while(choice!=0){
        
        printf("\n use the following options : \n");
        printf("1-> print low balance customers \n2-> withdraw/deposit \n0-> exit\n");
        scanf("%d",&choice);
        
        if(choice==1){
            print_lowBal(bnk, i);
        }
        else if(choice==2){
            printf("enter the following information :\n account number,amount,code(1 for deposit and 0 for withdrawl)");
            int acno,code;
            double amount;
            scanf("%d,%lf,%d",&acno,&amount,&code);
            int required_index = find_account(bnk,acno,i);
            if(required_index<0){
                printf("\naccount number not registered\n");
                
            }
            if(code==1){
                bnk[required_index].balance += amount;
                printf("current balance is  : %.2f\n",bnk[required_index].balance);
            }
            else if(code==0){
                if(bnk[required_index].balance<amount){
                    printf("not enough funds!\n");
                    
                }
                else{
                    bnk[required_index].balance-=amount;
                    printf("current balance is  : %.2f\n",bnk[required_index].balance);
                }
            }
        }
    }

    fclose(fp);

    FILE *file = fopen("accounts.txt","w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Write back modified data into the file
    for (int j = 0; j < i; ++j)
    {
        fprintf(file, "%d|%s|%.2f\n", bnk[j].account_number, bnk[j].name, bnk[j].balance);
    }

    // Close the file
    fclose(file);
    return 0;
}

int find_account(acnt arr[], int account_number, int size){
    int res = -1;
    for(int i=0;i<size;i++){
        if(arr[i].account_number==account_number){res = i;}
    }
    return res;
}

void print_lowBal(acnt arr[], int size){
    printf("low balance (<1000) customers are : \n");
    for(int i=0;i<size;i++){
        if(arr[i].account_number<5000){printf("account number : %d\t name : %s\n",arr[i].account_number,arr[i].name);}
    }
}