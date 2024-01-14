#include<iostream>
using namespace std;

class Calculator {
protected:
    double num1, num2;

public:
    void inputNumbers() {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
    }

    class Addition {
    public:
        double performOperation(const Calculator& calc) {
            return calc.num1 + calc.num2;
        }
    };

    class Subtraction {
    public:
        double performOperation(const Calculator& calc) {
            return calc.num1 - calc.num2;
        }
    };

    class Multiplication {
    public:
        double performOperation(const Calculator& calc) {
            return calc.num1 * calc.num2;
        }
    };

    class Division {
    public:
        double performOperation(const Clealculator& calc) {
            if (calc.num2 != 0) {
                return calc.num1 / calc.num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                return 0.0; // Returning 0 in case of division by zero
            }
        }
    };
};

int main() {
    Calculator calculator;
    Calculator::Addition add;
    Calculator::Subtraction subtract;
    Calculator::Multiplication multiply;
    Calculator::Division divide;

    int choice;
    do {
        cout << "\nCalculator Menu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calculator.inputNumbers();
                cout << "Result: " << add.performOperation(calculator) << endl;
                break;
            case 2:
                calculator.inputNumbers();
                cout << "Result: " << subtract.performOperation(calculator) << endl;
                break;
            case 3:
                calculator.inputNumbers();
                cout << "Result: " << multiply.performOperation(calculator) << endl;
                break;
            case 4:
                calculator.inputNumbers();
                cout << "Result: " << divide.performOperation(calculator) << endl;
                break;
            case 5:
                cout << "Exiting the calculator program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}

