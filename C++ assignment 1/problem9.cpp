#include <iostream>
using namespace std;


inline double square(double num) {
    return num * num;
}

int main() {
    double number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Square of " << number << " is: " << square(number) << endl;

    return 0;
}

