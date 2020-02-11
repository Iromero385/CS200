/////////////////////////////////////////////////////////////
// This starter is a one-file all inclusive test appliation.
// This starter combines with the necessary Frac definition.
// Do not re-include the Frac.h
// If you prefer a multiple file approach, separte them cleanly.
/////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <sstream> // stringstream

using namespace std;

class Frac;
ostream &operator<< (ostream &stm, Frac const &rhs);

class Frac {
	long num;
	long den;
public:
	// Frac() { num=0; den=1; }
	Frac() : num(0), den(1) {}
	Frac(long n, long d) {num=n; den=d;}
	Frac(const Frac &obj) {*this = obj;}
	void operator=(const Frac &rhs) { 
		num = rhs.num;  den = rhs.den;
	}   // Frac a = b;
	
	// string constructor is challenging, worth 2 pts, try your best! 
	Frac(string s);
	
	// math operators
	Frac operator+(const Frac &rhs) {
		Frac temp;
		temp.num = num*rhs.den + rhs.num*den;
		temp.den = den*rhs.den;
		// need to apply lower term by / gcd here
		return temp;
	}

	// postfix increment operator ++ --
	Frac operator++() { 
		num += den; 
		// lowterms(*this); 
		return *this; }
	
	Frac operator--() { 
		num -= den; 
		// lowterms(*this); 
		return *this; }
	
	// overload ostream insertion operator<<
	friend ostream &operator<< (ostream &stm, Frac const &rhs) {
		stm << rhs.num << "/" << rhs.den; }
};

int main() {
	Frac x(3,4);
	Frac y(1,2);
	cout << "\nCreated Frac x(3,4) as " << x;
	cout << "\nCreated Frac y(1,2) as " << y;
	

	// Turn on this one when you completed the definition of string constructor
	// Frac s("6/7"); // passing a Frac number as a string.
	// cout << "\nString constructed: s: " << s;

	
	Frac z(x);
	cout << "\nCopy constructed z as x: " << z;
	
	Frac v = x + y;
	cout << "\nx + y is: " << v;

	cout << "\nPlease observe the outputs of identical commands\n"
		 << " executed in one statement v. separated statements. \n";
	Frac f(5,6);
	cout << f << " "	 // start
		 << --f << " "  
		 << f << " "
		 << ++f << " " 
		 << --f << " " 
		 << ++f << endl; // end of one statement
		 
	cout << f << " " ; 
	cout << --f << " " ; 
	cout << f << " " ;
	cout << ++f << " " ; 
	cout << --f << " " ;
	cout << ++f;
	
	cout << "\nWhy the above output values are not the same?\n\n";
}