// arrover2.cpp
// creates safe array (index values are checked before access)
// uses one access() function for both put and get
#include <iostream>
#include <cstdlib> // exit()
using namespace std;
const int LIMIT = 10; //array size

class SafeAray {
int arr[LIMIT];
public:
	// the get() was return by value, 
	// the return value was destroyed along with call stack
	int& access(int n) {// fix: return by reference LearnCPP 7.4a
		if( n< 0 || n>=LIMIT ) {
			cout << "\nIndex out of bounds"; exit(1); }
		return arr[n];
	}
};

////////////////////////////////////////////////////////////////
int main() {
	SafeAray sa;
	for(int j=0; j<LIMIT; j++) 
	// assign elements into *left* side of equal sign
		sa.access(j) = j*10;   
	for(int j=0; j<LIMIT; j++) { //*right* side of equal sign
		cout << "Element " << j << " is " << sa.access(j) << endl;
	}
}