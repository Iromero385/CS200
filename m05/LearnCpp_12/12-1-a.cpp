#include <iostream>
#include "Derived.h"
 
int main() {
	Derived derived(5);
	std::cout << "\nderived is a " << derived.getName() 
			  << " and has value " << derived.getValue();
 
	Derived &rDerived = derived;
	std::cout << "\nrDerived is a " << rDerived.getName() 
			  << " and has value " << rDerived.getValue();
 
	Derived *pDerived = &derived;
	std::cout << "\npDerived is a " << pDerived->getName() 
			  << " and has value " << pDerived->getValue();
}