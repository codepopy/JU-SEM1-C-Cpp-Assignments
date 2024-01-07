#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;

public:
    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~MyString() {
        delete[] str;
    }

    void displayString() {
        cout << "String: " << str << endl;
    }

    MyString operator+(const MyString& s1) {
        
        char* r = new char[strlen(s1.str) + strlen(str) + 1];
        strcpy(r, str);
        strcat(r, s1.str);
        
        MyString res(r);
        
        
        return res;
    }
};

int main() {
    MyString string1("Hello");
    MyString string2(" World");

    cout << "Original Strings:" << endl;
    string1.displayString();
    string2.displayString();

    MyString resultString = string1 + string2;

    cout << "\nAfter Joining Strings:" << endl;
    resultString.displayString();

    return 0;
}
