#include <iostream>
#include "Derived.h"
 
int main() {
	Derived derived(5);
 
	// These are both legal!
	Base &rBase = derived;
	Base *pBase = &derived;
 
	std::cout << "\nderived is a " << derived.getName() 
			  << " and has value " << derived.getValue();
	std::cout << "\nrBase is a " << rBase.getName() 
			  << " and has value " << rBase.getValue();
	std::cout << "\npBase is a " << pBase->getName() 
			  << " and has value " << pBase->getValue();
}