#include<bits/stdc++.h>

using namespace std;

bool fun(int n) {
    unordered_set<int> st;
    for (int i = 1; i * i < n; ++i) {
        if(st.find(n - i * i) != st.end()){
            return true;
        }
        st.emplace(i * i);
    }
    return false;

}

int main() {
    int n;
    while (cin >> n)
    {
        if(fun(n)){
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}