// arrSubOver3.cpp
// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get

#include <iostream>
#include <cstdlib> // exit()
using namespace std;
const int LIMIT = 100; //array size
////////////////////////////////////////////////////////////////
class SafeAray {
    int arr[LIMIT];
public:
    int& operator [](int n) {// function name access overload to []
        if( n< 0 || n>=LIMIT ) {
            cout << "\nIndex out of bounds"; exit(1); }
        return arr[n];
    }
};

int main() {
    SafeAray sa;
        for(int j=0; j<LIMIT; j++) //insert elements
    sa[j] = j*10; //*left* side of equal sign
    for(int j=0; j<LIMIT; j++) { //display elements
        int temp = sa[j]; //*right* side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }
}
