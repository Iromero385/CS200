// creates safe array (index values are checked before access)
// uses separate put and get functions
#include <iostream>
#include <cstdlib> // exit()
using namespace std;
const int LIMIT = 10;

////////////////////////////////////////////////////////////////
class SafeArray{
    int arr[LIMIT];
public:
    void put(int n, int value) {//set value of element  // safe.put (index, right);
        if( n< 0 || n>=LIMIT ) {
            cout << "\nIndex out of bounds"; exit(1); }
        arr[n] = value; } // a repeat of implicit operator=
        
    int get(int n) const { //get value of element   // safe.get(index);
        if( n< 0 || n>=LIMIT ) {  
            cout << "\nIndex out of bounds"; exit(1); }
        return arr[n];
    }
};

////////////////////////////////////////////////////////////////
int main() {
    SafeArray sa;
    for(int j=0; j<LIMIT; j++) {// insert elements
        sa.put(j, j*10); cout << j << ' '; }
    cout << "the sa is initialized!\n";
    for(int j=0; j<LIMIT; j++) // display elements
        cout << "Element " << j << " is " << sa.get(j) << endl;
}