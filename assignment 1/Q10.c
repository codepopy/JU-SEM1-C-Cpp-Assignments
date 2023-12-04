#include <stdio.h>


int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    int a, b;


    printf("Enter an integer: ");
    scanf("%d", &a);

    
    b = reverseNumber(a);


    if (a == b) {
        printf("%d is a palindrome.\n", a);
    } else {
        printf("%d is not a palindrome.\n", b);
    }

    return 0;
}

