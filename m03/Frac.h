// Function Prototypes for Overloaded Stream Operators
// Forward declaration needs to be filled
// if multifiles are used, make sure to place the inclusion guard.
#include <iostream>
class Frac;

ostream &operator << (ostream &, const Frac &);
istream &operator >> (istream &, Frac &);
 
class Frac {
private:
    int num, den;
    long gcd(long a, long b)
    Frac lowterms(Frac &f);
public:
    Frac();
    Frac(string s);
    Frac(int num_, int den_);
    Frac(const Frac& rhs);
    Frac operator=(const Frac& rhs);
    
    // math + - * must be minimum term, i.e. no 2/8
    Frac operator + (Frac &rhs); 
    Frac operator - (Frac &rhs);
    Frac operator * (Frac &rhs);
    Frac operator / (Frac &rhs);
    
    // increment ++ decrement --
    Frac operator++();
    Frac operator++(int);
    Frac operator--();
    Frac operator--(int);
    
    // comparators
    bool operator == (Frac &f2);
    bool operator != (Frac &f2);
    bool operator < (Frac &f2);
    bool operator > (Frac &rhs);
    bool operator <= (Frac &f2);
    bool operator >= (Frac &f2);
    
    // overloading >> << stream operators
    friend istream& operator>>(istream& strm, Frac& f);
  	friend ostream& operator<<(ostream& strm,const Frac& f) {
};