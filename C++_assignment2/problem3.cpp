#include<iostream>
using namespace std;

class Rectangle{
    private:
        double length;
        double breadth;
    public:
        Rectangle(){}
        void createObj(double l, double b){
            length = l;
            breadth = b;
        }
        bool isLenEqBre(){
            return length==breadth;
        }
        void print(){
            cout<<"length : "<<length<<endl;
            cout<<"breadth : "<<breadth<<endl;
        }

};

int main(){
    int size = 3;
    Rectangle r[size];
    for(int i=0;i<size;i++){
        double l,b;
        cout<<"enter length : ";
        cin>>l;
        cout<<"enter breadth : ";
        cin>>b;
        r[i].createObj(l,b);
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        if(r[i].isLenEqBre()){
            r[i].print();
        }
    }
    return 0;
}