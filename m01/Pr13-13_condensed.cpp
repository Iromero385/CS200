// This program demonstrates a class with overloaded constructors.
// This class has overloaded constructors.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class InventoryItem {
   string description; // The item description
   double cost;        // The item cost
   int units;          // Number of units on hand
public:
    // Constructor #1 (default constructor)
    InventoryItem() { 
		description = "";
        cost = 0.0;
        units = 0; }

    // Constructor #2
    InventoryItem(string desc) { 
        description = desc;
        cost = 0; units = 0; }
        
    // Constructor #3
    InventoryItem(string desc, double c, int u) { 
		description = desc; cost = c; units = u; }

    // Mutator functions
    void setDescription(string d) { description = d; }
    void setCost(double c) { cost = c; }
    void setUnits(int u) { units = u; }
    
    // Accessor functions
    string getDescription() { return description; }
    double getCost() { return cost; }
    int getUnits() const { return units; }
};


int main()
{
	// Create an InventoryItem object with constructor #1.
	InventoryItem item1;
	item1.setDescription("Hammer");	// Set the description
	item1.setCost(6.95);			      // Set the cost
	item1.setUnits(12);				   // Set the units

	// Create an InventoryItem object with constructor #2.
	InventoryItem item2("Pliers");

	// Create an InventoryItem object with constructor #3.
	InventoryItem item3("Wrench", 8.75, 20);

	cout << "The following items are in inventory:\n";
	cout << setprecision(2) << fixed << showpoint
	     << " -> Item 1: " << item1.getDescription() 
	     << "\nCost: $" << item1.getCost()
	     << "\nUnits on Hand: " << item1.getUnits() << endl;

	cout << " -> Item 2: " << item2.getDescription() 
	     << "\nCost: $" << item2.getCost()
	     << "\nUnits on Hand: " << item2.getUnits() << endl;

	cout << " -> Item 3: " << item3.getDescription() 
	     << "\nCost: $" << item3.getCost()
	     << "\nUnits on Hand: " << item3.getUnits() << endl;
	return 0;
}