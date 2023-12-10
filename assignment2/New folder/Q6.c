#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main(){
	int countVowel = 0;
	
	char c[100];
	printf("enter the string : ");
	fgets(c, sizeof(c), stdin);
	
	for(int i=0;i<strlen(c);i++){
		if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u' ){
			countVowel++;
		}
		
	}
	printf("the number of vowels are : %d\n the number of consonants are : %d",countVowel, strlen(c)-countVowel);
	return 0;
}
