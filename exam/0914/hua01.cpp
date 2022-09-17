# include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("../test.in", "r", stdin);
    int M, N, K;
    cin >> M >> N >> K;

    vector<bool> flag(N + 2, true);

    // unordered_set<int> st;
    while (K--)
    {
        int idx;
        cin >> idx;
        flag[idx] = false;
        // st.insert(idx);
    }

    vector<vector<int>> dp(N + 2, vector<int>(M + 1, 0));

    dp[0][M] = 1;
    for (int i = 1; i < N + 2; ++i) {
        for (int j = 1; j < M + 1; ++j) {
            if(i >= 1) {
                // if(st.find(i-1) == st.end()) {
                if(flag[i-1]) {
                    dp[i][j] += dp[i - 1][j];
                } else {
                    if(j > 1) {
                        dp[i][j - 1] += dp[i - 1][j];
                    }
                }
            }

            if(i >= 2) {
                if(flag[i-2]) {
                // if(st.find(i-2) == st.end()) {
                    dp[i][j] += dp[i - 2][j];
                } else {
                    if(j > 1) {
                        dp[i][j - 1] += dp[i - 2][j];
                    }
                }
            }

            if(i >= 3) {
                if(flag[i-3]) {
                // if(st.find(i-3) == st.end()) {
                    dp[i][j] += dp[i - 3][j];
                } else {
                    if(j > 1) {
                        dp[i][j - 1] += dp[i - 3][j];
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i < M + 1; ++i) {
        res += dp[N + 1][i];
    }
    printf("%d\n", res);
    return 0;
}