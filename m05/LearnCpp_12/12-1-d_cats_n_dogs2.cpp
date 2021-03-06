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

void report(Animal &rAnimal) {
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}
 
int main() {
    Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
 
    // Set up an array of pointers to animals, 
    // and set those pointers to our Cat and Dog objects
    Animal *animals[] = { &fred, &garbo, 
    	&misty, &pooky, &truffle, &zeke };
    for (int iii=0; iii < 6; ++iii)
        std::cout << animals[iii]->getName() << " says " 
        		  << animals[iii]->speak() << '\n';
}
