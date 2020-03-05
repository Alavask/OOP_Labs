#include <iostream>

using namespace std;

class Father {
public:
    Father() {
       cout << "Here Father constructor is called" << endl;
    }

    ~Father() {
        cout << "Here Father destructor is called" << endl;
    }
};

class Son : public Father
{
public:
    Son() {
        cout << "Here Son constructor is called" << endl;
    };
    ~Son() {
        cout << "Here Son destructor is called" << endl;
    };
};

int main1() {
    auto father = new Father();
    delete father;

    cout << endl;

    auto son = new Son();
    delete son;

    cout << endl;

    Father* fosterSon = new Son();
    delete fosterSon;
    return 0;
}


