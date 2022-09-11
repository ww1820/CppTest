#include<bits/stdc++.h>

using namespace std;

fstream infile("/data/workspace/cpp_test/test.txt", ios::in);

vector<int> nums;
// vector<int> path;
// vector<vector<int>> res;
int res = 0;
const int MOD = 1e9+7;

// bool isvaild(const vector<int>& path) {
//     if(path.size() < 0) {
//         return false;
//     }
// }

void backtracing(vector<bool>& used, int odd, int even, int startIdx) {
    if((odd >= 2 && even == 0) || (even >= 2 && odd == 0)) {
        // res.push_back(path);
        ++res;
    }
    
    for(int i = startIdx; i < nums.size(); ++i) {
        // if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
        //     continue;
        // }
        if(used[i] == false) {
            used[i] = true;
            // path.emplace_back(nums[i]);
            int oldodd = odd;
            int oldeven = even;
            if((nums[i] & 1) == 0) {
                ++even;
            } else {
                ++odd;
            }
            backtracing(used, odd, even, i + 1);
            odd = oldodd;
            even = oldeven;
            // path.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    infile >> n;
    
    nums.resize(n);
    
    for(int i = 0; i < n; ++i) {
        infile >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    vector<bool> used(n,false);
    int sum = 0;
    backtracing(used, 0, 0, 0);
    cout << res;
    
}