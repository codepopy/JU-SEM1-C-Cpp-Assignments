#include<stdio.h>

struct time
{
    int hrs;
    int min;
    int sec;

};

struct time add(struct time t1, struct time t2){
    struct time res;
    res.sec = (t1.sec + t2.sec)%60;
    res.min = ((t1.min+t2.min) + (res.sec)/60)%60;
    res.hrs = ((t1.hrs+t2.hrs)+(res.min)/60)%24;
    
    

    return res;
}


int main(void){
    struct time t1, t2;
    printf("please enter time 1 in the format HH:MM:SS : \n");
    scanf("%d:%d:%d",&t1.hrs,&t1.min,&t1.sec);

    printf("please enter time 2 in the format HH:MM:SS : \n");
    scanf("%d:%d:%d",&t2.hrs,&t2.min,&t2.sec);

    struct time res = add(t1,t2);
    printf("sum of the times is : %d:%d:%d\n",res.hrs,res.min,res.sec);
    return 0;
}