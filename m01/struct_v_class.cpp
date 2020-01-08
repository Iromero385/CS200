// standard struct usage
#include <iostream>
using namespace std;

struct Tripple { int x=1, y=2, z; };

void show(Tripple t) { 
    cout << "show(): [" << t.x << ", " << t.y << ", " << t.z << "]\n"; }
    
void increase(Tripple &t) { t.x++; t.y++; t.z++; }

int main() {
    Tripple t;
    t.z = 3;
         
    show(t);
    cout << "increasse();\n";
    increase(t);
    show(t);
}