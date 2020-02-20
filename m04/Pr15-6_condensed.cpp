// This program demonstrates the Car, Truck, and SUV
// classes that are derived from the Automobile class.
#include <iostream>
#include <iomanip>
using namespace std;

// The Automobile class holds automobile in inventory.
class Automobile { 
    string make; // The auto's make
    int model; // The auto's year model
    int mileage; // The auto's mileage
    double price; // The auto's price
    
    public:
    // Default constructor
    Automobile() { make = ""; model = 0; mileage = 0; price = 0.0; }
    
    // Constructor
    Automobile(string autoMake, int autoModel,
        int autoMileage, double autoPrice) {
            make = autoMake;
            model = autoModel;
            mileage = autoMileage;
            price = autoPrice; }
    
    string getMake() const { return make; }
    int getModel() const { return model; }
    int getMileage() const { return mileage; }
    double getPrice() const { return price; }
}; 



class Car : public Automobile {
   int doors;
public:
   Car() : Automobile() { doors = 0;}
   Car(string carMake, int carModel, int carMileage, double carPrice, int carDoors) :
       Automobile(carMake, carModel, carMileage, carPrice) { doors = carDoors; }
   
   // Accessor for doors attribute
   int getDoors() {return doors;}
}; 

class Truck : public Automobile {
   string driveType;
public:
   Truck() : Automobile() { driveType = ""; }
   Truck(string truckMake, int truckModel, int truckMileage,
       double truckPrice, string truckDriveType) :
           Automobile(truckMake, truckModel, truckMileage, truckPrice)
           { driveType = truckDriveType; }
   string getDriveType() { return driveType; }
}; 

class SUV : public Automobile {
   int passengers;
public:
   SUV() : Automobile() { passengers = 0; }
   SUV(string SUVMake, int SUVModel, int SUVMileage,
       double SUVPrice, int SUVPassengers) :
           Automobile(SUVMake, SUVModel, SUVMileage, SUVPrice)
           { passengers = SUVPassengers; }
   
   // Accessor for passengers attribute
   int getPassengers() {return passengers;}
}; 

int main()
{
  //   make, year, mileage, priced, capacity.
  Car car("BMW", 2007, 50000, 15000.0, 4);
  Truck truck("Toyota", 2006, 40000, 12000.0, "4WD");
  SUV suv("Volvo", 2005, 30000, 18000.0, 5);
  
  // Display the automobiles we have in inventory.
  cout << fixed << showpoint << setprecision(2)
       << "We have the following car in inventory:\n"
       << car.getModel() << " " << car.getMake()
       << " with " << car.getDoors() << " doors and "
       << car.getMileage() << " miles.\nPrice: $"
       << car.getPrice() << endl << endl;
  
  cout << "We have the following truck in inventory:\n"
       << truck.getModel() << " " << truck.getMake()
       << " with " << truck.getDriveType()
       << " drive type and " << truck.getMileage()
       << " miles.\nPrice: $" << truck.getPrice()
       << endl << endl;

  cout << "We have the following SUV in inventory:\n"
       << suv.getModel() << " " << suv.getMake()
       << " with " << suv.getMileage() << " miles and "
       << suv.getPassengers() << " passenger capacity.\n"
       << "Price: $" << suv.getPrice() << endl;
} 