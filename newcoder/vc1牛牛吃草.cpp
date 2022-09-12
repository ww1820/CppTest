#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> W(n);
    vector<int> A(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> W[i];
    }
    
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    vector<int> dp(n);
    dp[n-1] = W[n-1];
    
    int res = dp[n-1];
    for(int i = n - 2; i >= 0; --i) {
        int maxn = 0;
        for(int j = i + A[i]; j < n; j += A[i]) {
            maxn = max(maxn, dp[j]);
        }
        dp[i] = W[i] + maxn;
        res = max(dp[i], res);
    }
    
    cout << res;
    return 0;
}
// 64 位输出请用 printf("%lld")