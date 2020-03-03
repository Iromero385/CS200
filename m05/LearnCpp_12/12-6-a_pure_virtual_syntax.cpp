class Base {
public:
	const char* sayHi() { return "Hi"; } // a normal non-virtual function	
 
	virtual const char* getName() { return "Base"; } // a normal virtual function
 
	virtual int getValue() = 0; // a pure virtual function
 
	int doSomething() = 0; // Compile error: can not set non-virtual functions to 0
};

int main() {
	Base base; // We can't instantiate an abstract base class, but for the sake of example, pretend this was allowed
	base.getValue(); // what would this do?
}