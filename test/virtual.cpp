#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"
using namespace std;

class Base {
public:
    Base() = default;
    Base(int a) : a_(a){};
    int a_ = 1;
    virtual void func()
    {
        printf("Base. \n");
    }
};

class Derived : public Base {
public:
    Derived() = default;
    Derived(int b) : b_(b) {}
    int b_ = 2;
    virtual void func()
    {
        printf("Derived. \n");
    }
};

int main() {
    Base *ptr1 = new Derived(10);
    Base *ptr2 = new Derived(11);
    memory_dump(ptr1, 16);
    memory_dump(ptr2, 16);
    return 0;
}