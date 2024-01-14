#include<iostream>
using namespace std;

class GreatestFinder {
private:
    int num1, num2, num3;

public:
    void inputNumbers() {
        cout << "Enter three numbers: ";
        cin >> num1 >> num2 >> num3;
    }

    int findGreatest() {
        if (num1 >= num2 && num1 >= num3)
            return num1;
        else if (num2 >= num1 && num2 >= num3)
            return num2;
        else
            return num3;
    }

    class DisplayResult {
    public:
        void display(int greatest) {
            cout << "The greatest number is: " << greatest << endl;
        }
    };
};

int main() {
    GreatestFinder::DisplayResult result;
    GreatestFinder obj;

    obj.inputNumbers();
    int greatest = obj.findGreatest();

    result.display(greatest);

    return 0;
}

