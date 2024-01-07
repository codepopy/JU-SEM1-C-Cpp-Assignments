#include<iostream>
using namespace std;
#define PI 3.141

class Shape {
protected:
    double radius; // Protected member variable

public:
    // Public member function to set the radius
    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            std::cout << "Invalid radius. Setting to default (0)." << std::endl;
            radius = 0;
        }
    }

    // Public member function to get the radius
    double getRadius() const {
        return radius;
    }
};

class Circle : public Shape {
public:
    // Public member function to calculate the area
    double calculateArea() const {
        return PI * radius * radius;
    }
};


int main(){
	float r;
	cout<<"enter the radius of the cirle";
	cin>>r;
	circle c(r);
	cout<<"the area of the circle is  : "<<c.calculateArea()<<endl;
	return 0;
}


