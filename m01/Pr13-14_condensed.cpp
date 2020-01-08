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

int main() {
	const int NUM_ITEMS = 6;
	InventoryItem inventory[NUM_ITEMS] = {
	                InventoryItem("Saw"),
					InventoryItem("Hammer", 6.95, 12),
					InventoryItem("Wrench", 8.75, 20),
					InventoryItem("Pliers", 3.75, 10),
					InventoryItem("Ratchet", 7.95, 14),
					InventoryItem("Screwdriver", 2.50, 22) };

	cout << setw(14) << "Inventory Item"
		 << setw(8) << "Cost" << setw(8)
		 << setw(16) << "Units on Hand\n"
	     << "-------------------------------------\n";

	for (int i = 0; i < NUM_ITEMS; i++) {
		cout << setw(14) << inventory[i].getDescription();
		cout << setw(8) << inventory[i].getCost();
		cout << setw(7) << inventory[i].getUnits() << endl;
	}
}