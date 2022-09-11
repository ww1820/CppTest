#include<bits/stdc++.h>

using namespace std;

int func(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int m = sum / 2;
    vector<int> dp(m + 1);
    dp[0] = true;
    for (int weight : stones) {
        for (int j = m; j >= weight; --j) {
            dp[j] = dp[j] || dp[j - weight];
        }
    }
    for (int j = m;; --j) {
        if (dp[j]) {
            return sum - j;
        }
    }
}

int main() {
    vector<int> stones = {17, 8, 11};
    cout << func(stones) << endl;
    return 0;
}