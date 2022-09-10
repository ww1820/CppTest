#include<bits/stdc++.h>

using namespace std;

class A
{
public:
    virtual void func() {
        printf("A\n");
    }
};

class B : public A
{
public:
    void func() override {
        printf("B\n");
    }
    void fun() {
        printf("Not virtual. ");
    }
};



int main() {
    A *a = new B();
    a->func();
    return 0;
}