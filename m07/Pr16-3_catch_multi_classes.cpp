#include <iostream>
using namespace std;

class Rectangle {
  private:
    double width, length;      
  public:
    class NegativeWidth { }; // Exception class for each element
    class NegativeLength { };
    Rectangle() { width = 0.0; length = 0.0; }
    void setWidth(double w) {
        if (w >= 0) width = w;
        else throw NegativeWidth();
    };
    void setLength(double len){
        if (len >= 0) length = len;
        else throw NegativeLength();
    };
    double getWidth() const { return width; };
    double getLength() const { return length; };
    double getArea() const { return width * length; };
};

int main() {
    int width, length;
    
    // Create a Rectangle object.
    Rectangle myRectangle;

    // Get the width and length.
    cout << "Enter the rectangle's width: ";
    cin >> width;
    cout << "Enter the rectangle's length: ";
    cin >> length;
    
    try {
        myRectangle.setWidth(width);
        myRectangle.setLength(length);
        cout << "The area of the rectangle is " << myRectangle.getArea() << endl;
    } catch (Rectangle::NegativeWidth) {
        cout << "Error: A negative value was given as width.\n";
    } catch (Rectangle::NegativeLength) {
        cout << "Error: A negative value was given as length.\n";
    }
}
