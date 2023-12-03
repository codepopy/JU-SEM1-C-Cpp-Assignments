//In a banking system, there are the following denomination of notes: Rs. 10, Rs. 20. Rs. 50. Rs. 100.
//Write a program that will accept an amount and find the minimum number of each note required to
//pay the amount.

#include<stdio.h>

int main(){
	int amount;
	printf("enter the amount you  wish to withdrawl only denominations available are (10,20,50,100)  : ");
	scanf("%d",&amount);
	int ar[4] = {100,50,20,10};
	int count=0;
	for(int i=0;i<4;i++){
		
		if(amount/ar[i]>0){
			count= count + (amount/ar[i]);
			amount= amount%ar[i];
		}
	}
	if(amount==0){
		printf("the min number of notes is : %d",count);
	}
	else{
		printf("not valid amount! only denominations available are (10,20,50,100)");
	}
	
	return 0;
}
