#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

//function to multiply matrix and vector

void multiplyMatrixVector(int n, double matrix[][n], double vector[n], double result[n]) {
    
    for (int i = 0; i < n; ++i) {
        result[i] = 0.0;
        for (int j = 0; j < n; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}



//function to perform matrix exponentiation (calculate M^p)

void matrixExpo(int n, int p, double m[][n]){
	double sum=0;
	double r[n][n];
	double tmp[n][n];
	for(int i =0;i<n;i++){
		for(int j=0;j<n;j++){
			r[i][j]=m[i][j];
		}
	}
	
	for(int a=0;a<p-1;a++){
		for(int b=0;b<n;b++){//column
			for(int c=0;c<n;c++){//row
				for(int k=0;k<n;k++){
					sum+= r[b][k] * m[k][c];
				}
				
				tmp[b][c] = sum;
				sum=0;
			}
		}
		
		for(int b=0;b<n;b++){
			for(int d=0;d<n;d++){
				r[b][d] = tmp[b][d];
			}
		}
	}
	
	for(int i =0;i<n;i++){
		for(int j=0;j<n;j++){
			m[i][j]=r[i][j];
		}
	}

}

//function to generate random matrix with each row summing to 1
void generateMatrix(int n, double matrix[][n]){
	
	int i,j;
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
        double rowSum = 0;

        // Generate random integers for each element in the row
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 2001 - 1000; // Generates random integers between -100 and 100
            rowSum += matrix[i][j];
        }

        // Normalize the row so that the sum is 1
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = matrix[i][j] * 1.0 / rowSum;
        }
    }
}

//function to compute R = M^p * R
void computeR(int n, double matrix[][n], double R[]){
	int i,j,k;
	double result[n];
	
	for (i = 0; i < n; ++i) {
        	result[i] = 0.0;
    	}
	
}



//function to print the matrix
void printMatrix(int n, double m[][n]){
	for(int i =0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%f\t",m[i][j]);
			
		}
		printf("\n");
	}
}

//function to print the R vector
void printVector(int n, double vector[]){
	for (int i = 0; i < n; ++i) {
        printf("%f\t", vector[i]);
    }
    printf("\n");
}


int main(){
	int n;
	printf("please enter the dimensions of the matrix : ");
	scanf("%d",&n);
	double m[n][n];
	double R[n];
	double result[n];
	 for (int i = 0; i < n; ++i) {
        	R[i] = 1.0 / n;
    	}
    	
	generateMatrix(n,m);
	matrixExpo(n,2,m);
	
	
	
	multiplyMatrixVector(n,m,R,result);
	
	printf("your matrix is : \n");
	printMatrix(n,m);
	
	printf("the resultant vector is : \n");
	printVector(n,result);
	return 0;
}
