#include <stdio.h>


void computeSortedUnion(int list1[], int size1, int list2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (list1[i] < list2[j]) {
            result[k++] = list1[i++];
        } else if (list1[i] > list2[j]) {
            result[k++] = list2[j++];
        } else {
            
            result[k++] = list1[i++];
            j++;
        }
    }

  
    while (i < size1) {
        result[k++] = list1[i++];
    }

 
    while (j < size2) {
        result[k++] = list2[j++];
    }
}

int main() {
    int size1, size2;

  
    printf("Enter the size of the first list: ");
    scanf("%d", &size1);

    int list1[size1];
    printf("Enter the elements of the first list in ascending order:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &list1[i]);
    }

    
    printf("Enter the size of the second list: ");
    scanf("%d", &size2);

    int list2[size2];
    printf("Enter the elements of the second list in ascending order:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &list2[i]);
    }


    int result[size1 + size2];
    computeSortedUnion(list1, size1, list2, size2, result);

    printf("The sorted union of the two lists is:\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}

