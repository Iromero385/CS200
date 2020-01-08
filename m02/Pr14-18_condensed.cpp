#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person {
	char *name;
public:
	Person() {
		cout << "*** default constructor ***\n";
		name = nullptr; }
 
	Person(char *n) {
		cout << "*** parameterized constructor ***\n";
		name = new char[strlen(n) + 1];
		strcpy(name, n); }

	// Copy constructor
	Person(const Person &obj) {
		cout << "*** copy constructor ***\n";
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name); }

	~Person() {
		cout << "*** destructor ***\n";
		delete name; }

	// Overloaded = operator
	Person & operator=(const Person &right) {
		cout << "*** assignment operator ***\n";
		if (this != &right) {
			if (name != nullptr)
				delete[] name;
			name = new char[strlen(right.name) + 1];
			strcpy(name, right.name);
		}
		return *this; }

	// getName member function
	char *getName() const
	{  return name; }
};

// Function prototype
Person makePerson();
void displayPerson(Person);

int main() {
	Person person;
	person = makePerson();
	displayPerson(person);
	return 0;
}

Person makePerson() {
	Person p("Will MacKenzie");
	return p;
}

void displayPerson(Person p2) {
	cout << p2.getName() << endl;
}