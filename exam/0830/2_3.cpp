#include<bits/stdc++.h>
using namespace std;

/*
输入：
7
rgbrgbg
1 2
2 3
3 4
4 5
5 6
6 7
输出：
1
*/

ifstream infile("/data/workspace/cpp_test/test.txt", ios::in); 

int main() {
    int n;
    infile >> n;
    
    vector<int> vec;

    int a;

    while (n--)
    {
        infile >> a;
        vec.emplace_back(a);
    }

    int res = INT_MIN;

    for (int i = 1; i < vec.size() - 1; ++i) {
        // 不修改
        int gap1 = max(abs(vec[i] - vec[i - 1]), abs(vec[i] - vec[i + 1]));
        // 修改
        int gap2 = (abs(vec[i - 1] - vec[i + 1]) + 0.5) / 2;

        res = max(min(gap1, gap2),res);
    }

    cout << res << endl;

    return 0;
}