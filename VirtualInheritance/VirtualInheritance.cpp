#include <iostream>

using namespace std;

class A
{
public:
    virtual string GetName() {return "A"; }
};

class B : public virtual A {
public:
    string GetName() { return "B"; }
};

class C : public virtual A {
public:
    string GetName() { return "C"; }
};

class D : public B, public C {
public:
    string GetName() { return "D"; }
};


void PrintName(A& a) {
    cout << a.GetName() << endl;
}

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;

    A a;
    B b;
    C c;
    D d;

    PrintName(a);
    PrintName(b);
    PrintName(c);
    PrintName(d);
   
    return 0;
}
