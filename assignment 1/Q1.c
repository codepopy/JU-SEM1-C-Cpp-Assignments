#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        printf("select one of the options below :\n 1. Fahrenheit to Degree Celsius\n 2. Degree Celsius to Fahrenheit\n 0.Exit \n");
        int choice;
        scanf("%d", &choice);
        float f1, f2, c1, c2;
        switch (choice) {
            case 1:
                printf("enter the temperature in fahrenheit : ");
                scanf("%f", &f1);
                printf("the temperature in celsius is : %f \n", (f1 - 32) * 5/9);
                break;

            case 2:
                printf("enter the temperature in Degree Celsius : ");
                scanf("%f", &c2);
                f2 = (c2 * 9/5) + 32;
                printf("the temperature in Fahrenheit is : %f\n", f2);
                break;

            case 0:
                exit(0);
            default:
                printf("wrong choice please try with a correct input!\n");
        }
    }
    return 0;
}

