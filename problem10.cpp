#include <iostream>
using namespace std;

class Fruit {
protected:
    static int totalFruits;

public:
    Fruit() {
        totalFruits++;
    }

    static int getTotalFruits() {
        return totalFruits;
    }
};

int Fruit::totalFruits = 0;

class Apples : public Fruit {
private:
    static int applesCount;

public:
    Apples() {
        applesCount++;
    }

    static int getApplesCount() {
        return applesCount;
    }
};

int Apples::applesCount = 0;

class Mangoes : public Fruit {
private:
    static int mangoesCount;

public:
    Mangoes() {
        mangoesCount++;
    }

    static int getMangoesCount() {
        return mangoesCount;
    }
};

int Mangoes::mangoesCount = 0;

int main() {
    Apples apple1, apple2, apple3;
    Mangoes mango1, mango2;

    cout << "Number of Apples: " << Apples::getApplesCount() << endl;
    cout << "Number of Mangoes: " << Mangoes::getMangoesCount() << endl;
    cout << "Total Number of Fruits in the Basket: " << Fruit::getTotalFruits() << endl;

    return 0;
}

