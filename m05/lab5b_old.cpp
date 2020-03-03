//  Lab5B: Pure Abstract Base Class

//	Driver program for testing
//  BasicShape (Abstract Base Class), 
//  Circle (Derived Class) and 
//  Rectangle (Derived class).


#include <iostream>
#include "Circle.h"
#include "Rectangle.h" // you may combine files anyway you choose to
using namespace std;

int main() {
	long x, y, length, width;
	double rad;

	// Demonstrate a Circle.
	cout << "Please enter the coordinate of the circle's center: ";
	cin >> x >> y;
	cout << "Please enter the radius of the circle: ";
	cin >> rad;
	Circle c(x,y,rad);
	cout << "The area of the circle is " << c.getArea() << ".";

	// Demonstrate a Rectangle.
	cout << "\n\nPlease enter the width and length of the rectangle: ";
	cin >> width >> length;
	Rectangle r(width, length);
	cout << "The area of the rectangle is " << r.getArea() << ".\n";

	return 0;
}

