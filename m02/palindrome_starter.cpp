//  Lab 2 Palindrome Detector
#include <iostream>
#include <string>
using namespace std;

// Function prototype
bool isPalindrome(string);

int main()
{
	const int SIZE = 6;

    // Create an array of strings to test.
    string testStrings[SIZE] = 
	        { "ABLE WAS I ERE I SAW ELBA",
              "FOUR SCORE AND SEVEN YEARS AGO",
              "NOW IS THE TIME FOR ALL GOOD MEN",
              "DESSERTS I STRESSED",
              "AKS NOT WHAT YOUR COUNTRY CAN DO FOR YOU",
              "KAYAK" };
   
   // Test the strings.
   for (int i = 0; i < SIZE; i++)
   {
      cout << "\"" << testStrings[i] << "\"";
	  if (isPalindrome(testStrings[i]))
		  cout << " is a palindrome.\n";
	  else
		  cout << " is NOT a palindrome.\n";
   }
 
	return 0;
}