#include <iostream>

using namespace std;

int main() {
    string q="1+2*3"; // enQ(), deQ(), front(), rear()
    
    cout << q
         << "\n\tcout << q   is q.show()\n";
    
    cout << q[0]
         << "\n\tq[0]   is q.front()\n";
    
    cout << q[q.size()-1]
         << "\n\tq[q.size()-1]   is q.rear()\n";
    
    q += '^';
    cout << q
         << "\n\tq += '^'  is q.enQ('^')\n";
    
    q.erase(0,1);
    cout << q
         << "\n\tq.erase(0,1)  is q.deQ()\n";
}