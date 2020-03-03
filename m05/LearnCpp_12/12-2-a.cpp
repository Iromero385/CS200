#include <iostream>

class Base {
public:
    const char* getName() { return "Base"; }
};
 
class Derived: public Base {
public:
    const char* getName() { return "Derived"; }
};
 
int main() {
    Derived derived;
    Base &rBase = derived;
    std::cout << "rBase is a " << rBase.getName() << '\n';
}