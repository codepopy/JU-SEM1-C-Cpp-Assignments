#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base class default constructor called." << endl;
    }

    Base(int x) {
        cout << "Base class parameterized constructor called with value: " << x << endl;
    }
    
    Base(Base &a){
    	cout<<"base copy constructor called"<<endl;
	}

    virtual ~Base() {
        cout << "Base class virtual destructor called." << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived class default constructor called." << endl;
    }

    Derived(int x, int y) : Base(x) {
        cout << "Derived class parameterized constructor called with values: " << x << ", " << y << endl;
    }

    ~Derived() override {
        cout << "Derived class destructor called." << endl;
    }
};

int main() {
    cout << "Creating Base object using default constructor:" << endl;
    Base baseObj;
    
    cout << "Creating Base object using copy constructor:" << endl;
    Base baseCPObj(baseObj);

    cout << "\nCreating Derived object using parameterized constructor:" << endl;
    Derived derivedObj(10, 20);

    cout << "\nCreating Derived object using default constructor:" << endl;
    Derived derivedObj2;

    return 0;
}

