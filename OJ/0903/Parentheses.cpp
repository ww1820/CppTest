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

    int l = 0;
    int weight = 0;
    for (int k = 0; k < input.length(); ++k)
    {
        if(input[k] == '(') {
            ++l;
        } else if(l > 0){
            --l;
            weight += 2;
        }
        L[k] = weight;
    }

    // printVec(L);
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n;i++) {
        for (int j = i+1; j < n;j++) {
            if (input[j] == ')') {
                dp[i][j] = L[j] - L[i];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
            ans += dp[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}