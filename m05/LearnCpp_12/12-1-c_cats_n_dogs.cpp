#include <string>
#include <iostream>
 
class Animal {
protected:
	std::string m_name;
 
	// We're making this constructor protected because
	// we don't want people creating Animal objects directly,
	// but we still want derived classes to be able to use it.
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
 
int main() {
	Cat cat("Fred");
	std::cout << "\ncat is named " << cat.getName() 
	          << ", and it says " << cat.speak();
 
	Dog dog("Garbo");
	std::cout << "\ndog is named " << dog.getName() 
	          << ", and it says " << dog.speak();
 
	Animal *pAnimal = &cat;
	std::cout << "\npAnimal is named " << pAnimal->getName() 
	          << ", and it says " << pAnimal->speak();
 
	pAnimal = &dog;
	std::cout << "\npAnimal is named " << pAnimal->getName() 
	          << ", and it says " << pAnimal->speak();
}