#include<bits/stdc++.h>

using namespace std;


class A{
public:
    void func() {
        funm();
    }
protected: 
    virtual void funm() {
        cout << "A" << endl;
    }

};

class B : public A{
public:
    void func() {
        A::funm();
    }
protected: 
    virtual void funm() {
        cout << "B" << endl;
    }
};

int main() {
    B b;
    A *a = &b;
    a->func();
    b.func();
    return 0;
}