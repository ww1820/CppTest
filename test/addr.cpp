#include<bits/stdc++.h>

using namespace std;

class A {
public:
    virtual void fun() {
        cout << "A" << endl;
    }

    virtual ~A() {
        cout << "~A" << endl;
    }
};

class B : public A {
public:
    void fun() {
        cout << "B" << endl;
    }

     ~B() {
        cout << "~B" << endl;
    }
};

int main() {
    A *a = new B();
    a->fun();
    delete a;
    a = nullptr;
    return 0;
}