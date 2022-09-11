#include<bits/stdc++.h>
using namespace std;

ifstream infile("/data/workspace/cpp_test/test.txt", ios::in); 

/*
8
-2 2 5 7 7 8 10 19

3
1 3 4

5
-1 1 2 5 7

5
1 6 2 9 14
*/

int main() {
    int n;
    infile >> n;
    
    vector<int> vec;
    vector<int> diff;
    int a;
    int idx = 0;
    while (n--)
    {
        infile >> a;
        if(!vec.empty()) {
            diff.emplace_back(abs(vec.back()-a));
            if(diff.back() > diff[idx]) {
                idx = diff.size() - 1; // 更新最大值下标
            }
        }
        vec.emplace_back(a);

    }

    if(idx == 0 || idx == diff.size() - 1) {
        diff[idx] = 0;
    } else {
        // 修改idx 
        int modify1 = ceil((vec[idx-1] + vec[idx+1]) / 2);
        int gap1 = max(abs(vec[idx - 1] - modify1), abs(vec[idx + 1] - modify1));
        // 或 修改 idx + 1
        int modify2 = ceil((vec[idx] + vec[idx+2]) / 2);
        int gap2 = max(abs(vec[idx] - modify2), abs(vec[idx + 2] - modify2));

        if(gap1 < gap2) {
            diff[idx - 1] = abs(vec[idx - 1] - modify1);
            diff[idx] = abs(vec[idx + 1] - modify1);
        }
        else
        {
            diff[idx] = abs(vec[idx] - modify2);
            diff[idx+1] = abs(vec[idx+2] - modify2);
        }
    }

    sort(diff.begin(), diff.end());
    cout << diff.back() << endl;
    return 0;
}