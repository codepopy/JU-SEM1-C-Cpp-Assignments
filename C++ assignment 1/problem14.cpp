#include <iostream>
using namespace std;

class NumberSwapper {
private:
    int num1, num2;

public:
    NumberSwapper(int a, int b) : num1(a), num2(b) {}

    friend void swapNumbers(NumberSwapper&);

    void displayNumbers() {
        cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << endl;
    }
};

void swapNumbers(NumberSwapper& ns) {
    ns.num1 = ns.num1 + ns.num2;
    ns.num2 = ns.num1 - ns.num2;
    ns.num1 = ns.num1 - ns.num2;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers:" << endl;
    cin >> num1 >> num2;

    NumberSwapper numbers(num1, num2);

    cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << endl;

    swapNumbers(numbers);

    numbers.displayNumbers();

    return 0;
}

