#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<long>   stdCodeVec = { 199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L };
const vector<string> stdNameVec = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };

void doNothing(int&)
{
}

int main() {
    int x = {__cplusplus};
    cout << "C++ version: " << x << endl;

    auto it = std::find(stdCodeVec.begin(), stdCodeVec.end(), x);
    if (it != stdCodeVec.end()) {
        int index = std::distance(stdCodeVec.begin(), it);
        cout << stdNameVec[index] << endl;
    }

    // Modern initialization forms (preferred):
    // added in C++11
    int d {7};   // direct-list-initialization (initial value in braces)
    int e {};      // value-initialization (empty braces)

    cout << "d: " << d << endl;
    cout << "e: " << e << endl;

    int xx; // this variable is uninitialized
    doNothing(xx); // make the compiler think we're assigning a value to this variable
    // print the value of x to the screen (who knows what we'll get, because x is uninitialized)
    std::cout << xx << '\n';

    std::cout << EXIT_SUCCESS << '\n';
    std::cout << EXIT_FAILURE << '\n';

    return 0;
}