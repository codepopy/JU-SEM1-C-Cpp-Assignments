#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Student {
protected:
    string name;
    int rollNumber;

public:
    Student(const string& studentName, int roll) : name(studentName), rollNumber(roll) {}

    virtual void display() const = 0;  // Pure virtual function
    virtual void study() const = 0;     // Pure virtual function

    virtual ~Student() {
        cout << "Student destructor called." << endl;
    }
};

// Engineering students
class Engineering : public Student {
private:
    string branch;

public:
    Engineering(const string& studentName, int roll, const string& engineeringBranch)
        : Student(studentName, roll), branch(engineeringBranch) {}

    void display() const override {
        cout << "Engineering Student - Name: " << name << ", Roll Number: " << rollNumber << ", Branch: " << branch << endl;
    }

    void study() const override {
        cout << "Engineering student is studying." << endl;
    }

    ~Engineering() override {
        cout << "Engineering destructor called." << endl;
    }
};

// Medicine students
class Medicine : public Student {
private:
    string specialization;

public:
    Medicine(const string& studentName, int roll, const string& medicineSpecialization)
        : Student(studentName, roll), specialization(medicineSpecialization) {}

    void display() const override {
        cout << "Medicine Student - Name: " << name << ", Roll Number: " << rollNumber << ", Specialization: " << specialization << endl;
    }

    void study() const override {
        cout << "Medicine student is studying." << endl;
    }

    ~Medicine() override {
        cout << "Medicine destructor called." << endl;
    }
};

// Science students
class Science : public Student {
private:
    string field;

public:
    Science(const string& studentName, int roll, const string& scienceField)
        : Student(studentName, roll), field(scienceField) {}

    void display() const override {
        cout << "Science Student - Name: " << name << ", Roll Number: " << rollNumber << ", Field: " << field << endl;
    }

    void study() const override {
        cout << "Science student is studying." << endl;
    }

    ~Science() override {
        cout << "Science destructor called." << endl;
    }
};

int main() {
    const int numStudents = 3;
    Student* students[numStudents];

    students[0] = new Engineering("John Doe", 101, "Computer Science");
    students[1] = new Medicine("Jane Smith", 201, "Cardiology");
    students[2] = new Science("Alice Johnson", 301, "Physics");

    cout << "Processing students using array of pointers:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        students[i]->display();
        students[i]->study();
        delete students[i];
        cout << endl;
    }

    return 0;
}

