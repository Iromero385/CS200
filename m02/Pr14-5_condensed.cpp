// This program demonstrates memberwise assignment.
#include <iostream>
using namespace std;

class Rectangle {
	double width, length;
public:
	Rectangle(double w, double l) { // Argument Constructor
		width = w; length = l; }
	Rectangle(Rectangle &r) { // Copy Constructor
		width = r.width; length = r.length; }
	Rectangle operator=(Rectangle &r) // Assignment Operator
		r.width = width; r.length = length; }
	void setWidth(double);
	void setLength(double);
	
	double getWidth() const { return width; }
	double getLength() const { return length; }
	double getArea() const { return width * length; }
};

int main()
{
	// Define two Rectangle objects.
	Rectangle box1(10.0, 10.0);	// width = 10.0, length = 10.0
	Rectangle box2 (20.0, 20.0);  // width = 20.0, length = 20.0
	
	// Display each object's width and length.
	auto show = [](Rectangle box, string name) {
		cout << name <<"'s width and length: " << box.getWidth() 
			 << " " << box.getLength() << endl;	 
	};
	show(box1, "box1");
	show(box2, "box2");
//	cout << "box1's width and length: " << box1.getWidth() 
//			<< " " << box1.getLength() << endl;
//	cout << "box2's width and length: " << box2.getWidth() 
//			<< " " << box2.getLength() << endl << endl;

	box2 = box1;
	show(box1, "box1");
	show(box2, "box2");
// 	cout << "box1's width and length: " << box.getWidth() 
// 		  << " " << box.getLength() << endl;
// 	cout << "box2's width and length: " << box.getWidth() 
// 		  << " " << box.getLength() << endl;
	
	return 0;
}

