#include<stdio.h>
#include<string.h>
int main(void){
	char ar[100];
	printf("enter the string to encode : ");
	scanf(" %[^\n]s",ar);
	
	for(int i=0;i<strlen(ar);i++){
		if(ar[i]!=' '){
			ar[i]+=1;
		}
	}
	
	printf("%s",ar);
	return 0;
}
