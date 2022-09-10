#include<bits/stdc++.h>

using namespace std;

class Base
{
private:
    /* data */
    int data_; // private 在派生类中不可见
// public protected 在派生类中可见，访问权限由继承权限控制
public:
    int data; 
protected:
    int pro;
};

class A : private Base {
    int get() {
        return Base::pro + Base::data;
    }
};

class B : protected Base {
    int get() {
        return Base::pro + Base::data;
    }
};

class C : public Base {
    int get() {
        return Base::pro + Base::data;
    }
};

int main() {
    printf("Hello World!\n");
    return 0;
}