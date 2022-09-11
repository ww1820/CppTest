#include <bits/stdc++.h>
using namespace std;


int main() {
    string str;
    cin >> str;
    int len = str.length();
    
    if(len < 2) return 0;
    
    int cnt = 0;
    
    stack<char> stk;
    
    for(int i = 0; i < len; ++i) {
        if(!stk.empty() && stk.top() == str[i]) {
            ++cnt;
            stk.pop();
            if (i+1< len && str[i] != str[i+1]) {
                stk.emplace(str[i]);
            }
        } else  {
            stk.emplace(str[i]);
        }
    }
    
    cout << cnt;
    
}
// 64 位输出请用 printf("%lld")