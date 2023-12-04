#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI (22/7)

long long fact(long long a){
	if(a==0)
		return 1;
	return a*fact(a-1);
}

double calculateFactSeries(){
	double res=0;
	for(int i=1;i<=10;i++){
		res+= i/fact(i);
	}
	return res;
}

 double calculateSine( double x, int n) {
     double sine = 0.0;
    for (int i = 0; i < n; i++) {
        sine += pow(-1, i) * pow(x, 2 * i + 1) / fact(2 * i + 1);
    }
    return sine;
}

double calculateCosine(double x, int n) {
    double cosine = 0.0;
    for (int i = 0; i < n; i++) {
        cosine += pow(-1, i) * pow(x, 2 * i) / fact(2 * i);
    }
    return cosine;
}

double calculateLogSeries(double x, int n) {
    double result = 0.0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            result -=  pow(x, i) / i;
        }
        else{
        	result +=  pow(x, i) / i;
		}
    }
    return result;
}




int main(){
	
	while(1){
	
	int choice;
	printf("choose the option below to print the series : \n 1. (1/1!)+ (2/2!) + (3/3!).... 10 terms\n 2. Sine series\n 3. Cosine series\n 4.Log(1+x) series\n");
	scanf("%d",&choice);
	
	double angle,result,x;
	int terms;
	switch(choice){
		case 1: printf("the value of the series is : %lf\n",calculateFactSeries());
				break;
		case 2:
				printf("Enter the angle in degrees: ");
			    scanf("%lf", &angle);
			    x = angle * PI / 180.0;
			    printf("Enter the number of terms in the series: ");
			    scanf("%d", &terms);
			    result = calculateSine(x, terms);
			    printf("The sine of %.2lf degrees is %.6lf\n", angle, result);
			    break;
			    
		case 3:
				printf("Enter the angle in degrees: ");
			    scanf("%lf", &angle);
			    x = angle * PI / 180.0;
			    printf("Enter the number of terms in the series: ");
			    scanf("%d", &terms);
			    result = calculateCosine(x, terms);
			    printf("The cosine of %.2lf degrees is %.6lf\n", angle, result);
			    break;
		
		case 4: printf("Enter the value of x: ");
			    scanf("%lf", &x);
			    
			    printf("Enter the number of terms in the series: ");
			    scanf("%d", &terms);
			
			    double result = calculateLogSeries(x, terms);
			    printf("The natural logof %.2lf is approximately %.6lf\n", x + 1, result);
			    break;
			    
		case 0: exit(0);
		default : printf("wrong choice! try again\n");
				
		
	}
}
	return 0;
}
