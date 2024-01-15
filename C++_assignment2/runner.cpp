#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int choice;
    cout<<"C++ assignment 2 menu : "<<endl;
    do{
        cout<<"----------------------------------"<<endl;
        cout<<"enter the number of the problem you want to see : ";
        cin>>choice;
        switch(choice){
            case 1:
                system("g++ problem1.cpp -o p1;./p1");
                break;
            case 2:
                system("g++ problem2.cpp -o p2;./p2");
                break;
            case 3:
                system("g++ problem3.cpp -o p3;./p3");
                break;
            case 4:
                system("g++ problem4.cpp -o p4;./p4");
                break;
            case 5:
                system("g++ problem5.cpp -o p5;./p5");
                break;
            case 6:
                system("g++ problem6.cpp -o p6;./p6");
                break;
            case 7:
                system("g++ problem7.cpp -o p7;./p7");
                break;
            case 8:
                system("g++ problem8.cpp -o p8;./p8");
                break;
            case 9:
                system("g++ problem9.cpp -o p9;./p9");
                break;
            case 10:
                system("g++ problem10.cpp -o p10;./p10");
                break;
            case 11:
                system("g++ problem11.cpp -o p11;./p11");
                break;
            case 12:
                system("g++ problem12.cpp -o p12;./p12");
                break;
            case 13:
                system("g++ problem13.cpp -o p13;./p13");
                break;
            case 14:
                system("g++ problem14.cpp -o p14;./p14");
                break;
            case 15:
                system("g++ problem15.cpp -o p15;./p15");
                break;
            case 0: exit(0);
            default: cout<<"wrong choice please try again"<<endl;
        }
    }
    while(choice!=0);

    return 0;
}