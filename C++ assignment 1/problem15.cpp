#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    friend Complex addComplex(const Complex& c1, const Complex& c2);

    void displayComplex() const {
        cout << "Result: " << real << " + " << imag << "i" << endl;
    }
};

Complex addComplex(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    double real1, imag1, real2, imag2;

    cout << "Enter the real and imaginary parts of the first complex number:" << endl;
    cin >> real1 >> imag1;

    cout << "Enter the real and imaginary parts of the second complex number:" << endl;
    cin >> real2 >> imag2;

    Complex complex1(real1, imag1);
    Complex complex2(real2, imag2);

    Complex result = addComplex(complex1, complex2);

    cout << "\nSum of the complex numbers:" << endl;
    result.displayComplex();

    return 0;
}

