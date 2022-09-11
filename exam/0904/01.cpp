#include<bits/stdc++.h>

using namespace std;

void f2(string &s) {
    try
    {
        if(s.length() < 10) {
            s += "!!";
            throw -1;
        }
    }
    catch(int)
    {
        cout << "*";
    }
}

int f(string &s) {
    try
    {
        f2(s);
        throw string("*");
    }
    catch(string s)
    {
        cout << "&";
    }
    cout << "#";
}

int main() {
    string i;
    cin >> i;
    try
    {
        f(i);
        throw string("@");
    }
    catch(string s)
    {
        cout << s << endl;
    }
    return 0;
}