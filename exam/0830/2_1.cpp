#include<bits/stdc++.h>
using namespace std;

ifstream infile("/data/workspace/cpp_test/test.txt", ios::in); 

int main() {
    int q;
    infile >> q;
    while (q--)
    {
        string str;
        infile >> str;
        bool flag = false;
        for (int i = str.length() - 1; i >= 0; --i)
        {
            if(((str[i]-'0') & 1) == 0) {
                swap(str[i], str[str.length() - 1]);
                flag = true;
                break;
            }
        }
        if(flag)
            cout << str << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}