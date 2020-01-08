#include<iostream>
using namespace std;

int main(){
    int i(1);
    cout << "This sequence is in one statement:   "
         << i << " " 
         << i-- << " "  
         << i << " "
         << i++ << " " 
         << i-- << " " 
         << i++ 
         << "\nThe one below is break into 6 steps: ";
    cout << i << " " ; 
    cout << i-- << " " ; 
    cout << i << " " ;
    cout << i++ << " " ; 
    cout << i-- << " " ;
    cout << i++ ;
}