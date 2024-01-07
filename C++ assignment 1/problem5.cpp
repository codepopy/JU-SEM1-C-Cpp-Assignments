#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imaginary;

public:
    Complex() : real(0), imaginary(0) {}
    Complex(int r) : real(r), imaginary(0) {}
    Complex(int r, int i) : real(r), imaginary(i) {}

    void show() {
        cout << "Complex Number: " << real << " + " << imaginary << "i" << endl;
    }

    Complex sum(const Complex& c2) {
        Complex result;
        result.real = real + c2.real;
        result.imaginary = imaginary + c2.imaginary;
        return result;
    }
    
    void print(){
    	cout<<real<<" + "<<"( "<<imaginary<<"i"<<" )"<<endl;
	}
};

int main() {
    
	
	int real, img;
	cout<<"complex number 1"<<endl;
	cout<<"real part : ";
	cin>>real;
	cout<<"imaginary part : ";
	cin>>img;
	
	Complex c1(real,img);
	
	c1.print();
	
	cout<<"complex number 1"<<endl;
	cout<<"real part : ";
	cin>>real;
	cout<<"imaginary part : ";
	cin>>img;
	
	Complex c2(real,img);
	
	c2.print();
	
	Complex sum = c2.sum(c1);
	
	cout<<"sum is : ";
	sum.print();
    
    return 0;
}
