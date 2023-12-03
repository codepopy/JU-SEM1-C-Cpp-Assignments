//In a hotel, a professor lives in a room no. X. The room number are sequentially numbered from 1
//to n (n can be any integer). The sum of the room numbers left to X is equal to the sum of the room
//numbers to the right of X. Write a program to find X.


//possible values to check the solution
//  n x
//	1 1
//	8 6      
//	49 35    
//	288 204  
//	1681 1189
//	9800 6930
//	57121 40391
//	332928 235416
//	1940449 1372105
//	11309768 7997214
//	65918161 46611179

#include<stdio.h>

long long sum(long long n){
	return n * (n+1)/2;
}

int main(){
	int n;
	int flag=1;
	printf("enter total number of rooms : ");
	scanf("%d", &n);
	int i =n-1;
	while(i>0){
		if(sum(i-1)==sum(n)-sum(i)){
			printf("the room number of the professor is : %d",i);
			flag=0;
			break;
		}
		i--;
	}
	if(flag==1){
		printf("no such room number exists");
	}
	return 0;
}
