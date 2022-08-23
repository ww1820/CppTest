/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();

        val.resize(n+2);
        val[0] = 1;
        val[n+1] = 1;

        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i - 1];
        }

        rec.resize(n + 2, vector<int>(n + 2, -1));

        return dfs(0, n + 1);
    }

private:
    vector<vector<int>> rec;
    vector<int> val;


    int dfs(int left, int right) {
        if(left >= right - 1) {
            return 0;
        }
        if(rec[left][right] != -1) {
            return rec[left][right];
        }

        for (int i = left + 1; i < right; ++i) {
            int sum = val[left] * val[i] * val[right];
            sum += dfs(left, i) + dfs(i, right);
            rec[left][right] = max(rec[left][right], sum);
        }

        return rec[left][right];
    }
};
// @lc code=end

