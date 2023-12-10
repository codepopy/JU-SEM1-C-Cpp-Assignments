#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int countVowel = 0;
	
	char c[100];
	printf("enter the string : ");
	fgets(c, sizeof(c), stdin);
	
	for(int i=0;i<strlen(c);i++){
		c[i] = toupper(c[i]);
	}
	
	printf("\n%s",c);
	return 0;	
}
