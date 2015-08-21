#include <iostream>

using namespace std;


class A
{
public:
    virtual void func1() { cout << "A::func1" << endl; };
    virtual void func2() { cout << "A::func2" << endl; };
};

class B : public A
{
public:
    virtual void func1() { cout << "B::func1" << endl; };
    virtual void func2() { cout << "B::func2" << endl; };
};


int main()
{

    cout << "DownCast Test" << endl;

    A* pA = new A;
    pA->func1();
    pA->func2();

    B* pB = new B;
    pB->func1();
    pB->func2();

    // testing undefined behavior
    B* badB = (B*) pA;
    badB->func1();

    return 0;
}

