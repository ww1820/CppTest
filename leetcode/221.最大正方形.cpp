/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        int res = 0;
        // 初始化dp数组
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            res = max(res, dp[i][0]);
        }

        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            res = max(res, dp[0][j]);
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
                res = max(res, dp[i][j] * dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

