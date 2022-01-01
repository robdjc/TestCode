#include <iostream>

using namespace std;

// testing only
// example for using and debugging thru recursion
int Raise (int num, int power)
{
    cout << "Raise called: " << num << "  " << power << endl;
    if(power == 0)
    {
        return 1;
    }
    else
    {
        int ans = Raise(num, power - 1);
        int ret_ans = num * ans;
        cout << "Raise calculation num=" << num 
             << ", power=" << power 
             << ", ans=" << ans
             << ", ret_ans " << ret_ans << endl;
        return ret_ans;
    }
}


int main()
{

    int answer = Raise(5, 10);
    cout << answer << endl;

    answer = Raise(2, 0);
    cout << answer << endl;

    answer = Raise(2, 6);
    cout << answer << endl;

    return 0;
}

