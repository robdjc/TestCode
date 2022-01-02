#include <iostream>
#include <algorithm>

using namespace std;

// testing only
// example for using and debugging thru recursion
int IsPalindrome (string s)
{
    s.erase (std::remove (s.begin(), s.end(), ' '), s.end()); 

    cout << "IsPalindrome called: " << s << endl;
    if(s.length() <= 1)
    {
        return true;
    }
    else
    {
        bool b_test1 = s[0] == s[s.length()-1] && IsPalindrome(s.substr(1, s.length()-2));
        return b_test1;
    }
}


int main()
{
    bool answer = IsPalindrome("");
    cout << answer << endl;

    answer = IsPalindrome("aa");
    cout << answer << endl;

    answer = IsPalindrome("ab");
    cout << answer << endl;

    answer = IsPalindrome("aba");
    cout << answer << endl;

    answer = IsPalindrome("was it a car or a cat i saw");
    cout << answer << endl;

    answer = IsPalindrome("abc123aaa320cba");
    cout << answer << endl;

    return 0;
}

