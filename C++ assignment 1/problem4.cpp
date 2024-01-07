#include <iostream>

using namespace std;

class InvertedTriangle {
private:
    int height;

public:
    InvertedTriangle(int h) : height(h) {}

    void printPattern() {
        for (int i = height; i >= 1; --i) {
            for (int j = 0; j < height - i; ++j) {
                cout << "  ";
            }
            for (int k = 0; k < 2 * i - 1; ++k) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

int main() {
    int height;

    cout << "Enter the height of the inverted triangle: ";
    cin >> height;

    InvertedTriangle invertedTriangle(height);

    invertedTriangle.printPattern();

    return 0;
}

