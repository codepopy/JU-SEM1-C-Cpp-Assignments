#include<stdio.h>
#include<math.h>

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
	
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			sum+= (m[i][j] * m[i][j]);
		}
	}
	
	double rt = sqrt(sum);
	
	printf("\nthe normal of the matrix is : %lf",rt);
	return 0;
}
