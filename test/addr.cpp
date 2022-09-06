#include<bits/stdc++.h>

using namespace std;

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    cout << (char*)(a+1) - (char*)(a) << endl;
}