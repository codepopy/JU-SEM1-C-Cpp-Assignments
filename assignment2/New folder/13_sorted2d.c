#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print2D(int (*arr)[3], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++ ){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void sort2D(int a[][3], int row, int col){
    int *arr = (int *)a;
    int elementcount = row * col;
    int *lowerBound = arr;
    int *upperBound = arr + (elementcount - 1);
    int *j;
    for (arr = arr + 1; arr<=upperBound; arr++){
        int temp = *arr;
        j = arr-1;
        while(j>=lowerBound && temp<(*j)){
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = temp;
    }
}

int main(){
    int arr[3][3] = {
        {4, 2, 9},
        {4, 5, 6},
        {2, 3, 5}};

    sort2D(arr, 3, 3);
    printf("\n\nAfter sorting arr1: \n");
    print2D(arr, 3, 3);

    int arr2[3][3] = {
        {7, 3, -5},
        {1, -1, 2},
        {11, 9, -12}};

    sort2D(arr2, 3, 3);
    printf("\n\nAfter sorting arr2: \n");
    print2D(arr2, 3, 3);

    int result[3][3];

    for(int i = 0; i<3; i++){
        for (int j = 0; j<3; j++)
            result[i][j] = arr[i][j] + arr2[i][j];
    }
    
    printf("\n\nResultant array after sum: \n");
    print2D(result, 3, 3);

    return 0;
}