#include <iostream>

class A {
public:
	virtual const char* getName() { return "A"; }
};
 
// class B final : public A // note use of final specifier here
class B : public A {
public:
	// note use of final specifier on following line -- that makes this function no longer overridable
	virtual const char* getName() override final { return "B"; } // okay, overrides A::getName()
};
 
class C : public B {
public:
// 	virtual const char* getName() override { return "C"; } // compile error: overrides B::getName(), which is final
};

int main() {
    C c;
	B &rB= c, b;
	A &rA = b;
	std::cout << rA.getName() << '\n';
	std::cout << rB.getName() << '\n';
}