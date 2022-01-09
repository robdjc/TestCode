#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void th1_print(int n, const string &s)  {
    for(auto i = 0; i < n; ++i) {
        cout << "th1_print thread " << s << ", " << i << endl;

        if(i%2) {
            cout << "th1_print thread - sleeping" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
} 

void th2_print(int n, const string &s)  {
    for(auto i = 0; i < n; ++i) {
        cout << "th2_print thread " << s << ", " << i << endl;  

        if(i%2) {
            cout << "th2_print thread - sleeping" << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
} 

int main()
{
    cout << "main thread - start" << endl;  
    thread th1(th1_print, 10, "th1");
    thread th2(th2_print, 20, "th2");

    cout << "main thread - before join" << endl;  
    th1.join();
    th2.join();
    cout << "main thread - after join" << endl;  
    
    return 0;
}
