#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
        long st_roll;
        string st_name;
        double marks[3];
        float avg;
        string grade;

        void calcGrade(){
            if(avg>80)grade = "A";
            else if(avg<80 && avg>70)grade = "B";
            else if(avg<70 && avg>60)grade = "C";
            else if(avg<60 && avg>50)grade = "D";
           else grade = "E";
        }
    public:
        Student(){}
        void createStudent(){
            cout<<"enter the roll : ";
            cin>>st_roll;
            cout<<"enter name of student : ";
            cin>>st_name;
            cout<<"enter marks of 3 subjects : "<<endl;
            cin>>marks[0]>>marks[1]>>marks[2];
            cout<<endl;

            avg = (marks[0]+marks[1]+marks[2])/3;

            calcGrade();

        }

        void printStudent(){
            cout<<"roll : "<<st_roll<<endl;
            cout<<"name : "<<st_name<<endl;
            cout<<"average marks : "<<avg<<endl;
            cout<<"grade : "<<grade<<endl;
        }
        
        
        long getRoll(){
            return st_roll;
        }
        string getName(){
            return st_name;
        }
        double* getMarks(){
            return marks;
        }

};

int main(){
    int size = 5;
    Student s[size];
    for(int i=0;i<size;i++){
        cout<<"----student "<< i+1 <<"----"<<endl;
        s[i].createStudent();
        cout<<endl;
    }

    for(int i=0;i<size;i++){
        s[i].printStudent();
        cout<<endl;
    }
    return 0;
}