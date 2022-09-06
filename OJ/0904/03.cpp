#include<bits/stdc++.h>
#include "/data/workspace/cpp_test/tool.h"

using namespace std;

/*
3
10 5 8
*/

int main() {
    int n, ans = INT32_MAX;
    infile >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        infile >> nums[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int maxn = max(nums[i], nums[i + 1]);
        int minn = min(nums[i], nums[i + 1]);

        int cnt = 0;

        

        if(maxn >= minn * 2) {
            cnt = maxn / 2 + maxn % 2;
        } else {
            cnt = (maxn + minn) / 3;
            if((maxn + minn) % 3 > 0) {
                ++cnt;
            }
        }
        ans = min(cnt, ans);
    }
    cout << ans << endl;
}