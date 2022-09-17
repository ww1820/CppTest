#include<bits/stdc++.h>

using namespace std;

void my_reserve(string &str, int i) {
    if(!(str[i] ^ '1')) {
        str[i] = '0';
    } else if(!(str[i] ^ '0')){
        str[i] = '1';
    }
}

bool canReserve(string s1, string s2) {
    for (int i = 0; i < s1.length()-1; ++i) {
        if(s1[i] != s2[i]) {
            my_reserve(s1, i);
            my_reserve(s1, i + 1);
        }
    }

    return (s1 == s2);
}

int main() {
    freopen("../test.in", "r", stdin);

    int n;

    cin >> n;

    string str;
    

    while (n--)
    {
        cin >> str;
        string A(str.length(), '0');
        string B(str.length(), '1');
        if (canReserve(str, A) || canReserve(str, B))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}