#include <stdio.h>

void multiplyMatrices(int first[][10],
                      int second[][10],
                      int result[][10],
                      int r1, int c1, int r2, int c2) {

   // Initializing elements of matrix mult to 0.
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }

   // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}


int main(){
	
	int row,col;
	
	printf("enter dimension of the matrix y,x : ");
	scanf("%d %d",&row,&col);
	int m[10][10],t[10][10],res[10][10];
	
	printf("enter the matrix : \n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%d",&m[i][j]);
			
		}
	}
	
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			t[j][i] = m[i][j];
		}
	
	}
	printf("transpose is : \n");
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	multiplyMatrices(m,t,res,row,col,col,row);
	
	for(int i=0;i<row;i++){
		for(int j=0;j<row;j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
