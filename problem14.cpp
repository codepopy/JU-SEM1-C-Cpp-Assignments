#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& personName) : name(personName) {}

    virtual void display() const {
        cout << "Name: " << name << endl;
    }

    virtual ~Person() {
        cout << "Person destructor called." << endl;
    }
};

class Employee : virtual public Person {
protected:
    int employeeId;

public:
    Employee(const string& empName, int empId) : Person(empName), employeeId(empId) {}

    void display() const override {
        Person::display();
        cout << "Employee ID: " << employeeId << endl;
    }

    virtual ~Employee() {
        cout << "Employee destructor called." << endl;
    }
};

class Student : virtual public Person {
protected:
    int studentId;

public:
    Student(const string& stuName, int stuId) : Person(stuName), studentId(stuId) {}

    void display() const override {
        Person::display();
        cout << "Student ID: " << studentId << endl;
    }

    virtual ~Student() {
        cout << "Student destructor called." << endl;
    }
};

class Manager : public Employee, public Student {
public:
    Manager(const string& mgrName, int empId, int stuId)
        : Person(mgrName), Employee(mgrName, empId), Student(mgrName, stuId) {}

    void display() const override {
        Person::display();
        cout << "Manager (Employee ID): " << employeeId << endl;
        cout << "Manager (Student ID): " << studentId << endl;
    }

    ~Manager() override {
        cout << "Manager destructor called." << endl;
    }
};

int main() {
    Manager managerObj("John Doe", 101, 201);
    managerObj.display();

    return 0;
}

