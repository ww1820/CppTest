/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start

#include <bits/stdc++.h>

using namespace std;

#define BIT_MAX 32

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = nums.size();
        int res = 0;

        for (int bit = 0; bit < BIT_MAX; ++bit) {
            int x = 0;
            int y = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if(nums[i] & (1 << bit)) { // 统计数组中该位是 1 的个数
                    ++x;
                }

                if((i >= 1 && (i & (1 << bit)))) {
                    ++y;
                }
            }

            if(x > y) {
                res |= 1 << bit;
            }
        }

        return res;
    }
};
// @lc code=end

