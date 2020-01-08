// This program demonstrates a static class member variable.
#include <iostream>
#include <iomanip>
using namespace std;

class Budget {
	static double corpBudget;  // Static member
	double divisionBudget;	  // Instance member
public:
	Budget() { divisionBudget = 0; }
	void addBudget(double b) { 
		divisionBudget += b; corpBudget += b; }
	double getDivisionBudget() const { return divisionBudget; }
	double getCorpBudget() const { return corpBudget; }
};

// Definition of static member variable corpBudget
double Budget::corpBudget = 0;

int main() {
	int count;						 // Loop counter
	const int NUM_DIVISIONS = 4;	 // Number of divisions
	Budget divisions[NUM_DIVISIONS]; // Array of Budget objects

	// Get the budget requests for each division.
	for (count = 0; count < NUM_DIVISIONS; count++) {
		double budgetAmount;
		cout << "Enter the budget request for division "
		     << (count + 1) << ": ";
		cin >> budgetAmount;
		divisions[count].addBudget(budgetAmount);
	}

	// Display the budget requests and the corporate budget.
	cout << fixed << showpoint << setprecision(2)
	     << "\nHere are the division budget requests:\n";
	for (count = 0; count < NUM_DIVISIONS; count++) {
		cout << "\tDivision " << (count + 1) << "\t$ "
		     << divisions[count].getDivisionBudget() << endl;
	}
	cout << "\tTotal Budget Requests:\t$ "
	     << divisions[0].getCorpBudget() << endl; 
}