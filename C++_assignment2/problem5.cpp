#include<iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    class AreaCalculator {
    public:
        void calculateAndPrintArea(const Circle& circle) {
            double area = 3.14 * circle.radius * circle.radius;
            cout << "Area of the circle with radius " << circle.radius << " is: " << area << endl;
        }
    };
};

int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    Circle circleObj(radius);
    Circle::AreaCalculator calculator;

    calculator.calculateAndPrintArea(circleObj);

    return 0;
}

