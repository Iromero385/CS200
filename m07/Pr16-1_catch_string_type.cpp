// 16.1 an exception being thrown and caught.
#include <iostream>
#include <string>
using namespace std;

double divide(int numerator, int denominator) {
    if (denominator == 0) {
         string exceptionString = "ERROR: Cannot divide by zero.\n";
         throw exceptionString;
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num1, num2;  // To hold two numbers
    double quotient; // To hold the quotient of the numbers

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    try { // Divide num1 by num2 and catch any potential exceptions.
         quotient = divide(num1, num2);
         cout << "The quotient is " << quotient << endl;
    } catch (string e) {
         cout << e;
    }
}