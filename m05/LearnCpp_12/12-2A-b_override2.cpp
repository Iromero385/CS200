#include <iostream>

class A {
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
	virtual const char* getName3(int x) { return "A"; }
};
 
class B : public A {
public:
	// compile error, function is not an override
	// virtual const char* getName1(short int x) override { return "B"; } 

	// compile error, function is not an override
	// virtual const char* getName2(int x) const override { return "B"; } 

	// Two identical overrides of A::getName3(int) function
	// the 'override' is not a keyword, but grammar sugar, hence duplication!
	// virtual const char* getName3(int x) override { return "B"; }
	virtual const char* getName3(int x) { return "B"; }
};
 
int main() {
	B b;
	A &rBase = b;
	std::cout << rBase.getName3(1) << '\n';
}