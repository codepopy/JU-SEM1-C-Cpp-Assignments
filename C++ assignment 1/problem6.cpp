#include <iostream>
using namespace std;

class LeapYearChecker {
private:
    int year;

public:
    LeapYearChecker(int y) : year(y) {
        cout << "Object created for year " << year << endl;
    }

    ~LeapYearChecker() {
        cout << "Object destroyed for year " << year << endl;
    }

    void checkLeapYear() {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            cout << year << " is a leap year." << endl;
        } else {
            cout << year << " is not a leap year." << endl;
        }
    }
};

int main() {
    int year;

    cout << "Enter a year: ";
    cin >> year;

    LeapYearChecker yearChecker(year);
    yearChecker.checkLeapYear();

    return 0;
}

