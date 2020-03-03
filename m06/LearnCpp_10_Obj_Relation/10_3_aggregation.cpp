#include <string>
#include <iostream>

class Teacher {
	std::string m_name;
public:
	Teacher(std::string name) : m_name(name) { }
	std::string getName() { return m_name; }
};

class Department {
	Teacher *m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers
public:
	Department(Teacher *teacher = nullptr) : m_teacher(teacher) { }
};

int main() {
	// Create a teacher outside the scope of the Department
	Teacher *teacher = new Teacher("Bob"); // create a teacher
{
	// Create a department and use the constructor parameter to pass
	// the teacher to it.
	Department dept(teacher);
} // dept goes out of scope here and is destroyed

	// Teacher still exists here because dept did not delete m_teacher
	std::cout << teacher->getName() << " still exists!\n";
	delete teacher;
}