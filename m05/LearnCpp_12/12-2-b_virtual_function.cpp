#include <iostream>
class Base {
public:
	// note addition of virtual keyword
	virtual const char* getName() { return "Base"; } 
	
};
 
class Derived: public Base {
public:
	virtual const char* getName() { return "Derived"; }
};
 
int main() {
	Derived derived;
	Base &rBase = derived;
	std::cout << "rBase is a " << rBase.getName() << '\n';
}