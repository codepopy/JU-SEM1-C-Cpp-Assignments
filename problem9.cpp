#include <iostream>
using namespace std;

class Mammals {
public:
    void displayMammal() {
        cout << "I am a mammal." << endl;
    }
};

class MarineAnimals {
public:
    void displayMarineAnimal() {
        cout << "I am a marine animal." << endl;
    }
};

class BlueWhale : public Mammals, public MarineAnimals {
public:
    void displayBlueWhale() {
        cout << "I belong to both the categories: Mammals as well as Marine Animals." << endl;
    }
};

int main() {
    Mammals mammalObj;
    MarineAnimals marineAnimalObj;
    BlueWhale blueWhaleObj;

    cout << "a) Function of Mammals by the object of Mammal:" << endl;
    mammalObj.displayMammal();

    cout << "\nb) Function of MarineAnimal by the object of MarineAnimal:" << endl;
    marineAnimalObj.displayMarineAnimal();

    cout << "\nc) Function of BlueWhale by the object of BlueWhale:" << endl;
    blueWhaleObj.displayBlueWhale();

    cout << "\nd) Function of each parent by the object of BlueWhale:" << endl;
    blueWhaleObj.displayMammal();
    blueWhaleObj.displayMarineAnimal();

    return 0;
}

