// Chapter 14, Programming Challenge 12: LandTract Class
#include <iostream>
#include <sstream>
#include "FeetInches.h"
#include "LandTract.h"
using namespace std;

void menu();

int main()
{
    bool stay = true;                   // Boolean to stay in this menu
    string choice, word, text;   // User input for choices and input
    // int feet, inches;
    FeetInches width, length;
    LandTract myProperty;
    auto menu = [] ( ) {
    	cout << "_______ LandTract Class Test Menu __________\n"
    	     << "    m - menu\n"
    		 << "    n - new LandTract\n"
    		 << "    d - display the LandTract attributes\n"
    		 << "    q - Quit\n";

        };
        menu();
	while(stay) {           // Main menu while starts
        cout << "    Enter your choice: ";
		cin >> choice;      // Take in user choice from menu
		cin.ignore();
		char ch = choice[0];

		switch(ch) { // menu switch start
            case 'n':
            case 'N': // new LandTract
            {
                cout << "      Enter Tract Width in Feet, then Inches: \n";
                // fill the blank for inputting width 
                
                
                cout << "      Enter Tract Length in Feet, then Inches: \n";
                // fill the blank for inputting length
                
                
                cout << endl;
                break;
            }
            case 'd': 
            case 'D': // Display this LandTract
            {
                // Display the area.
            	cout << "      the width is " << myProperty.getWidth()
            	     << "\n      the length is " << myProperty.getLength()
            	     << "\n      the area is " << myProperty.getArea()
            	     << "\n\n";
                break;
            }

            case 'm': case 'M': 
                menu(); break;
            case 'q': case 'Q': // quit
				stay = false;
				break;

			default: // Invalid! Tells user to try again
				cout << "\nInvalid command!\nTry again!\n\n";
        }
    }
    cout << "\nProgram exit!";
}

