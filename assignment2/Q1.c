#include<stdio.h>

void sort(){
	
}

int main(){
	int n,t;
	printf("enter array size : ");
	scanf("%d",&n);
	int a[n];
	printf("enter the array : ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for (int i = 0; i < n; i++) { 
        
        
        for (int j = i + 1; j < n; j++) { 
            
             
            if (a[i] < a[j]) { 
                t = a[i]; 
                a[i] = a[j]; 
                a[j] = t; 
            } 
        } 
    } 
	
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	
	return 0;
}
