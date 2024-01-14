#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Marks {
protected:
    int rollNumber;
    string name;
    int marks;

public:
    Marks() {
        rollNumber = generateRollNumber();
    }

    int generateRollNumber() {
        static int baseRollNumber = 1000; // starting roll number
        return baseRollNumber++;
    }

    void inputMarks( string a, string n) {
    	name = n;
        cout << "Enter "<<a<<" marks for student " << n << " : ";
        cin >> marks;
    }

    int getMarks() const {
        return marks;
    }
    string getName(){
    	return name;
	}
};

class Physics : public Marks {
public:
    Physics() : Marks() {}
};

class Chemistry : public Marks {
public:
    Chemistry() : Marks() {}
};

class Mathematics : public Marks {
public:
    Mathematics() : Marks() {}
};

int main() {
    int numStudents;
    
    cout << "Enter the number of students in the class: ";
    cin >> numStudents;

    Physics* physicsStudents = new Physics[numStudents];
    Chemistry* chemistryStudents = new Chemistry[numStudents];
    Mathematics* mathStudents = new Mathematics[numStudents];

    
    for (int i = 0; i < numStudents; ++i) {
    	string name;
    	cout<<"enter the name of student : ";
    	cin>>name;
        physicsStudents[i].inputMarks("physics",name);
        chemistryStudents[i].inputMarks("chemistry",name);
        mathStudents[i].inputMarks("math",name);
        
        cout<<endl;
    }

   
    int totalPhysics = 0, totalChemistry = 0, totalMathematics = 0, total=0;

    for (int i = 0; i < numStudents; ++i) {
        totalPhysics += physicsStudents[i].getMarks();
        totalChemistry += chemistryStudents[i].getMarks();
        totalMathematics += mathStudents[i].getMarks();
    }
   
    
    for (int i = 0; i < numStudents; ++i) {
        total = physicsStudents[i].getMarks() + chemistryStudents[i].getMarks() + mathStudents[i].getMarks();
        cout<<" total of student "<<physicsStudents[i].getName()<<" is : "<<total<<" / 300"<<endl;
        total = 0;
    }

    double averagePhysics = static_cast<double>(totalPhysics) / numStudents;
    double averageChemistry = static_cast<double>(totalChemistry) / numStudents;
    double averageMathematics = static_cast<double>(totalMathematics) / numStudents;

    
    cout << "\nSubject-wise Class Statistics:\n";
    cout << "Physics - Total Marks: " << totalPhysics << ", Average Marks: " << fixed << setprecision(2) << averagePhysics << endl;
    cout << "Chemistry - Total Marks: " << totalChemistry << ", Average Marks: " << fixed << setprecision(2) << averageChemistry << endl;
    cout << "Mathematics - Total Marks: " << totalMathematics << ", Average Marks: " << fixed << setprecision(2) << averageMathematics << endl;

   
    delete[] physicsStudents;
    delete[] chemistryStudents;
    delete[] mathStudents;

    return 0;
}

