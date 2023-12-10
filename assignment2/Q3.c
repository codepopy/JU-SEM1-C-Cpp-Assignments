#include<stdio.h>

double getMean(int a[], int n){
	float sum = 0;
	for(int i=0;i<n;i++){
		sum+=a[i];	
	}
	
	return sum/n;
}

int getMode(int a[],int n) {
   int maxValue = 0, maxCount = 0, i, j;

   for (i = 0; i < n; ++i) {
      int count = 0;
      
      for (j = 0; j < n; ++j) {
         if (a[j] == a[i])
         ++count;
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = a[i];
      }
   }

   return maxValue;
}

float getSD(int a[], int n, int mean){
	float sum=0;	
	for(int i=0;i<n;i++){
		sum+= (a[i]-mean)*(a[i]-mean);
	}
	return sum/n;
}

int main(){
	int n;
	printf("enter array size : ");
	scanf("%d",&n);
	int a[n];
	printf("enter the array : ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	double mean = getMean(a,n);
	int mode = getMode(a,n);
	float SD = getSD(a,n,mean);

	printf(" mean : %lf\n mode : %d\n Standard deviation : %lf\n",mean,mode,SD);
	return 0;
}
