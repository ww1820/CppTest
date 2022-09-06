#include <bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"
using namespace std;

// ifstream infile("/data/workspace/cpp_test/tool.h", ios::in);

int main() {
    string input;
    infile >> input;
    int n = input.length();
    if(n == 0) {
        cout << 0;
        return 0;
    }
    vector<int> L(input.size(), 0);
    vector<int> R(input.size(), 0);
    if(input[0] == '(') {
        ++L[0];
    } else {
        ++R[0];
    }
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            L[i] = L[i - 1] + 1;
            R[i] = R[i - 1];
        } else {
            L[i] = L[i - 1];
            R[i] = R[i - 1] + 1;
        }
    }
    // printVec(L);
    // printVec(R);
    printf("\n");
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n;i++) {
        for (int j = 2; j <= n - i;j++) {
            string s = input.substr(i, j);
            int l = 0, weight = 0;
            for (int k = 0; k < s.length(); ++k) {
                if(s[k] == '(') {
                    ++l;
                } else if(l > 0){
                    --l;
                    weight += 2;
                }
            }
            ans += weight;
        }
    }
    cout << ans << endl;

    return 0;
}