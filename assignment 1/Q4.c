#include <stdio.h>

void convertToWords(int number) {
    char *indian_words[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *indian_tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *indian_teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    // Extract individual digits
    int crore = number / 10000000;
    int lakh = (number / 100000) % 100;
    int thousand = (number / 1000) % 100;
    int units = number % 1000;

    // Convert digits to words
    printf("Indian Number System: ");
    
    // Crore place
    if (crore != 0) {
        printf("%s Crore ", indian_words[crore]);
    }
    
    // Lakh place
    if (lakh != 0) {
        printf("%s Lakh ", indian_words[lakh]);
    }
    
    // Thousand place
    if (thousand != 0) {
        printf("%s Thousand ", indian_words[thousand / 10]); // corrected this line
    }
    
    // Units place
    if (units != 0) {
        printf("%s", indian_words[units]);
    }

    printf("\n");

    // Reset result for International system
    
}

int main() {
    // Example usage
    int number = 12345678;
    convertToWords(number);

    return 0;
}

