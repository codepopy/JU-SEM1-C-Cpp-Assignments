#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string shapeName) : name(shapeName) {}

    virtual void display() const {
        cout << "Shape: " << name << endl;
    }

    virtual double area() const {
        return 0.0;
    }

    virtual ~Shape() {
        cout << "Shape destructor called." << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    void display() const override {
        Shape::display();
        cout << "Radius: " << radius << endl;
    }

    double area() const override {
        return 3.14 * radius * radius;
    }

    ~Circle() override {
        cout << "Circle destructor called." << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : Shape("Rectangle"), length(l), width(w) {}

    void display() const override {
        Shape::display();
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    double area() const override {
        return length * width;
    }

    ~Rectangle() override {
        cout << "Rectangle destructor called." << endl;
    }
};

class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;

public:
    Trapezoid(double b1, double b2, double h) : Shape("Trapezoid"), base1(b1), base2(b2), height(h) {}

    void display() const override {
        Shape::display();
        cout << "Base1: " << base1 << ", Base2: " << base2 << ", Height: " << height << endl;
    }

    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }

    ~Trapezoid() override {
        cout << "Trapezoid destructor called." << endl;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Trapezoid(3.0, 5.0, 2.0);

    for (int i = 0; i < 3; ++i) {
        shapes[i]->display();
        cout << "Area: " << shapes[i]->area() << endl;
        delete shapes[i];
        cout << endl;
    }

    return 0;
}

