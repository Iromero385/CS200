#include <iostream>
using namespace std;

class Rectangle {
  private:
    double width, length; 
  public:
    class NegativeWidth { // Exception Class 
      private:
         int value;
      public:
          NegativeWidth(int val) { value = val; }
          int getValue() const { return value; }
      };

    class NegativeLength { // Exception class
      private:
        int value;
      public:
        NegativeLength(int val) { value = val; }
        int getValue() const { return value; }
    };

    // Basic Methods
    Rectangle() { width = 0.0; length = 0.0; }
    void setWidth(double w) {
        if (w >= 0) width = w;
        else throw NegativeWidth(w);
    };
    void setLength(double len) {
        if (len >= 0) length = len;
        else throw NegativeLength(len);
    };
    double getWidth() const { return width; };
    double getLength() const { return length; };
    double getArea() const { return width * length; };
};

int main() {
    int width, length;
    
    Rectangle myRectangle;
    cout << "Enter the rectangle's width: ";
    cin >> width;
    cout << "Enter the rectangle's length: ";
    cin >> length;
    
    try {
        myRectangle.setWidth(width);
        myRectangle.setLength(length);
        cout << "The area of the rectangle is " << myRectangle.getArea() << endl;
    } catch (Rectangle::NegativeWidth e) {
        cout << "Error: " << e.getValue() << " is an invalid value for the width.\n";
    } catch (Rectangle::NegativeLength e) {
        cout << "Error: " << e.getValue() << " is an invalid value for the length.\n";
    }
    cout << "\nExit program!";
}