#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // If characters at the start and end are not equal, not a palindrome
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }

        start++;
        end--;
    }

    return 1; // Palindrome
}

int main() {
    char inputString[100]; // Assuming a maximum string length of 100 characters

    // Input
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Output the string in reverse order
    printf("Reverse of the string: ");
    for (int i = strlen(inputString) - 1; i >= 0; i--) {
        printf("%c", inputString[i]);
    }
    printf("\n");

    // Check if the string is a palindrome
    if (isPalindrome(inputString)) {
        printf("The entered string is a palindrome.\n");
    } else {
        printf("The entered string is not a palindrome.\n");
    }

    return 0;
}

