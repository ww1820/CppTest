#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k = 4;
    // cin >> n >> k;
    string input = "())())())(()";
    n = input.length();
    // cin >> input;

    vector<int> left_count_record(input.size(), 0);
    int left_count = 0;
    for (int i = 0; i < input.size(); i++) {
        left_count_record[i] = left_count;
        if (input[i] == '(') {
            left_count++;
        }
    }

    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n;i++) {
        for (int j = i+1; j < n;j++) {
            if (input[j] == ')') {
                dp[i][j] = dp[i][j - 1] + left_count_record[j] - left_count_record[i];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
            
            if (dp[i][j] >= k) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}