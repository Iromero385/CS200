#ifndef M01_08_H
#define M01_08_H

class Rectangle {
private:
    double width;
    double length;
public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

void Rectangle::setWidth(double w) {width=w;};
void Rectangle::setLength(double l) {length=l;};
double Rectangle::getWidth() const {return width;};
double Rectangle::getLength() const {return length;};
double Rectangle::getArea() const {return width*length;};
#endif