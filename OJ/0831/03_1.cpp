#include <bits/stdc++.h>
using namespace std;

ifstream infile("/data/workspace/cpp_test/test.txt", ios::in);

const int inf = INT_MAX;
int n, d;
// int dp[10005];
vector<int> dp(10005, INT_MAX);
int dis[10005], tim[10005];
int main()
{
    // cout << "INT_MAX = " << hex << inf/2 << endl;
    infile >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        infile >> dis[i] >> tim[i];
        tim[i]++;
    }
    dis[n + 1] = d;
    // memset(dp, inf, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dis[i] - dis[j] > 1000)
                break;
            dp[i] = min(dp[i], dp[j]);
        }
        if (dp[i] == INT_MAX)
        {
            cout << -1 << endl;
            return 0;
        }
        dp[i] += tim[i];
    }
    int res = d / 100;
    cout << dec << dp[n + 1] + res << endl;
    return 0;
}