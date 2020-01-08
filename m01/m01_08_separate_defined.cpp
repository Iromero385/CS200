#include "m01_08.h"
#include "m01_08.h"
#include <iostream>
using namespace std;

// class Rectangle {
// private:
//     double width;
//     double length;
// public:
//     void setWidth(double);
//     void setLength(double);
//     double getWidth() const;
//     double getLength() const;
//     double getArea() const;
// };

// void Rectangle::setWidth(double w) {width=w;};
// void Rectangle::setLength(double l) {length=l;};
// double Rectangle::getWidth() const {return width;};
// double Rectangle::getLength() const {return length;};
// double Rectangle::getArea() const {return width*length;};

int main() {
    Rectangle r;
    r.setWidth(3); r.setLength(4);
    cout << "I have created a " << r.getWidth() << " by "
         << r.getLength() << " Rectangle with area of "
         << r.getArea();
}