#include<iostream>
#include<string>
using namespace std;

class Employee{
    private:
        string emp_name;
        long emp_id;
        double salary;
    public:
        Employee(){}
        Employee(const char* name ,long id, double sal){
            emp_id = id;
            salary = sal;
            emp_name = name;
        }
        void setId(long id){
            emp_id = id;
        }

        void setSalary(double sal){
            salary = sal;
        }
        void setName(string name){
            emp_name = name;
        }
        long getId(){
            return emp_id;
        }
        double getSalary(){
            return salary;
        }
        string getName(){
            return emp_name;
        }
        void printNameAndId(){
            cout<<"name : "<<emp_name<<endl;
            cout<<"id : "<<emp_id<<endl;
        }

};

int main(){
    int size = 2;
    Employee e[size];
    
    for(int i =0;i<size;i++){
        cout<<"enter name id salary of employee "<<i+1<<" : "<<endl;
        string name;
        long id;
        double sal;
        cin>>name;
        cin>>id;
        cin>>sal;
        e[i].setId(id);
        e[i].setSalary(sal);
        e[i].setName(name);
    }

    cout<<"the name and id of employees having more than 5k salary are : "<<endl;
    for(int i=0;i<size;i++){
        if(e[i].getSalary()>5000){
            e[i].printNameAndId();
        }
    }
   
    return 0;
}