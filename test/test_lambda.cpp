#include<bits/stdc++.h>

using namespace std;

int main() {
    int a_ = 10;

    // auto f = [&a = a_] () mutable // 引用传递, 别名为a
    // auto f = [a = a_] () mutable  // 以值传递, 别名为a
    auto f = [a = a_] () mutable 
    {
        printf("a = %d\n", a);
        ++a;
        printf("a = %d\n", a);
    };
    f();
    printf("a_ = %d\n", a_);
    return 0;
}