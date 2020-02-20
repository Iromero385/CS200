#include <iostream>
using namespace std;

class Rectangle {
	double width, length;
public:
	// Default constructor
	Rectangle() { width = 0.0; length = 0.0; }

	// Constructor #2
	Rectangle(double w, double len) { width = w; length = len; }
	double getWidth() const { return width; }
	double getLength() const { return length; }
	double getArea() const { return width * length; }
};

class Box : public Rectangle {
protected:
	double height;
	double volume;
public:
	// Default constructor
	Box() : Rectangle()
	{ height = 0.0; volume = 0.0; }
		
	// Constructor #2
	Box(double w, double len, double h) : Rectangle(w, len)
	{ height = h;
	  volume = getArea() * h; }

	double getHeight() const
	{ return height; }
	
	double getVolume() const
	{ return volume; }
};


int main() {
	double boxWidth;	// To hold the box's width
	double boxLength;  // To hold the box's length
	double boxHeight;  // To hold the box's height

	// Get the width, length, and height from the user.
	cout << "Enter the dimensions of a box:\n"
	     << "Width: ";
	cin >> boxWidth;
	cout << "Length: ";
	cin >> boxLength;
	cout << "Height: ";
	cin >> boxHeight;

	// Define a Box object.
	Box myBox(boxWidth, boxLength, boxHeight);

	// Display the Box object's properties.
	cout << "Here are the box's properties:"
	     << "\nWidth: " << myBox.getWidth()
	     << "\nLength: " << myBox.getLength()
    	 << "\nHeight: " << myBox.getHeight()
	     << "\nBase area: " << myBox.getArea()
	     << "\nVolume: " << myBox.getVolume();

}