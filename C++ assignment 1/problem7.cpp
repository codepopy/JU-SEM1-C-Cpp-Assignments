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

    void joinStrings(const MyString& s1, const MyString& s2) {
        delete[] str;
        str = new char[strlen(s1.str) + strlen(s2.str) + 1];
        strcpy(str, s1.str);
        strcat(str, s2.str);
    }
};

int main() {
    MyString string1("Hello");
    MyString string2(" World");

    cout << "Original Strings:" << endl;
    string1.displayString();
    string2.displayString();

    MyString resultString("Initial");
    resultString.joinStrings(string1, string2);

    cout << "\nAfter Joining Strings:" << endl;
    resultString.displayString();

    return 0;
}

