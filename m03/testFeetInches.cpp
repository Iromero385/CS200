#include<iostream>
#include "FeetInches.h"

using namespace std;

int main() {
	FeetInches first, second("3'4\""), third("4'9\"");
	auto show = [&]() {
	    cout << "first: " << first
	     << "; second: " << second
	     << "; third: " << third << endl; };
	
	show();
	cout << "Binary operator demo:\n";
	first = second + third; // Math expression
    show();
    // C++ operator expression
    first.operator= ( second.operator+( third ) );
    show();
}