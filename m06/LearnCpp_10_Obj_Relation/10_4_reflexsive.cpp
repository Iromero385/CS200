#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Course {
    string m_name;
    Course *m_prerequisite;
 
public:
    Course(string name, Course *prerequisite=nullptr):
        m_name(name), m_prerequisite(prerequisite) { }
    string getName() { return m_name; }
    string getPrereqName() { return  m_prerequisite->m_name; }
    bool prereq() { return (m_prerequisite != nullptr); }
};

int main() {
    Course cs100("COMSC-100");
    Course cs110("COMSC-110", &cs100);
    Course cs165("COMSC-165", &cs110);
    Course cs200("COMSC-200", &cs165);
    auto show = [](Course c) {
        cout << c.getName() << " <- "
             <<  ( (c.prereq()) ? c.getPrereqName() : "" )
             << endl; 
    };

    show(cs100);
    show(cs110);
    show(cs165);
    show(cs200);
}