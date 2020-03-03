#include <string>
#include <iostream>
 
class Animal {
protected:
	std::string m_name;

	Animal(std::string name) : m_name(name) { }
public:
	std::string getName() { return m_name; }
	const char* speak() { return "???"; }
};
 
class Cat: public Animal{
public:
	Cat(std::string name) : Animal(name) { }
 
	const char* speak() { return "Meow"; }
};
 
class Dog: public Animal {
public:
	Dog(std::string name) : Animal(name) { }
	const char* speak() { return "Woof"; }
};

void report(Cat &cat) {
	std::cout << cat.getName() << " says " << cat.speak() << '\n';
}
 
void report(Dog &dog) {
	std::cout << dog.getName() << " says " << dog.speak() << '\n';
}
 
int main() {
	Cat cats[] = { Cat("Fred"), Cat("Misty"), Cat("Zeke") };
	Dog dogs[] = { Dog("Garbo"), Dog("Pooky"), Dog("Truffle") };
 
	for (int iii=0; iii < 3; ++iii)
		std::cout << cats[iii].getName() << " says "
				  << cats[iii].speak() << '\n';
 
	for (int iii=0; iii < 3; ++iii)
		std::cout << dogs[iii].getName() << " says " 
				  << dogs[iii].speak() << '\n';
}