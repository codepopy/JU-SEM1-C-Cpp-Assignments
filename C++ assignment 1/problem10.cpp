#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265359;

// Function overloading for volume calculation
int calculateVolume(int side) {
    return pow(side, 3); // Cube
}

double calculateVolume(double length, double width, double height) {
    return length * width * height; // Cuboid
}

double calculateVolume(double radius, double height) {
    return PI * pow(radius, 2) * height; // Cylinder
}

double calculateVolume(double radius) {
    return (4.0 / 3.0) * PI * pow(radius, 3); // Sphere
}

double calculateVolume(double radius, int slantHeight) {
    return (1.0 / 3.0) * PI * pow(radius, 2) * slantHeight; // Cone
}

int main() {
    int choice,side,slantHeight;
    double volume, length, width, height, radius;

    do {
        cout << "\nMenu:\n";
        cout << "1. Volume of Cube\n";
        cout << "2. Volume of Cuboid\n";
        cout << "3. Volume of Cylinder\n";
        cout << "4. Volume of Sphere\n";
        cout << "5. Volume of Cone\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the side of the cube: ";
                cin >> side;
                volume = calculateVolume(side);
                break;

            case 2:
                cout << "Enter the length, width, and height of the cuboid: ";
                cin >> length >> width >> height;
                volume = calculateVolume(length, width, height);
                break;

            case 3:
                cout << "Enter the radius and height of the cylinder: ";
                cin >> radius >> height;
                volume = calculateVolume(radius, height);
                break;

            case 4:
                cout << "Enter the radius of the sphere: ";
                cin >> radius;
                volume = calculateVolume(radius);
                break;

            case 5:
                cout << "Enter the radius and slant height of the cone: ";
                cin >> radius >> slantHeight;
                volume = calculateVolume(radius, slantHeight);
                break;

            case 0:
                cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                continue;
        }

        cout << "Volume: " << volume << endl;

    } while (true);

    return 0;
}

