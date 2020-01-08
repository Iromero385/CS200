// standard struct usage
#include <iostream>
using namespace std;

class Tripple {
    int x=1, y=2, z; 
public:
    void setZ(int i) { z=i; };
    void show(Tripple t) { 
        cout << "show(): [" << t.x << ", " << t.y << ", " << t.z << "]\n"; };
    void increase(Tripple &t) { t.x++; t.y++; t.z++; };
};

int main() {
    Tripple t;
    t.setZ(3);
         
    t.show(t);
    cout << "increasse();\n";
    t.increase(t);
    t.show(t);
}