#include<stdio.h>

int main(){
	
	int x,y;
	double sum=0;
	printf("enter dimensions of the matrix  in the format y,x : ");
	scanf("%d %d",&y,&x);
	int m[y][x];
	
	printf("enter the matrix : \n");
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			scanf("%d",&m[i][j]);
			
		}
	}
	
	printf("the transpose is  : \n");
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			printf("%d ",m[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
