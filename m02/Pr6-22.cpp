// This program uses a static local variable.
#include <iostream>
using namespace std;

void showStatic(); // Function prototype

int main() {
	for (int count = 0; count < 5; count++)
		showStatic();
}

void showStatic() {
	static int statNum = 0;
	cout << "statNum is " << statNum << endl;
	statNum++;
} 