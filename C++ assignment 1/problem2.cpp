#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    void inputSides();
    double calculateArea();
    double calculatePerimeter();
    void printData();
};

void Triangle::inputSides() {
    cout << "Enter the lengths of the three sides of the triangle:" << endl;
    cin >> side1 >> side2 >> side3;
}

double Triangle::calculateArea() {
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double Triangle::calculatePerimeter() {
    return side1 + side2 + side3;
}

void Triangle::printData() {
    cout << "Triangle sides: " << side1 << ", " << side2 << ", " << side3 << endl;
    cout << "Area: " << calculateArea() << endl;
    cout << "Perimeter: " << calculatePerimeter() << endl;
}

int main() {
    Triangle myTriangle;

    myTriangle.inputSides();
    myTriangle.printData();

    return 0;
}

