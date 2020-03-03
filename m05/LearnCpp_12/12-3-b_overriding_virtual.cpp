#include <iostream>

class Base {
public:
    virtual ~Base() { // note: virtual
        std::cout << "Calling ~Base()" << std::endl;
    }
};

// Rule: Whenever you are dealing with inheritance, 
// you should make any explicit destructors virtual.
class Derived: public Base {
    int* m_array;
public:
    Derived(int length) { m_array = new int[length]; }
    virtual ~Derived() { // note: virtual
        std::cout << "Calling ~Derived()" << std::endl;
        delete[] m_array;
    }
};
 
int main() {
    Derived *derived = new Derived(5);
    Base *base = derived;
    delete base;
}
