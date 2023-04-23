# include<bits/stdc++.h>

using namespace std;

int main() {

    freopen("../test.in", "r", stdin);

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        if(s.length() != 5) {
            cout << "No" << endl;
        } else {
            unordered_set<char> tmp{'B', 'a', 'i', 'd', 'u'};
            bool flag = true;
            for (auto c : s)
            {
                if(tmp.find(c) != tmp.end()) {
                    tmp.erase(c);
                } else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}