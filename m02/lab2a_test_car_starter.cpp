#include<iostream>
#include<string>
using namespace std;

class Car{
    int year, speed;
    string make;

public:
    // constructors
    Car( int y, string m );
    Car( Car &c );
    // getters
    int getYear();
    string getMake();
    int getSpeed();
    // setters
    void setYear( int y );
    void setMake( string  m );
    void accelerate( );
    void brake( );
};

int main() {
    Car tesla(2019, "S3");
    cout << "My Tesla is at " << tesla.getSpeed() << " m/h.\n";
    for( int count =0; count < 10; count++ ) {
        tesla.accelerate();
        cout << "My Tesla is at " << tesla.getSpeed() << " m/h.\n";
    }
    // ...
    // continue to drive to the destination
}