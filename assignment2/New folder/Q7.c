#include <stdio.h>  
  
void bubble_sort(int arr[], int n) {  
  int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (arr[j] > arr[j + 1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
  }  
}  
int main() {  
 	printf("enter the array size :  ");
	int n;
	scanf("%d",&n);
	int arr[n+1];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("enter the number to insert : ");
	int num;
	scanf("%d",&num);
  arr[n] = num;
  bubble_sort(arr, n+1);  
  printf("Sorted array: ");  
  for (int i = 0; i < n+1; i++) {  
    printf("%d ", arr[i]);  
  }  
  return 0;  
}  
