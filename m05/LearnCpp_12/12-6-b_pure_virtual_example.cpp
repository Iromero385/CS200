#include <iostream>
#include <string>

class Animal {
protected:
	std::string m_name;
	// We're making this constructor protected because
	// we don't want people creating Animal objects directly,
	// but we still want derived classes to be able to use it.
	Animal(std::string name) : m_name(name) { }
public:
	std::string getName() { return m_name; }
	virtual const char* speak(); // { return "???"; }
};

// an external body for virtual
const char* Animal::speak() { return "buzz"; }
 
class Dog: public Animal {
public:
	Dog(std::string name) : Animal(name) { }
	virtual const char* speak() { return "Woof"; }
};

class Cow: public Animal {
public:
	Cow(std::string name) : Animal(name) { }
 
	// We forgot to redefine speak
};
 
int main() {
	Dog dog("Garbo");
	std::cout << dog.getName() << " says " << dog.speak() << '\n';
		
	Animal &animal = dog;
	std::cout << animal.getName() << " says " << animal.speak() << "\n";
	
	Cow cow("Betsy");
	std::cout << cow.getName() << " says " << cow.speak() << '\n';
}