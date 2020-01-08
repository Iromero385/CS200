#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;
public:
    void setWidth(double w) {width=w;};
    void setLength(double l) {length=l;};
    double getWidth() const {return width;};
    double getLength() const {return length;};
    double getArea() const {return width*length;};
};

int main() {
    Rectangle *rPtr = new Rectangle;
    rPtr->setWidth(3); rPtr->setLength(4);
    cout << "I have created a " << rPtr->getWidth() << " by "
         << rPtr->getLength() << " Rectangle with area of "
         << rPtr->getArea();
}