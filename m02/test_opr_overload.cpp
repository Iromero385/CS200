#include<iostream>

using namespace std;

class Test;
ostream &operator << (ostream &, const Test &);

class Test {
    int item = 3;
public:
    Test(int i) { item=i; }
    // addition
    // b + c  is to return b.add(c)
    // no change to both the original value of b and c 
    Test add(Test const & right) 
        { Test temp; temp.item = item + right.item; return temp; }
    
    // increment
    // pre is operation before return
    Test pre_inc() { item += 1; return *this; }
    // post is operation after return
    Test post_inc() { return *this; item += 1; }
    
    // greater than
    bool greater(Test const &right) { return (item > right.item); }
    
    friend ostream &operator << (ostream &strm, const Test &right) 
        { strm << right.item; return strm; }
};

int main() {
    Test a(3), b(4);
    std::cout << a.post_inc() << " ";
    std::cout << a.pre_inc();
}