#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(){
	printf("enter the array size :  ");
	int n;
	
	scanf("%d",&n);
	if(n%2!=0){
		printf("cannot be odd number!");
		exit(0);
	}
	int arr[n];
	
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n;i++){
		if(i%2==0){
			int temp = arr[i+1];
			arr[i+1] = arr[i];
			arr[i] = temp;
		}
	}
	
	
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
