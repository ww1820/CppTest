#include<bits/stdc++.h>
using namespace std;

ifstream infile("/data/workspace/cpp_test/test.txt", ios::in); 

/*
1500
4
300 2
600 1
1000 0
1200 0
*/

int main() {
    int n, d;
    infile >> d >> n;
    
    vector<int> dp(n + 1, INT_MAX);
    vector<int> distance(n + 2);
    vector<int> time(n);

    for (int i = 1; i <= n; i++)
    {
        infile >> distance[i] >> time[i];
        time[i]++; // 充电
    }

    distance[n + 1] = d;
    dp[0] = 0;

    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (distance[i] - distance[j] > 1000)// 不能到达
                break;
            dp[i] = min(dp[i], dp[j]); // 
        }
        if (dp[i] == INT_MAX)
        {
            cout << -1 << endl;
            return 0;
        }
        dp[i] += time[i];
    }
    int res = d / 100;
    cout << dp[n + 1] + res << endl;
    return 0;
}