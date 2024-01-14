#include <iostream>
using namespace std;

class Shape {
public:
    void display() {
        cout << "This is a shape." << endl;
    }
};

class Polygon : public Shape {
public:
    void display() {
        cout << "Polygon is a shape." << endl;
    }
};

class Rectangle : public Polygon {
public:
    void display() {
        cout << "Rectangle is a polygon." << endl;
    }
};

class Triangle : public Polygon {
public:
    void display() {
        cout << "Triangle is a polygon." << endl;
    }
};

class Square : public Rectangle {
public:
    void display() {
        cout << "Square is a rectangle." << endl;
    }
};

int main() {
    Shape shapeObj;
    Polygon polygonObj;
    Rectangle rectangleObj;
    Triangle triangleObj;
    Square squareObj;

    cout << "Calling function by the object of each class:" << endl;

    shapeObj.display();
    polygonObj.display();
    rectangleObj.display();
    triangleObj.display();
    squareObj.display();

    return 0;
}

