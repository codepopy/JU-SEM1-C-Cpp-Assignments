#include <iostream>
using namespace std;

class NumberProcessor {
public:
    void calculate(int m, char ch) {
        if (ch == 'r') {
            reverseDigits(m);
        } else if (ch == 'p') {
            checkPrime(m);
        } else {
            cout << "Invalid choice. Please enter 'r' or 'p'." << endl;
        }
    }

private:
    void reverseDigits(int& num) {
        if (num < 10) {
            cout << "The number should have more than one digit for reversal." << endl;
        } else {
            int reversedNum = 0;
            while (num > 0) {
                int digit = num % 10;
                reversedNum = reversedNum * 10 + digit;
                num /= 10;
            }
            cout << "Reversed Number: " << reversedNum << endl;
        }
    }

    void checkPrime(int num) {
        if (num < 2) {
            cout << num << " is not a prime number." << endl;
            return;
        }

        bool isPrime = true;
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << num << " is a prime number." << endl;
        } else {
            cout << num << " is not a prime number." << endl;
        }
    }
};

int main() {
    NumberProcessor processor;

    int number;
    char choice;

    cout << "Enter an integer: ";
    cin >> number;

    cout << "Enter 'r' to reverse digits or 'p' to check prime: ";
    cin >> choice;

    processor.calculate(number, choice);

    return 0;
}

