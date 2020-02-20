#include<iostream>
using namespace std;

class Base {
    int x;
public:
    Base() { cout << "Base Default" << endl; }
    Base(int x) : x(x) { cout << "Base Parameterize" << endl; }
};

class Derived : public Base{
    int y;
public:
    Derived() : Base() { cout << "Derived Default" << endl; }
    Derived(int y, int x) : Base(x), y(y) { cout << "Derived Parameterize" << endl; }
};

int main() {
    Derived d;
    Derived d2(1,2);
}