#include <iostream>

using namespace std;


class A
{
public:
    virtual void func1() { cout << "A::func1\n"; };
    virtual void func2() { cout << "A::func2\n"; };

    void test_override() { cout << "A::test_override\n"; };
};

class B : public A
{
public:
    virtual void func1() { cout << "B::func1\n"; };
    virtual void func2() { cout << "B::func2\n"; };

    void test_override() { cout << "B::test_override\n"; };
};


void some_func(A * obj)
{
    obj->func1();
    obj->func2();
    obj->test_override();
}

int main()
{

    cout << "DownCast Test\n";

    A* pA = new A;
    pA->func1();
    pA->func2();

    B* pB = new B;
    pB->func1();
    pB->func2();


    // testing undefined behavior
    // gcc/linux this calls A::func1, but there are no guarantees
    B* badB = (B*) pA;

    cout << "\n\nCall with a bad B pointer\n";
    badB->func1();

    B* goodB = dynamic_cast<B*>(pA);
    if(goodB)
    {
        cout << "dynamic_cast succeeded\n";
    }
    else
    {
        cout << "dynamic_cast failed\n";
    }

    cout << "\n\nTest override\n";

    B myB;
    A* ptrA = &myB;

    some_func(ptrA);

    return 0;
}

