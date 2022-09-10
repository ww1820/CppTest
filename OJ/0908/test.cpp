#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"

using namespace std;

int main() {
    vector<int> dp(12, 0);
    dp[0] = 1;
    for (int i = 1; i <= 11; ++i)
    {
        dp[i] = accumulate(dp.begin(), dp.begin() + i, 0);
    }
    cout << dp[11];
}