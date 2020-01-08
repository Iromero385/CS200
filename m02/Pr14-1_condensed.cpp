// This program demonstrates a static member variable.
#include <iostream>
using namespace std;

class Tree {
   static int objectCount;    // Static member variable.
public:
   Tree() { objectCount++; }
   int getObjectCount() const { return objectCount; }
};

// Initialize the static member variable
// Must be after the class declaration, before application start.
int Tree::objectCount = 0;

int main() {
   Tree oak, elm, pine;

   cout << "We have " << pine.getObjectCount()
        << " trees in our program!\n";
}