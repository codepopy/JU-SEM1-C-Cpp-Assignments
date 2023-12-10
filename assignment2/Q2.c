#include<stdio.h>

int main(){
	
	int n;
	printf("enter array size : ");
	scanf("%d",&n);
	int a[n];
	printf("enter the array : ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int min=a[0],max=a[0];

	for(int i=0;i<n;i++){
		if(min>a[i])min=a[i];
		if(max<a[i])max=a[i];
	}

	printf("max element is : %d, min element is  : %d",max,min);
	return 0;
}
