#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    vector<const char*> vec {"this","is","as","easy", "as", "123"};
    for(auto x:vec) cout << x << " "; cout << endl ;
    auto cstr_compare = [](const char* s1, const char* s2) {
        return strcmp(s1,s2) < 0; }; // define a Lambda, function object
    sort(vec.begin(), vec.end(), cstr_compare);
    for(auto x:vec) cout << x << " "; cout << endl;
}
