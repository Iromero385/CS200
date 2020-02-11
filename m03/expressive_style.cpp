// lengthy statements tend to fractured the local meaning
// Loops are problematic
// higher order functions, i.e pass function as an argument
// transform  => map
// copy_if    => filter
// accumulate => reduce
#include <iostream>
using namespace std;

enum TrafficLight { Red=0, Green, Yellow, Amber };
enum State { Go, Stopped, GetReady };

int main() {
    auto SunnySide = "down";
    auto Color = "Green";
    if(SunnySide == "up") 
        Color = "Yellow";
    else
        Color = "White";
    
    // solution and problem...
    // const auto Color : 
        (SunnySide == "up") 
            ? "Yellow"
            : "White";
            
    // Solution - use switch return
    auto TrafficLight = Amber;
    const auto State = [TrafficLight] {
        switch (TrafficLight) {
            case Red:
                return Stopped;
            case Yellow:
                return GetReady;
            case Green:
                return Go;
        }
    } ();
}