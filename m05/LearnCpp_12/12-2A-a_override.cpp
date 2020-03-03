#include <iostream>

class A {
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
};
 
class B : public A {
public:
    // no override: parameter is a short int
	virtual const char* getName1(short int x) { return "B"; } 
	// no override: function is const
	virtual const char* getName2(int x) const { return "B"; } 
};

class C : public A {
public:
    // override works
	virtual const char* getName1(int x) { return "C"; } 
	virtual const char* getName2(int x) { return "C"; } 
};
 
int main() {
    C c;
	B b;
	A &rBase = b, &rBase2 = c;

	std::cout << rBase.getName1(1) << '\n';
	std::cout << rBase.getName2(2) << '\n';
	std::cout << rBase2.getName1(3) << '\n';
	std::cout << rBase2.getName2(4) << '\n';
}