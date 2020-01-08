// This program demonstrates a static member function.
#include <iostream>
#include <iomanip>
using namespace std;

class Budget {
	static double corpBudget;  // Static member variable
	double divisionBudget;	  // Instance member variable
public:
	Budget() { divisionBudget = 0; }
	void addBudget(double b)
		{ divisionBudget += b; corpBudget += b; }
	double getDivisionBudget() const { return divisionBudget; }
	double getCorpBudget() const { return corpBudget; }
static void mainOffice(double);  // Static member function
};
    double Budget::corpBudget = 0;
void Budget::mainOffice(double moffice) { corpBudget += moffice; }

int main() {
	int count;					// Loop counter
	const int NUM_DIVISIONS = 4;// Number of divisions	double mainOfficeRequest;	// Main office budget request

// Get the main office's budget request.
// Note that no instances of the Budget class have been defined.
double mainOfficeRequest;	// Main office budget request
cout << "Enter the main office's budget request: ";
cin >> mainOfficeRequest;
Budget::mainOffice(mainOfficeRequest);

	Budget divisions[NUM_DIVISIONS]; // An array of Budget objects.

	// Get the budget requests for each division.
	for (count = 0; count < NUM_DIVISIONS; count++) {
		double budgetAmount;
		cout << "Enter the budget request for division ";
		cout << (count + 1) << ": ";
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