#include <iostream>
using namespace std;

// (Friend step 1) Forward Declaration 
class FeetInches;	

// (Friend step 2) Forward Declaration of Friend Function
ostream &operator << (ostream &, const FeetInches &);
istream &operator >> (istream &, FeetInches &);

class FeetInches {
	int feet;		// To hold a number of feet
	int inches;		 // To hold a number of inches
	void simplify();// header only Definition below
public:
	// argument constructor
	FeetInches(int f = 0, int i = 0) 
		{ feet = f; inches = i; simplify(); }
	// copy constructor - must 1. pass ref var.
	FeetInches (const FeetInches &fi) 
		{ feet = fi.feet; inches = fi.inches; simplify(); }
	// assignment operator
	FeetInches operator= (const FeetInches &right)
		{ feet = right.feet; inches = right.inches; simplify(); }
	// Mutator
	void setFeet(int f) { feet = f; }
	void setInches(int i) { inches = i; simplify(); }
	// Accessor 
	int getFeet() const { return feet; }
	int getInches() const { return inches; }

	// Overloaded operator functions      
	FeetInches operator + (const FeetInches &);	// Overloaded + 
	FeetInches operator - (const FeetInches &);	// Overloaded -
	FeetInches operator ++ ();					// Prefix ++      
	FeetInches operator ++ (int);				// Postfix ++  
	bool operator > (const FeetInches &);		// Overloaded >  
	bool operator < (const FeetInches &);		// Overloaded <
	bool operator == (const FeetInches &);		// Overloaded ==

	// Object Type Converter declaration
	operator int() { return feet; } 
	operator double() {
		double temp = feet; temp += (inches / 12.0); return temp; } 
		
    // (Friends Step 3) Friend Function Declaration
	friend ostream &operator << (ostream &, const FeetInches &);
	friend istream &operator >> (istream &, FeetInches &);
};
	
void FeetInches::simplify(){
	if (inches >= 12) {
		feet += (inches / 12);
		inches = inches % 12; }
	else if (inches < 0) {
		feet -= ((abs(inches) / 12) + 1);	// quotion for feets
		inches = 12 - (abs(inches) % 12); }	// remainder for inches
	if( feet < 0 && inches >0 ) { feet += 1; inches -= 12; }
}

//*********************************************************
// Overloaded binary + and - operator.	int	result = a + b;
//*********************************************************

FeetInches FeetInches::operator + (const FeetInches &right) { 
	FeetInches temp;
	temp.inches = inches + right.inches; 
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp; 
}

FeetInches FeetInches::operator - (const FeetInches &right) {
	FeetInches temp;
	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();  
	return temp;
} 

//**********************************************************
// Overloaded unary pre and postfix ++ operator.		
//**********************************************************
FeetInches FeetInches::operator++() { // prefix increment
	++inches;
	simplify();
	return *this;
}  // a = (myself+1) + b

FeetInches FeetInches::operator++(int) { 
	FeetInches temp(feet, inches);  // keep my old picture
	inches++;                       // increase myself == 3
	simplify();
	return temp;                    // return my old picture
}          

//************************************************************
// Overloaded comparator operator.  
//************************************************************

bool FeetInches::operator > (const FeetInches &right) {
	if (feet > right.feet)  return true;
	if (feet == right.feet && inches > right.inches)
		return true;
	return false;
}


bool FeetInches::operator < (const FeetInches &right) {
	if (feet < right.feet) return true;
	if (feet == right.feet && inches < right.inches)
		return true;
	return false;
}

bool FeetInches::operator == (const FeetInches &right) {
	if (feet == right.feet && inches == right.inches)
		return true;
	return false;
}

//************************************************************
// (Friend step 4) Friend Function Definition
// Overloaded stream operator << and >>
//************************************************************
ostream &operator << (ostream &strm, const FeetInches &rhs) {
    strm << rhs.feet << "\' " << rhs.inches << "\" "; 
    return strm;
}

istream &operator >> (istream &strm, FeetInches &rhs) {
    char c; // 3'5"
    strm >> rhs.feet;
    strm >> c;
    strm >> rhs.inches;
    rhs.simplify();
    return strm;
}

//////////// main application //////////////
int main() {
	int feet, inches;
	FeetInches first, second, third;

	cout << "Enter a distance in feet and inches: ";
	cin >> feet >> inches;

	// Store the distance in the first object.
	first.setFeet(feet);
	first.setInches(inches);
	
	// copy construct
	FeetInches copyCon(first);

	// Get another distance from the user.
	cout << "Enter another distance in feet and inches: ";
	cin >> feet >> inches;

	// Store the distance in second.
	second.setFeet(feet);
	second.setInches(inches);

	// Assign first + second to third.
	third = first + second;

	// Display the result.
	// Compare the two objects.
	if (first == second)
		cout << "first and second are equal.\n";
	else if (first > second)
		cout << "first is greater than second.\n";
	else 
		cout << "first is less than second.\n";
		
	// Display the result.
	cout << "\nfirst + second = ";
	cout << third.getFeet() << " feet, ";
	cout << third.getInches() << " inches.\n";

	// Assign first - second to third.
	third = first - second;

	// Display the result.
	cout << "first - second = ";
	cout << third.getFeet() << " feet, ";
	cout << third.getInches() << " inches.\n";
	
	// test comparator
	// cout << ( first > second ) ? "first  is larger than second\n" :
	// 		( ( first == second ) ? "first and second are the same.\n"
	// 							  : "first is less than second " ) ;
	
	// Convert type and show third as int and double
	int i; i = third; 
	double d; d = third;
	cout << "\nObject 'third' Type Convertion:"
		 << "\nto integer: " << i 
		 << "\nto double: " << d;
		 
	// Alternatively
	cout << "\nUse int constructor instead: "
		 << "\nto integer: " << int(third)
		 << "\nto double: " << double(third);
	
	
	// Use the prefix ++ operator.
	cout << "\n\nDemonstrating prefix ++ operator.\n";
	for (int count = 0; count < 4; count++) {
		first = ++second;
		cout << "first: " << first.getFeet() << " feet, ";
		cout << first.getInches() << " inches. ";
		cout << "second: " << second.getFeet() << " feet, ";
		cout << second.getInches() << " inches.\n";
	}

	// Use the postfix ++ operator.
	cout << "\nDemonstrating postfix ++ operator.\n";
	for (int count = 0; count < 4; count++) {
		first = second++;
		cout << "first: " << first.getFeet() << " feet, ";
		cout << first.getInches() << " inches. ";
		cout << "second: " << second.getFeet() << " feet, ";
		cout << second.getInches() << " inches.\n";
	}
	
	// Help from overloaded (Friend) stream operator >> then << 
	cout << "\nShow the last result by a friend << " <<  second;
	cout << "\nEnter a new FeetInches (in 3'5\" format):  ";
	cin >> first;
	cout << "You have entered " << first << endl;
	for (int count = 0; count < 4; count++) 
		cout << first++ << endl;
	
}