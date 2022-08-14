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
        pos = vector<bool>(n, true);
        return backTracing(nums);
    }

private:
    int res = 0;
    unordered_map<vector<bool>, int> maxSumDict;
    vector<bool> pos; // 存储位置信息


    int backTracing(const vector<int>& nums) {
        // 剪枝
        if(maxSumDict.find(pos) != maxSumDict.end()) {
            return maxSumDict[pos];
        }
        
        if (accumulate(pos.begin(), pos.end(), 0) == 0)
        { // 终止条件
            return 0;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if(pos[i]) { // pos[i] 没还被戳破
                pos[i] = false;
                int nextLevel = backTracing(nums); // 下一层最大的分数
                maxSumDict.emplace(make_pair(pos, nextLevel));
                sum = max(sum, cal(nums, i) + nextLevel);
                pos[i] = true;
            }
        }

        return sum;
    }

    int cal(const vector<int>& nums, int k){
        int l = k - 1;
        int r = k + 1;
        
        while (l >= 0 && !pos[l])
            --l;
        
        while (r < nums.size() && !pos[r])
            ++r;

        l = (l == -1) ? 1 : nums[l];
        r = (r == nums.size()) ? 1 : nums[r];

        return (l * nums[k] * r);
    }
};
// @lc code=end

