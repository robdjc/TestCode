#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

// lambdas
// anonymous functions
// usually small function without a formal function definition
// can be used anywhere a function pointer or functor was used
// [capture](parameters){code;}
// capture can bring in variable from the current scope
//   into the lambdas code

class MyFunctor
{
   public:
     void operator()(int x) { std::cout << x << std::endl; }
};

int main()
{
    std::vector<int> v {5, 1, 2, 3, 4};

    // using a functor
    std::cout << "Functor" << std::endl;
    std::for_each(v.begin(), v.end(), MyFunctor());

    // using a lambda
    std::cout << "Lambda" << std::endl;
    std::for_each(v.begin(), v.end(), 
        [](int x){ std::cout << x << std::endl; });

    // lambda with capture
    std::cout << "Lambda with capture" << std::endl;
    int myval = 100;
    std::for_each(v.begin(), v.end(), 
        [myval](int x){ std::cout << (x + myval) << std::endl; });

    // basic lambda passed to std find_if
    auto it = std::find_if(v.begin(), v.end(), 
        [](int value){return value > 2 && value < 5;} );
    
    if(it != v.end()) {
        std::cout << "Found: " << (*it) << std::endl;
    }
    else {
        std::cout << "Not found!" << std::endl;
    }

    return 0;
}
