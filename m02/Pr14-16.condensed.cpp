// Stock trader program
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Stock {
	string symbol;		// Trading symbol of the stock
	double sharePrice;	// Current price per share
public:
	Stock() { set("", 0.0); }
	Stock(const string sym, double price) { set(sym, price); }
	Stock(const Stock &obj) { set(obj.symbol, obj.sharePrice); }
	void set(string sym, double price) { symbol = sym; sharePrice = price; }
	string getSymbol() const { return symbol; }
	double getSharePrice() const { return sharePrice; }
};

class StockPurchase {
	Stock stock;  // The stock that was purchased
	int shares;	// The number of shares
public:
	// The default constructor sets shares to 0. The stock
	// object is initialized by its default constructor.
	StockPurchase() { shares = 0; }
	
	StockPurchase(const Stock &stockObject, int numShares)
		{ stock = stockObject; shares = numShares; }
		  
	double getCost() const
		{  return shares * stock.getSharePrice(); }
};

int main() {
	int sharesToBuy;  // Number of shares to buy
	
	// Create a Stock object for the company stock. The
	// trading symbol is XYZ and the stock is currently
	// priced at $9.62 per share.
	Stock xyzCompany("XYZ", 9.62);
	
	// Display the symbol and current share price.
	cout << setprecision(2) << fixed << showpoint
	     << "XYZ Company's trading symbol is "
		 << xyzCompany.getSymbol() << endl
		 << "The stock is currently $"
		 << xyzCompany.getSharePrice()
		 << " per share.\n";
	
	// Get the number of shares to purchase.
	cout << "How many shares do you want to buy? ";
	cin >> sharesToBuy;
	
	// Create a StockPurchase object for the transaction.
	StockPurchase buy(xyzCompany, sharesToBuy);
	
	// Display the cost of the transaction.
	cout << "The cost of the transaction is $"
		 << buy.getCost() << endl;
} 