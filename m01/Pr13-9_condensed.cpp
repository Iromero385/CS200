// This program demonstrates passing an argument to a constructor.
#include <iostream>
#include <iomanip>
using namespace std;

class Sale {
   double itemCost, taxRate; 
public:
   Sale(double cost, double rate) { itemCost = cost; taxRate = rate; }
   double getItemCost() const { return itemCost; }
   double getTaxRate() const { return taxRate; }
   double getTax() const { return (itemCost * taxRate); }
   double getTotal() const { return (itemCost + getTax()); }
};

int main() {
	const double TAX_RATE = 0.06;   // 6 percent sales tax rate
	double cost;			        // To hold the item cost
	cout << "Enter the cost of the item: ";
	cin >> cost;
	
	Sale itemSale(cost, TAX_RATE);
	Sale *proj = new Sale(cost, TAX_RATE);
	
	cout << fixed << showpoint << setprecision(2)
	     << "The amount of sales tax is $" << itemSale.getTax() 
	     << "\nThe total of the sale is $"
	     << itemSale.getTotal();
	     
	cout << "\n\nThe projected sales is " << cost
	     << "\nThe amount of sales tax is $" << proj->getTax() 
	     << "\nThe total of the sale is $"
	     << proj->getTotal();
}