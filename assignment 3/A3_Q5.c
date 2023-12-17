#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct date
{
    int day;
    int month;
    int year;
}DATE;

int main(void)
{
    DATE a,b;
    while(1){
        printf("\nenter first date(dd/mm/yyyy) : ");
        scanf("%d/%d/%d",&a.day,&a.month,&a.year);
        if(a.day>30 || a.day<1 || a.month>12 || a.month<1 || a.year<1){
            printf("invalid date entered please try again");
        }
        else{
            break;
        }
    }
    
    while(1){
        printf("\nenter second date(dd/mm/yyyy) : ");
        scanf("%d/%d/%d",&b.day,&b.month,&b.year);
        if(b.day>30 || b.day<1 || b.month>12 || b.month<1 || b.year<1){
            printf("invalid date entered please try again");
        }
        else{
            break;
        }
    }
    

    

    if(a.day==b.day && a.month==b.month && a.year==b.year){
        printf("the dates are equal\n");
    }
    else{
        printf("the dates are not equal");
    }
    return 0;
}
