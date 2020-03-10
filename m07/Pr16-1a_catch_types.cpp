//__________________________________________
// throw primitive types ...

#include <iostream>
#include <stdexcept>   // for runtime_error
#include <string>
using namespace std;

int main() {
    string choice, word, text;  // User input for choices and input
    auto menu = [] ( ) {
    	cout << "_______ Throw Primitive Types __________\n"
    	     << "    m - menu\n"
    	     << "    c - c_str\n"
    		 << "    i - integer\n"
    		 << "    f - float\n"
    		 << "    s - string\n"
    	     << "    u - undefined (double)\n"
    		 << "    q - Quit\n"; };
    menu();
    string s("Worse");
    int i=123;
    float f=1.23;
    double d=4.56;
    const char *c = "foo bar";
    
    bool stay = true;
	while(stay) {           // Main menu while starts
        cout << "    Enter your choice: ";
		cin >> choice;      // Take in user choice from menu
		cin.ignore();
		char ch = choice[0];

        try {
    		switch(ch) { // menu switch start
    		    case 'b': case 'B':  // break out of loop
    		        stay = false; break;
    		    
                case 'c': case 'C':  // c_str
                    throw("Bad"); break;
                
                case 'i': case 'I':  // integer
                    throw(123); break;
                
                case 'f': case 'F':  // float;
                    throw(f); break;
                
                case 's': case 'S': // string
                    throw(s); break;
                
                case 'm': case 'M': 
                    menu(); break;
                    
                case 'r': case 'R':
                    throw runtime_error("Catastrophe");
                    break;
                
                case 'u': case 'U':  // undefined (double)
                    throw(d); break;
                    
                case 'q': case 'Q': // quit
    				stay = false; break;
    				
    			default: // Invalid! Tells user to try again
    				cout << "\nInvalid command!\nTry again!\n\n";
            }
        } // end of try block

        catch ( runtime_error &e ) { cout << e.what () << '\n'; } 
        catch (int i) { cout << i << '\n'; } 
        catch (float f) { cout << f << '\n'; }
        catch (const char *e) { cout << e << '\n'; } 
        catch (string e) { cout << e << '\n'; } 
        catch (...) { cout << "some unknown exception.\n"; }
	} // end of while
    
    cout << "\nProgram exit!";
}